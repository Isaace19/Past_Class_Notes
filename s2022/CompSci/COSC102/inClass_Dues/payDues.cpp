#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    string line;
    ifstream fin;
    ifstream("dues.csv"); // imports file
    string name, email, tempString;
    bool Jan, Feb, Mar, Apr, May;

    getline(fin, line);
    while (getline(fin, line))
    {
        istringstream sin(line);       // breaks the whole line into pieces
        getline(sin, name, ',');       // store this in name vector: names.push_back(name);
        getline(sin, email, ',');      // store in email vector
        getline(sin, tempString, ','); // because getLine() cannot use bool, make a tempString
        if (tempString == "paid")
            Jan = true; // can write if in this format if there is only one line
        else
            Jan = false;
        getline(sin, tempString, ',');
        if (tempString == "paid")
            Feb = true;
        else
            Feb = false;
    }

    // ofstream fout(); // after saving data in while loop, go through vectors and write to output file
    ofstream fout("myNewFile.txt");
    string outputFileName = names[i] + ".txt";
    ofstream fout(outputFileName);
}
