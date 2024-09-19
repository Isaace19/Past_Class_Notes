/*

Name: Isaac Abella
Objective: Print out the command line arguments and their addresses in
memory

*/

#include <iostream>
#include <cstdio>

int main(int argc, char *argv[])
{
    std::cout << "Num Args = " << argc << "\n";

    for (int i = 0; i < argc; ++i)
    {
        printf("argv[%d] = %p %s\n", i, (void *)&argv[i], argv[i]);
        // void pointers can hold addresses, so we use it to get
        // c style addresses stored in argv
    }
}
