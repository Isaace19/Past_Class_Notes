/* Pass by value and Pass by reference */
#include <iostream>
using namespace std;

/* Passing a parameter by value means we make a copy of the parameter
for the function. IF YOU EDIT THAT PARAMETER AND WANT THAT EDIT IN MAIN,
 you won't get it with pass by value!
 
 Two reasons why you may NOT want to pass by value.
 1. If you want that edit to exist also in main
 2. If you will end up copying excessively large data around */
int myFunction(string s) { // passes "s" by value
    s = s + "7";
    cout << " s = " << s << endl;
    return 7;
}

/* The other option is to pass by reference */
/* Put an ampersand (&) between the parameter type and the parameter name */
int myFunction2(string &s) {
    s = s + "8";
    cout << " s = " << s << endl;
    return 8;
}

int main() {
    string str1 = "abc123";
    int result1 = myFunction(str1);
    int result2 = myFunction2(str1);

    cout << "my result from function 1 with pass by value: " << result1 << endl;
    cout << " str1 afterwards: " << str1 << endl;
    cout << "my result from function 2 with pass by reference: " << result2 << endl;
    cout << " str1 afterwards: " << str1 << endl;
}