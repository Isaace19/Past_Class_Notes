/*
Author: Isaac Abella
Description : Implementing the Support.h commands
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include "Support.h"

template <typename T>
bool primer(T N)
{
    for (T i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
            return false;
    }
    return true;
}
// create pointer obj to verbose.
isprime::isprime(bool verbose) : verbose(verbose)
{
    known_primes.assign(1, 2);
}

bool isprime::operator()(int N)
{
    if (N < 2)
        return false;

    if (N > known_primes.back())
        expand_known_primes(N);

    return std::binary_search(known_primes.begin(), known_primes.end(), N);
}

void isprime::expand_known_primes(int N)
{
    if (!verbose)
    {
        for (int i = known_primes.back() + 1;; ++i)
        {
            if (primer(i))
            {
                known_primes.push_back(i);
                if (i >= N)
                    break;
            }
        }
    }
    else
    {
        std::cout << "updating " << N << '\n';
        for (int i = known_primes.back() + 1;; ++i)
        {
            if (primer(i))
            {
                std::cout << "adding " << i << "...\n";

                known_primes.push_back(i);

                if (i >= N)
                    break;
            }
        }
    }
}
