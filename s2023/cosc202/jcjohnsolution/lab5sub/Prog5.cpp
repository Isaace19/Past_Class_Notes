// John Cordwell III
// reads in ppm file, manipulates data (gray, flip, lens) and outputs modified ppm file

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
#include "Support.h"

int main(int argc, char *argv[])
{
  int block_size = 512;
  float z;

  bool gray_bool = false; // -gray
  bool flip_bool = false; // -flip
  bool lens_bool = false; // -lens z
  // -bs n

  for (int i = 1; i < argc; ++i) // read command line arguments
  {
    string option = argv[i];

    if (option == "-gray")
      gray_bool = true;
    else if (option == "-flip")
      flip_bool = true;
    else if (option == "-lens" && i + 1 < argc)
    {
      z = stod(argv[++i]);
      if (z <= 1 || z > 2)
      {
        cerr << "usage: ./Prog5 [-gray] [-flip] [-lens z] [-bs nbytes] image.ppm\n"; // std::cerr
        return 1;
      }
      lens_bool = true;
    }
    else if (option == "-bs" && i + 1 < argc) // possibly check for n
    {
      block_size = stoi(argv[++i]);
    }
	else if (i != argc-1)
	{
        cerr << "usage: ./Prog5 [-gray] [-flip] [-lens z] [-bs nbytes] image.ppm\n"; // std::cerr
        return 1;  
	}
  }

  ppm image;                // instantiate ppm image
  image.set_bs(block_size); // set fileio block size

  image.read(argv[argc - 1]); // read image

  if (gray_bool)
    gray(image); // apply gray conversion

  if (flip_bool)
    flip(image); // flip image left-to-right

  if (lens_bool)
    lens(image, z); // apply spherical transformation

  // write image
  image.write(argv[argc - 1]);
}
