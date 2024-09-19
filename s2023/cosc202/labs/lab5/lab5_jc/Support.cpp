#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

#include "Support.h"

ppm::ppm()
{
    magicid = "P6";
    block_size = 512;
    Nrow = 0;
    Ncol = 0;
    maxvalue = 255;
    img = NULL;
}

ppm::ppm(const ppm &other)
{
    magicid = other.magicid;
    block_size = other.block_size;
    Nrow = other.Nrow;
    Ncol = other.Ncol;
    maxvalue = other.maxvalue;
    int size = Nrow * Ncol;
    // copy rgb values over
    img = new RGB[size];
    for (int i = 0; i < size; ++i)
        img[i] = other.img[i];
}

ppm::~ppm()
{
    delete[] img;
    img = NULL;
}

RGB *ppm::operator[](int index)
{
    return img + index * Ncol;
}

void ppm::set_bs(int num)
{
    block_size = num;
}

void ppm::read(const string &in_file)
{
    // open file -- error check
    ifstream file(in_file, ios::binary);

    if (!file)
    {
        cerr << "Error: Unable to open the file ";
        return;
    }

    // read header
    string magic;

    int width, height, max_val;
    file >> magic >> width >> height >> max_val;

    if (magic != magicid || max_val != maxvalue)
    {
        cerr << "Error: Invalid PPM file format or max value is not 255.";
        return;
    }

    // ignore trailing newline after
    file.ignore(1, '\n');

    Nrow = height;
    Ncol = width;
    img = new RGB[height * width];

    char *cur = (char *)img;

    while (file)
    {
        file.read(cur, block_size);
        cur += block_size;
    }
    // skip blanks
    // check magicid
    // check maxvalue
    // read image (block_size) -- error check
    file.close();
}

void ppm::write(const string &output_file)
{
    // update file name
    string filename = output_file.substr(0, output_file.rfind('.'));
    filename += "_mod.ppm";

    ofstream file(filename, ios::binary);
    if (!file.is_open())
    {
        std::cerr << "Error opening file (ppm::write)";
        return;
    }

    file << magicid << '\n'
         << Ncol << ' ' << Nrow << '\n'
         << maxvalue << '\n';

    char *cur = (char *)img;
    // calculate size of buffer in bytes
    int size = Nrow * Ncol * sizeof(RGB);
    while (size > block_size)
    {
        // write current block
        file.write(cur, block_size);
        cur += block_size;
        size -= block_size;
    }
    // write remainder
    file.write(cur, size);

    file.close();
}

void gray(ppm &img) // change RBG to(R + G + B) / 3
{
    int size = img.get_Ncol() * img.get_Nrow();
    // get img.img
    RGB *data = img[0];
    // calculate end
    RGB *end = data + size;
    for (; data < end; ++data)
    {
        int value = (data->R + data->G + data->B) / 3;
        // set all values equal to the average value
        data->R = data->G = data->B = value;
    }
}

void flip(ppm &img) // flip image left - to - right
{
    for (int row = 0; row < img.get_Nrow(); ++row)
    {
        RGB *row_data = img[row];
        int first = 0;
        int last = img.get_Ncol() - 1;
        for (; first < last; ++first, --last)
        {
            RGB temp = row_data[first];
            row_data[first] = row_data[last];
            row_data[last] = temp;
        }
    }
}

void lens(ppm &img, float rho) // apply spherical transformation
{
    float ci = img.get_Nrow() / 2;
    float cj = img.get_Ncol() / 2;
    float rmax = min(cj, ci);
    ppm copy = img;
    for (int i = 0; i < img.get_Nrow(); ++i)
    {
        for (int j = 0; j < img.get_Ncol(); ++j)
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