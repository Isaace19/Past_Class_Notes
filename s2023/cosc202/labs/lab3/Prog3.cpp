/*
Author: Isaac Abella
Description : Implementing the Support.h commands
*/

#include "Support.h"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

void Error_Prog()
{
	std::cerr << "usage: ./Prog3 [-sorted|unique] [-verbose] < file.txt\n";
}


int main(int argc, char *argv[])
{

	// we have to error check for seperate errors in ./Numbers and ./Prog3

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
		else if (arg == "-unique")
        {
            unique = true;
        }
		else if (arg == "-verbose")
        {
            verbose = true;
        }
		else
		{
			Error_Prog();
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
	// sorted sequence of prime numbers (no unique)
	if (sorted || unique)
	{
		std::sort(vec.begin(), vec.end());
		if(unique)
		{
			std::vector<int>::iterator it = std::unique(vec.begin(), vec.end());
			vec.erase(it, vec.end());
		}
	}
	
	std::cout<<std::right;	
    int count = 0;
    for (size_t i = 0; i < vec.size() -1; ++i)
    {
        std::cout << std::setw(4) << vec[i];
        if (++count%20 == 0)
        {
            std::cout << '\n';
			count = 0;
        }else
		{
			std::cout << ' ';
		}
	}
	std::cout << std::setw(4) << vec.back() << '\n';
	return 0;
}
