/*
Name: Isaac Abella
Description: Header file for PPM lab
*/

#ifndef __SUPPORT_H__
#define __SUPPORT_H__

#include <string>
using namespace std;

typedef unsigned char uchar;

struct RGB
{
    RGB() { R = 0, G = 0, B = 0; }
    uchar R, G, B;
};

class ppm
{
public:
    ppm();
    ppm(const ppm &);

    ~ppm();

    void read(const string &);
    void write(const string &);

    RGB *operator[](int rowIndex);

    void set_bs(int);
    void flip();

    int get_Nrow();
    int get_Ncol();

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
