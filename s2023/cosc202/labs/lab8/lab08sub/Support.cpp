#include <iostream>
#include <set>
#include <cmath>

#include "Support.h"

using namespace std;

prime_partition::prime_partition()
{
    pset.insert(2); // smallest prime number is 2
}

void prime_partition::print_partition()
{
    cout << partition[0] << '+' << partition[1] << '+' << partition[2] << '\n';
}

void prime_partition::find_partition(int number)
{
    if (*pset.rbegin() < number)
    {
        if (*pset.rbegin() < number)
            expand_pset(number);

        if (!find_partition(number, 0))
            cout << "Goldbach's conjecture proven wrong!!\n";
        else
            print_partition(); // Print partition here
    }
}

void prime_partition::expand_pset(int number)
{
    int pset_max = *pset.rbegin();
    int next_prime = pset_max + 1;

    while (pset_max < number)
    {
        bool found_prime = true;
        double k_max = sqrt(next_prime);

        for (set<int>::iterator it = pset.begin(); it != pset.end() && *it <= number; ++it)
        {
            int k = *it;
            if (k > k_max)
                break;
            if (next_prime % k == 0)
            {
                found_prime = false;
                break;
            }
        }

        if (found_prime)
        {
            pset.insert(next_prime);
            pset_max = next_prime;
        }

        ++next_prime;
    }
}

bool prime_partition::is_valid(int number, int terms)
{
    if (number == 0)
        return terms == 3;

    return true;
}

bool prime_partition::find_partition(int number, int terms)
{
    if (number == 0 && terms == 3)
        return true;
    if (number < 0 || terms > 3)
        return false;

    for (set<int>::iterator it = pset.begin(); it != pset.end() && *it <= number; ++it)
    {
        int k = *it;
        {
            partition[terms] = k;

            if (is_valid(number - k, terms + 1))
            {
                if (find_partition(number - k, terms + 1))
                    return true;
            }
        }
    }

    return false;
}