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

// create PPM class constructor
#include "Support.h"

ppm::ppm() : magicid("P6"), block_size(512), Nrow(0), Ncol(0), maxvalue(255), img(NULL)
{
}

ppm::ppm(const ppm &clone) : magicid(clone.magicid), block_size(clone.block_size), Nrow(clone.Nrow), Ncol(clone.Ncol), maxvalue(clone.maxvalue)
{
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

    string magicHeader;
    int magicWidth, magicHeight, magicMax;

    myfile >> magicHeader >> magicWidth >> magicHeight >> magicMax;

    if (magicHeader != magicid)
    {
        cerr << "ppm::read: magicid " << magicHeader << " not supported\n";
        exit(1);
    }
    if (magicMax != maxvalue)
    {
        cerr << "ppm::read: maxvalue " << magicMax << " not supported\n";
        exit(1);
    }
    myfile.ignore(1, '\n');

    // delete in case something was already in the img
    Nrow = magicHeight;
    Ncol = magicWidth;
    img = new RGB[magicHeight * magicWidth];

    char *parse = static_cast<char *>(static_cast<void *>(img));

    while (myfile)
    {
        myfile.read(parse, block_size);
        parse += myfile.gcount();
    }

    if (static_cast<long unsigned int>(parse - (char *)img) != magicWidth * magicHeight * sizeof(RGB))
    {
        cerr << "ppm::read: expected " << magicWidth * magicHeight * sizeof(RGB) << " but read " << (parse - (char *)img) << " bytes\n";
        exit(1);
    }

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
    // Write the PPM header
    writefile << magicid << '\n'
              << Ncol << ' ' << Nrow << '\n'
              << maxvalue << '\n';

    writefile.write(reinterpret_cast<const char *>(img), Nrow * Ncol * sizeof(RGB));

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
            unsigned char Y = static_cast<unsigned char>((img[i][j].R + img[i][j].G + img[i][j].B) / 3);
            img[i][j].R = Y;
            img[i][j].G = Y;
            img[i][j].B = Y;
        }
    }
}

void flip(ppm &img)
{
    // flip function
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
    // interpret pseudocode given in the lab writeup
    int numRows = img.get_Nrow();
    int numCols = img.get_Ncol();

    float ci = numRows / 2;
    float cj = numCols / 2;
    float rmax = min(cj, ci);
    ppm copy = img;

    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            float di = i - ci;
            float dj = j - cj;
            float r = sqrt(di * di + dj * dj);
            if (r < rmax)
            {
                float z = sqrt(rmax * rmax - r * r);
                float dzi = di / sqrt(di * di + z * z);
                float dzj = dj / sqrt(dj * dj + z * z);
                float bi = (1.0 - 1 / rho) * asin(dzi);
                float bj = (1.0 - 1 / rho) * asin(dzj);
                int ip = (int)(i - z * tan(bi) + .5);
                int jp = (int)(j - z * tan(bj) + .5);
                img[i][j] = copy[ip][jp];
            }
        }
    }
}