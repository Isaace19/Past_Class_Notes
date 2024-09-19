/*
Program Name: calc.cpp
Student name: Isaac Abella
Net ID: iabella
Student ID: 000641840
Program Description - This program will ask for a left operand,
math operation, and a right operand and than calculate their total.
*/

#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int input1;
    int input2;
    char operation;

    // define the operations that are valid to the code

    cout << "Enter an integer: " << endl;
    cin >> input1;
    // error stream output if user enters an invalid operator into code
    if (cin.fail())
    {
        cerr << "Invalid left Operand" << endl;
        return 1;
    }

    if (operation != 'B' && operation != 'b' && operation != '|')
    {
        cout << "Enter  right operand";
        cin >> right;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (cin.fail())
        {
            cout << "Invalid operation" << endl;
            return 1;
        }
    }

    // cout << "Enter an operation: " << endl;
    // cin >> operation;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // This section of the code will find the absolute value given only the left hand input and the opeartion

    switch (operation)
    {
    case 'B':
    case 'b':
    case '|':
        if (input1 < 0)
        {
            input1 = -1 * input1;
            cout << "Result =  " << +(input1) << endl;
            return 0;
        }
        else
        {
            cout << "Result = " << +(input1) << endl;
            return 0;
        }
    }

    cout << "Enter a second integer: " << endl;
    cin >> input2;
    if (cin.fail())
    {
        cerr << "Invalid right Operand" << endl;
        return 1;
    }

    /*
    The switch statement tests all the possible inputs for arithmatic operations and outputs a proper result
    Should the user enter an unrecognized input, than the code will return an error code and end.
    */

    switch (operation)
    {
    case 'A':
    case 'a':
    case '+':
        cout << "Result = " << +(input1 + input2) << endl;
        return 0;
    case 'S':
    case 's':
    case '-':
        cout << "Result =" << +(input1 - input2) << endl;
        return 0;
    case 'M':
    case 'm':
    case '*':
        cout << "Result = " << +(input1 * input2) << endl;
        return 0;
    case 'D':
    case 'd':
    case '/':
        cout << "Result = " << +(input1 / input2) << endl;
        return 0;
    case 'C':
    case 'c':
    case '%':
        cout << "Result = " << +(input1 / input2) << endl;
        return 0;
    default:
        cout << "Unknown Operation." << endl;
        return 1;
    }

    return 0;
}
