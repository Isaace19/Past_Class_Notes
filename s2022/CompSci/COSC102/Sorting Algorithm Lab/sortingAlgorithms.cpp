/*
Program Name: bowling.cpp
Student name: Isaac Abella
Net ID: iabella
Student ID: 000641840
Program Description - Takes the user input file argument and sorts the values.
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

vector<int> get_vector(int argc, char **argv)
{
    // create the vector that will hold the int data and something to read into it
    vector<int> FileVector;
    ifstream file(argv[1]); // this will be used to read in the file strings to FileVector.
    string dummy;

    while (getline(file, dummy))
    {
        istringstream reader(dummy);
        int burner;
        while (reader >> burner)
        {
            FileVector.push_back(burner);
        }
    }
    file.close();
    return FileVector;
};

// TODO: Use this instead of the manual print I created inside of insertion and selection sort. to make things easier.
void printVector(vector<int> &FileVector)
{
    for (int i = 0; i < FileVector.size(); ++i)
    {
        cout << "  " << FileVector.at(i);
    }
    cout << "\n";
}

void InsertionSort(vector<int> &FileVector)
{
    int n = FileVector.size();
    for (int i = 1; i < n; i++)
    {
        int Sorted = FileVector.at(i);
        int Unsorted = i - 1;
        // Comparison operator between values are we move around
        while (Unsorted >= 0 && FileVector.at(Unsorted) > Sorted)
        {
            FileVector.at(Unsorted + 1) = FileVector.at(Unsorted);
            Unsorted--;
        }
        FileVector.at(Unsorted + 1) = Sorted;
        cout << "Beginning Vector: \n";
        printVector(FileVector);
        cout << "Finding placement of this value: " << i << endl;
        cout << i << " needs to be placed at index " << Sorted << endl;
        cout << "Current state of vector: \n";
        if (Unsorted == Sorted)
        {
            cout << "Sorted Array in Ascending Order: \n";
        }
        printVector(FileVector);
    }
}

void swapFunction(vector<int> &FileVector, int &dummy, int &dumdum)
{
    int temp = FileVector.at(dummy);
    FileVector.at(dummy) = FileVector.at(dumdum);
    FileVector.at(dumdum) = temp;
}

void SelectionSort(vector<int> &FileVector)
{
    int n = FileVector.size();
    int Unsorted, Sorted;
    for (int i = 0; i < (n - 1); i++)
    {
        Unsorted = i;
        for (int Sorted = i + 1; Sorted < n; Sorted++)
        {
            if (FileVector.at(Sorted) < FileVector.at(Unsorted))
            {
                Unsorted = Sorted;
            }
        }
        cout << "Step " << i << "\n";
        cout << "Selected Index: vec[" << i << "]" << Unsorted << "\n";
        cout << "vec[" << i << "] = " << Unsorted << " is the minimum. \n";
        cout << "SWAP \n";
        cout << "Vector after step " << i << ":\n";
        if (Sorted == Unsorted)
        {
            cout << "No swap. The selected index is the minimum.\n";
            cout << "Vector after step " << i << "\n";
            printVector(FileVector);
            cout << "Sorted Array in Ascending Order: \n";
        }
        swapFunction(FileVector, i, Unsorted);
        printVector(FileVector);
    }
}

int main(int argc, char **argv)
{

    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " filename.txt\n";
        return 1;
    }
    vector<int> DataFile = get_vector(argc, argv);

    // Start the isertion sort and selection sort process.
    // get the user input

    char input;
    while (true)
    {
        cout << "Type \"i\" for insertion sort or \"s\" for selection sort. ";
        cin >> input;
        if (input == 'i' || input == 's')
        {
            break;
        }
    }
    if (input == 'i')
    {
        InsertionSort(DataFile);
    }
    else if (input == 's')
    {
        SelectionSort(DataFile);
    }

    return 0;
}
