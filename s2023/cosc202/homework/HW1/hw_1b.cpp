/*

Name: Isaac Abella
Objective: Print out the command line arguments and their addresses in
memory
now we also want to print out the length fo each argument with an implemented
int strlen(char*)

*/

#include <iostream>
#include <cstdio>

size_t strlen(const char *str)
{
    // implement a way to get the length of a C-style string using pointers

    // correction: size_t should be used when getting the length of objects and I can't have the function argument take pointer to a whole array

    const char *p = str;
    int count = 0;

    // while not at the end of the line, increment our count and char
    while (*p != '\0')
    {
        ++p;
        ++count;
    }
    return count;
}

int main(int argc, char *argv[])
{
    std::cout << "Num Args = " << argc << "\n";

    for (int i = 0; i < argc; ++i)
    {
        int length = strlen(argv[i]);
        printf("argv[%d] = %p %s (strlen=%d)\n", i, (void *)&argv[i], argv[i], length);
    }
}
