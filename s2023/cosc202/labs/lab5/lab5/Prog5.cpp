/*
Name: Isaac Abella
Description: Support Driver
*/

#include <iostream>
#include <string>
#include <fstream>
#include "Support.h" // Include the header file

using namespace std;

int main(int argc, char *argv[])
{
    int block_size = 512;
    float rho;
    bool grayscale = false;
    bool flip_image = false;
    bool apply_lens = false;

    for (int i = 1; i < argc; ++i)
    {
        string arg = argv[i];
        if (arg == "-gray")
        {
            grayscale = true;
        }
        else if (arg == "-flip")
        {
            flip_image = true;
        }
        else if (arg == "-lens" && i + 1 < argc)
        {
            rho = std::stod(argv[++i]);
            // gots to check if the rho value is valid
            if (rho <= 1 || rho > 2)
            {
                cerr << "usage: ./Prog5 [-gray] [-flip] [-lens z] [-bs nbytes] image.ppm\n"; // std::cerr
                return 1;
            }
            apply_lens = true;
        }
        else if (arg == "-bs" && i + 1 < argc)
        {
            block_size = std::stoi(argv[++i]);
        }
        else if (i != argc - 1)
        {
            cerr << "usage: ./Prog5 [-gray] [-flip] [-lens z] [-bs nbytes] image.ppm\n"; // std::cerr
            return 1;
        }
    }

    ppm p_image;
    p_image.set_bs(block_size);
    p_image.read(argv[argc - 1]);

    if (grayscale)
    {
        gray(p_image);
    }
    if (flip_image)
    {
        flip(p_image);
    }
    if (apply_lens)
    {
        lens(p_image, rho);
    }

    // stroke that thang cuzzo >_<

    p_image.write(argv[argc - 1]);
    return 0;
}