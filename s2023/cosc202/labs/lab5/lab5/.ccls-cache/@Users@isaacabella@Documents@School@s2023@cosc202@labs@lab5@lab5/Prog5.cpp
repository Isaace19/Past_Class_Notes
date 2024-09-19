#include ...

#include "support.h"

int main(int argc, char *argv[]) {
  int block_size = 512;
  float rho = 1.0;

  read command line arguments
    -gray (optional)
	-flip (optional)
	-lens z (optional)
	-bs n (optional)
	file name (required)

  error check: 1.0 < z <= 2.0
  error check: file name given

  instantiate ppm image
  set fileio block size

  read image

  if specified,
    apply gray conversion

  if specified
    flip image left-to-right

  if specified
    apply spherical transformation

  write image
}
