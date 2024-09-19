#include <iostream>
#include <set>

#include "Support.h"

bool is_going_forward = false;
bool is_true = false;

int main(int argc, char *argv[])
{
    prime_partition goldbach;

    if (argc < 2 || argc > 3)
    {
        cerr << "usage: ./Prog8 -forward|reverse [-verbose]" << endl;
        return 1;
    }

    string forward = argv[1];

    if (forward == "-forward")
    {
        is_going_forward = true;
    }
    else if (forward == "-reverse")
    {
        is_going_forward = false;
    }
    else
    {
        cerr << "usage: ./Prog8 -forward|reverse [-verbose]\n";
        return 1;
    }

    while (1)
    {
        int user_input;
        std::cout << "number = ";
        std::cin >> user_input;

        if (cin.fail())
        {
            cout << endl;
            return 0;
        }

        if (user_input < 6)
        {
            cout << "Too small. Try again.\n";
            continue;
        }

        goldbach.find_partition(user_input);
    }

    return 0;
}
