/* More on argv and argc
    1. Check the argc for errors
    2. Deal with the data types of the arguments
        - The argument should be a string that's easy.
        A c-style string is an arraay of chars and can be set to a c++ string.
        - A Numerical, than we must deal with it.
            Either through stringstreams or stoi
*/

/*
    The Pitfalls of stoi

    Options to convert C-style strings to int/doubles
    1. stringstreams
    2. stoi(), stod(). stof()

    What are the pitfalls?
        1. There are some cases such like "abc123" to succeed conversion when
        most people would expect the string to fail.
        2. C++98 and earlier does not have a stoi() function.


*/

#include <iostream>
#include <sstream>

using namespace std;
// creating a stoi function above the main file for the code
// creating a helper function

int stringToInt(string s)
{
    int i;
    string s2;
    // cout << "  S = " << s << endl;
    // sin >> i >> s2;
    // cout << "  s2 = " << s2 << endl;
    istringstream sin(s); // Using the stingstream constructor
    if (!(sin >> i >> s2))
    {
        cerr << "Failed to convert string to int. " << endl;
    }
    return 1;
    /*understand the pitfalls of stoi and the use of stringstreams.
    Need to know that stoi is not available in older versions of c++, and that there
    are some cases where stoi will successfully run when we actually expect it to fail, which
    might not be helpful to our code.
    */
}

int main(int argc, char **argv)
{
    string str1 = "hello";
    string str2 = "123";
    string str3 = "abc123";
    string str4 = "123abc";
    string str5 = "10.5";

    int n, n2;
    n = stringToInt(str5);
    n2 = stoi(str4);

    cout << "My version: " << n << endl;
    // cout << "c++ Version: " << n2 << endl;
}