/*
Reminder of how to read files:
1. Include <fstream> header file
2. Declare a file variable (ifstream for reading - stands for input file stream) (ofstream for writing - output file stream)
   and name it (typically fin, fout)
3. 3a. Open the file connecting the variable to the actual file and 3b. check for failure to open.
4. Do the work on the intended file (either read from the file or write to the file) using <<, >>
5. Close the file.
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string> //needed for getline
#include <vector>
using namespace std;

int main() {
    ifstream fin("mycsvfile.txt");

    if(!fin.is_open()) {
        cout << "File failed to open." << endl;
        return 1;
    }

    string line, firstName, lastName, tempString, stringAge;
    int age;
    vector <vector <string> > dataTable;
    while(getline(fin, line)) {
        vector <string> person;
        istringstream ss(line);

        getline(ss, firstName, ',');
        person.push_back(firstName);

        getline(ss, lastName, ',');
        person.push_back(lastName);

        getline(ss, tempString, ',');
        getline(ss, stringAge); 
        person.push_back(stringAge);

        age = stoi(stringAge);
        cout << firstName << " " << lastName << " " << age << endl;

        dataTable.push_back(person);
    }

    for (int i = 0; i < dataTable.size(); i++) {
        for (int j = 0; j < dataTable[0].size(); j++) {
            cout << dataTable[i][j] << " ";
        }
        cout << endl;
    }

    fin.close();
}
