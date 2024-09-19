/*
Author: Isaac Abella
Description : Implementing the Support.h commands
*/

#ifndef SUPPORT_H
#define SUPPORT_H

#include <vector>
using std::vector;

class isprime
{
public:
    isprime(bool verbose = false);
    bool operator()(int N);

private:
    void expand_known_primes(int N);

    bool verbose;
    vector<int> known_primes;
};

#endif
