/*
Author: Isaac Abella
Description : Implementing the Support.h commands
*/
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

#include "Support.h"

int main(int argc, char *argv[])
{
    bool sorted = false;
    bool unique = false;
    bool verbose = false;

    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        if (arg == "-sorted")
        {
            sorted = true;
        }
        if (arg == "-unique")
        {
            unique = true;
        }
        if (arg == "verbose")
        {
            verbose = true;
        }
        else
        {
            std::cerr << "Usage: ./Prog3 [-sorted|unique] [-verbsoe]\n";
            return 1;
        }
    }

    isprime primer(verbose);
    std::vector<int> vec;
    int num_candidate;

    while ((std::cin >> num_candidate))
    {
        /*
        the () in push_back is overloaded to not only populate,
        but to also check the valid primes.
        */
        if (primer(num_candidate))
        {
            vec.push_back(num_candidate);
        }
    }
    if (vec.empty())
    {
        std::cout << '\n';
        return 1;
    }

    if (sorted || unique)
    {
        std::sort(vec.begin(), vec.end());
        if (unique)
        {
            std::vector<int>::iterator it = std::unique(vec.begin(), vec.end());
            vec.erase(it, vec.end());
        }
    }

    std::cout << std::right;
    int count = 0;
    for (size_t i = 0; i < vec.size() - 1; ++i)
    {
        std::cout << std::setw(4) << vec[i];
        if (++count % 20 == 0)
        {
            std::cout << '\n';
        }
        else
        {
            std::cout << ' ';
        }
    }

    if (count != 0)
    {
        std::cout << '\n';
    }

    std::cout << std::setw(4) << vec.back() << '\n';
    return 0;
}