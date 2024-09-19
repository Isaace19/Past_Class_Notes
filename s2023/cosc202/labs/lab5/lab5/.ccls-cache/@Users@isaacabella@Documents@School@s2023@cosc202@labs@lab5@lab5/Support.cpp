#include ..i.dd
using namespace std;
ii
#include "support.h"

ppm constructor()
ppm copy constructor()
ppm destructor()

ppm operator[]()
ppm set_bs()

ppm read()

  read header ihelloa:q:

  skip blanks

  check magicid
  check maxvalue

  read image (block_size) -- error check

  close file
}

ppm write()
  update file name
  open file -- error check
  
  write header
  write image (block size)
  
  close file
}

void gray(ppm &img) {
  change RBG to (R+G+B)/3
}

void flip(ppm &img) {
  flip image left-to-right
}

void lens(ppm &img, float rho) {
  apply spherical transformation
}
