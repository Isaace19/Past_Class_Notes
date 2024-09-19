/*  An introduction into File Streams
    How to read from files AND
    How to write to files!
    This program will be about READING in from files.
*/

/* HOW TO:
1. Opening a file
    a. declare a file stream variable
    b.  use .open() with filename in QOUTE if literal
2. Do a cbeck to verify this < didn't fail
    a. use !fin.is_open and print an error message
3. Extract info (we can use cin or cout >>/<<)
    a. Usimg nums.txt in the same directory to read data
4. Remember to close the file stream!
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("nums.txt");

    // If statement to check if the file opened
    if (!fin.is_open())
    {
        cout << "Could not open file nums.txt" << endl;
        return 1; // 1 signifies an error happened.
    }

    int data;
    fin >> data;
    cout << "The first piece of data is (data)" << data << endl;
    fin >> data;
    cout << "The Second piece of data is (data)" << data << endl;
    fin.close();

    // versus

    int terminalData1, terminalData2; // type in 10 20 in the terminal
    cin >> terminalData1;
    cin >> terminalData2;
    cout << "First: " << terminalData1 << " Second: " << terminalData2 << endl;
}