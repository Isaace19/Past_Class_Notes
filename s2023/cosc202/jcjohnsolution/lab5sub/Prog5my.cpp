/*
Name: Isaac Abella
Description: PPM file manipulator - source code implementation
*/

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

#include "Support.h"
// create PPM class constructor
ppm::ppm()
{
    magicid = "P6";
    block_size = 512;
    Nrow = 0;
    Ncol = 0;
    maxvalue = 255;
    img = NULL;
}

// copy of the class constructor to put data into to compare
ppm::ppm(const ppm &clone)
{
    magicid = clone.magicid;
    block_size = clone.block_size;
    Nrow = clone.Nrow;
    Ncol = clone.Ncol;
    maxvalue = clone.maxvalue;
    // copy rgb values over
    img = new RGB[Nrow * Ncol];
    for (int i = 0; i < Nrow * Ncol; ++i)
    {
        img[i] = clone.img[i];
    }
}

// deconstructor
ppm::~ppm()
{
    delete[] img;
    img = NULL;
}

// allow 2D access to the underlying 1D image data.
RGB *ppm::operator[](int rowIndex)
{
    return img + rowIndex * Ncol;
}

// sets the byte size of the parser.
void ppm::set_bs(int bytes)
{
    block_size = bytes;
}

int ppm::get_Nrow()
{
    return Nrow;
}

int ppm::get_Ncol()
{
    return Ncol;
}

void ppm::read(const string &imgfile)
{
    ifstream myfile(imgfile, ios::binary);

    if (!myfile)
    {
        cerr << "ppm::read: cannot open " << imgfile << '\n';
        exit(1);
    }

    // parse the header, maxvalue, and the rgb data values

    string verifyHeader;
    int verifyWidth, verifyHeight, verifyMax;

    myfile >> verifyHeader >> verifyWidth >> verifyHeight >> verifyMax;

    if (verifyHeader != magicid)
    {
        cerr << "ppm::read: magicid " << verifyHeader << " not supported\n";
        exit(1);
    }
    if (verifyMax != maxvalue)
    {
        cerr << "ppm::read: maxvalue " << verifyMax << " not supported\n";
        exit(1);
    }
    myfile.ignore(1, '\n');

    // delete in case something was already in the img
    delete[] img;
    Nrow = verifyWidth;
    Ncol = verifyHeight;
    img = new RGB[Nrow * Ncol];

    // read binary into the img array directly
    char *parse = static_cast<char *>(static_cast<void *>(img));

    while (myfile)
    {
        myfile.read(parse, block_size);
        parse += block_size;
    }

    if (static_cast<long unsigned int>(parse - (char *)img) != verifyWidth * verifyHeight * sizeof(RGB))
    {
        cerr << "ppm::read: expected " << verifyWidth * verifyHeight * sizeof(RGB) << " but read " << (parse - (char *)img) << " bytes\n";
        exit(1);
    }

    // not necessary
    myfile.close();
}

void ppm::write(const string &imgfileout)
{
    // write to new ppm file

    string outputfile = imgfileout.substr(0, imgfileout.rfind('.')); // find the . in the string here we can append the mod to it
    outputfile += "_mod.ppm";

    ofstream writefile(outputfile, ios::binary);

    if (!writefile.is_open())
    {
        std::cerr << "Error opening file (ppm::write)";
        return;
    }

    // insert header first, than write the image array by byte.

    writefile << "P6" << '\n'
              << Ncol << ' ' << Nrow << '\n'
              << maxvalue << '\n';

    int dimension = Nrow * Ncol * sizeof(RGB);

    char *parse = static_cast<char *>(static_cast<void *>(img));
    while (dimension > block_size)
    {
        writefile.write(parse, block_size);

        // for every bit parsed we get rid of dimensions.
        parse += block_size;
        dimension -= block_size;
    }
    writefile.write(parse, dimension);

    writefile.close();
}

void gray(ppm &img)
{
    // implement the get_Nrow/Col to work with img values
    int numRows = img.get_Nrow();
    int numCols = img.get_Ncol();

    // manipulate the colors to grayscale.
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            unsigned char Y = static_cast<unsigned char>(img[i][j].R + img[i][j].G + img[i][j].B / 3);
            img[i][j].R = Y;
            img[i][j].G = Y;
            img[i][j].B = Y;
        }
    }
}

void flip(ppm &img)
{
    int numRows = img.get_Nrow();
    int numCols = img.get_Ncol();

    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols / 2; ++j)
        {
            RGB temp = img[i][j];
            img[i][j] = img[i][numCols - 1 - j];
            img[i][numCols - 1 - j] = temp;
        }
    }
}

void lens(ppm &img, float rho)
{
    // get the row and col data
    float numRows = img.get_Nrow();
    float numCols = img.get_Ncol();
    // make a copy of the img.
    ppm copy = img;

    // get the radius of the row and columb by dividing by 2
    float ci = numRows / 2;
    float cj = numCols / 2;
    float rmax = min(numRows / 2, numCols / 2);

    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            // (di,dj) = (i-ci, j-cj)
            float di = i - ci;
            float dj = j - cj;

            float r = sqrt((di * di) + (dj * dj));

            if (r < rmax)
            {
                float z = sqrt((rmax * rmax) - (r * r));
                float dzi = di / sqrt((di * di) + (z * z));
                float dzj = dj / sqrt((dj * dj) + (z * z));

                float bi = (1.0 - 1 / rho) * (asin(dzi));
                float bj = (1.0 - 1 / rho) * (asin(dzj));

                int ip = ((int)(i - z * tan(bi) + 0.5));
                int jp = ((int)(j - z * tan(bj) + 0.5));
                img[i][j] = copy[ip][jp];
            }
        }
    }
}