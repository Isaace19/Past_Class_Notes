/*

Name: Isaac Abella
Objective: Print out the command line arguments and their addresses in
memory
now we also want to print out the length fo each argument with an implemented
int strlen(char*)

*/

#include <iostream>
#include <cstdio>
/*
 edit to mistake: the function implementation of strlen needs to take a c style argument so I 
 would need just a char pointer and not a pointer to const char
*/

size_t strlen(const char *str)
{
    // implement a way to get the length of a C-style string using pointers

    const char *p = str;
    int count = 0;

    // '\0' is the terminator of a line

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
