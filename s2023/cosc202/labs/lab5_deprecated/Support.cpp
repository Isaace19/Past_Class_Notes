/*
Name: Isaac Abella
Description: PPM file manipulator - source code implementation
*/

#include "Support.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ios>

using namespace std;

// create PPM class constructor
ppm::ppm() : magicid("P6"), Nrow(0), Ncol(0), maxvalue(255), img(NULL) {}; // set the block_size to one pixel per increment


// copy of the class constructor to put data into to compare
ppm::ppm(const ppm &clone) : magicid(clone.magicid), Nrow(clone.Nrow), Ncol(clone.Ncol), maxvalue(clone.maxvalue)
{
    img = new RGB[Nrow * Ncol];
    // for loop copies over the rows and coloumn and copies the img index into the P6 copy of the image.
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

void ppm::read(const string &imgfile)
{
    ifstream myfile(imgfile, ios::in | ios::binary);

    if (!myfile)
    {
        cout << "Error: cannot open " << imgfile << '\n';
        return;
    }

    // parse the header, maxvalue, and the rgb data values

    string verifyHeader;
    int verifyWidth, verifyHeight,verifyMax;
    myfile >> verifyHeader >> verifyWidth >> verifyHeight >> verifyMax;


    if (verifyHeader != magicid)
    {
        cout << "Error: The header: " << verifyHeader << " is not supported.\n";
        return;
    }
    if (verifyMax != maxvalue)
    {
        cout << "Error: The maxvalue: " << verifyMax << " is not supported\n";
        return;
    }
    myfile.ignore(1, '\n');

    // delete in case something was already in the img
	
    Nrow = verifyWidth;         
    Ncol = verifyHeight;
    img = new RGB[Nrow * Ncol]; 

    // read binary into the img array directly
    char *parse = static_cast<char*>(static_cast<void *>(img));

    while(myfile){
        myfile.read(parse, block_size);
        parse += block_size;
    }

   // not necessary
    myfile.close();
}

void ppm::write(const string &imgfileout)
{
    // write to new ppm file

    string outputfile = imgfileout.substr(0, imgfileout.rfind('.')); // find the . in the string here we can append the mod to it
    outputfile += "_mod.ppm";

    ofstream writefile("image_mod.ppm", ios::in | ios::binary);

    if (!writefile.is_open())
    {
        cout << "Cannot write to image_mod.ppm, exiting...\n";
        return;
    }

    
    //insert header first, than write the image array by byte.

    writefile << "P6" << '\n';
    writefile << Ncol << ' ' << Nrow << '\n';
    writefile << Ncol << ' ' << Nrow << '\n';
    writefile << maxvalue << '\n';


    // calculate dimensions
    int dimension =  Nrow * Ncol * sizeof(RGB);

    char *parse = static_cast<char*>(static_cast<void *>(img));
    while(dimension > block_size){
        writefile.write(parse, block_size);

        // for every bit parsed we get rid of dimensions.
        parse += block_size;
        dimension-= block_size;
    }
    writefile.write(parse,dimension);

    writefile.close();
}

int ppm::get_Nrow()
{
    return Nrow;
}

int ppm::get_Ncol()
{
    return Ncol;
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
            RGB temp = img[i][j]; // Use the operator[] to access pixels
            img[i][j] = img[i][numCols - 1 - j]; // Use the operator[] to access pixels
            img[i][numCols - 1 - j] = temp; // Use the operator[] to access pixels
        }
    }
}


void lens(ppm &img, float rho)
{
    // get the row and col data 
    int numRows = img.get_Nrow();
    int numCols = img.get_Ncol();



    // make a copy of the img.
    ppm copy = img;
    
    // get the radius of the row and columb by dividing by 2
    int ci = numRows /2;
    int cj = numCols/2;


    int rmax = std::min(numRows/2,numCols/2);

    for(int i = 0; i < numRows; ++i)
    {
        for(int j = 0; j < numCols; ++j)
        {
            // (di,dj) = (i-ci, j-cj)
            int di = i - ci;
            int dj = j - cj;

            double r = std::sqrt((di*di) + (dj*dj));

        if(r < rmax)
        {
            double z = std::sqrt((rmax * rmax) - (r * r));
            double dzi = di/std::sqrt((di*di) + (z*z));
            double dzj = dj/std::sqrt((dj*dj) + (z*z));

            double bi = (1.0-1/rho) * (std::asin(dzi));
            double bj = (1.0-1/rho) * (std::asin(dzj));

            int ip = ((int)(i-z*std::tan(bi)+0.5));
            int jp = ((int)(j-z*std::tan(bj)+0.5));
            // write to the clone image
            if (ip >= 0 && ip < numRows && jp >= 0 && jp < numCols)
            {
                img[i][j] = copy[ip][jp];
            }
        }
        }
    }
}
