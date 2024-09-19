#ifndef __SUPPORT_H__
#define __SUPPORT_H__

#include <string>
using std::string;
sdf:
ea:
typedef unsigned char uchar;

struct RGB {
  RGB() { R=0, G=0, B=0; }
  uchar R, G, B;
};

class ppm {
  public:
    ppm();
    ppm(const ppm &);

    ~ppm();

    void read(const string &);
    void write(const string &);

    RGB *operator[](int);

    void set_bs(int);

    int get_Nrow() { return Nrow; }
    int get_Ncol() { return Ncol; }

  private:
    string magicid;

    int Nrow, Ncol;
    int maxvalue;

    int block_size;
    RGB *img;
};

void gray(ppm &);
void flip(ppm &);
void lens(ppm &, float);

#endif
