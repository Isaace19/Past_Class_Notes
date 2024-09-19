#include <iostream>
#include <set>
#include <cmath>

#include "Support.h"

prime_partition::prime_partition()
{
    // insert the smallest prime curr_number which is 2
    pset.insert(2);
}

void prime_partition::print_partition()
{
    // insert the partition state of the three possible prime numbers
    std::cout << partition_set[0] << '+' << partition_set[1] << '+' << partition_set[2] << '\n';
}

void prime_partition::find_partition(int curr_number)
{
    if (*pset.rbegin() < curr_number)
    {
        expand_pset(curr_number);
    }

    if (!find_partition(curr_number, 0))
    {
        std::cout << "Goldbach's conjecture proven wrong!!\n";
    }
    else
    {
        // print my partition
        print_partition();
    }
}

void prime_partition::expand_pset(int curr_number)
{
    int pset_max = *pset.rbegin();
    int next_prime = pset_max + 1;

    while (pset_max < curr_number)
    {
        bool found_prime = true;
        double k_max = sqrt(next_prime);

        for (set<int>::iterator it = pset.begin(); it != pset.end() && *it <= curr_number; ++it)
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

bool prime_partition::is_valid(int curr_number, int partition_state)
{
    if (curr_number == 0)
    {
        return partition_state == 3;
    }

    return true;
}

bool prime_partition::find_partition(int curr_number, int partition_state)
{
    if (curr_number == 0 && partition_state == 3)
    {
        return true;
    }

    if (curr_number < 0 || partition_state > 3)
    {
        return false;
    }

    for (set<int>::iterator i = pset.begin(); i != pset.end() && *i <= curr_number; ++i)
    {
        int k = *i;
        {
            partition_set[partition_state] = k;

            if (is_valid(curr_number - k, partition_state + 1))
            {
                if (find_partition(curr_number - k, partition_state + 1))
                {
                    return true;
                }
            }
        }
    }

    return false;
}
