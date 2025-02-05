#include <iostream>
#include <sstream>
// Everything in C++ is passed by value by default except for arrays.
using namespace std;

int myFunction(string s)
{
    s = s + "7";
    return 7;
}
/*
C++ always passes "s" by value

passing a parameter by value means we make a copy of the parameter
IF YOU EDIT THAT PARAMTER AND WNAT THAT EDIT IN MAIN, YOU WON'T GET IT WITH THE PASS BY VALUE!

2 Reasons why you may not want to pass by value:
    1. If you want the edit to happen in main
    2. If you will end up copying excessively large data around.

The other option is to pass by reference
We will use an aanpersand & in between the parameter type and parameter name in order to call the reference
*/

int myFunction2(string &s)
{
    s = s + "8";
    return 8;
}

int main(int argc, char **argv)
{
    string str1 = "abe123";
    int result1 = myFunction(str1);
    int result2 = myFunction2(str1);

    cout << "My result is from function 1 with pass by value " << result1 << endl;
    cout << " str1 afterwards: " << str1 << endl;
    cout << "My result is from the function 2 with pass by reference " << result2 << endl;
    cout << " str1 afterwards: " << str1 << endl;
}