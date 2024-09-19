#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <sstream>
#include <ostream>

using namespace std;

typedef vector<int> iVec;

int main(int argc, char **argv)
{
    vector<iVec> pascal;
    int r;
    istringstream sin;
    ostringstream sout;
    stringstream ss; // this is confusing so don't use it because you'll probably be confused when you try to do str.()

    if (argc != 2)
    {
        cerr << "usage: ./pascal rows \n";
        return 1;
    }

    // argv[1] holds the number of rows.
    // argv[1] can easily be changed to a c++ string currently a c-style
    // could get this into an integer data type 2 ways: stoi() or stringstreams

    sin.str(argv[1]);
    if (!(sin >> r))
    {
        cerr << "Bad rows - need integer \n";
        return 1;
    }

    // extract r

    // sout << "blahblahblah" << endl;
    // sout.str();

    cout << "you entered: " << r << " rows." << endl;
    pascal.resize(r); // this changes the outer vectoor to be the size of the # rows
    for (int it = 0; it < pascal.size(); it++)
    {
        for (int j = 0; j <= it; j++) // J will be the cell number
        {
            if (j == 0)
            {
                pascal[it].push_back(1);
            }
            else
            {
                pascal[it].push_back(pascal[it - 1][j - 1] + pascal[it - 1][j]);
            }
        }
    }

    // Resizze:
    // Increasing - will give null/0 zeros if we don't specify
    // Decreasing - removes off the back end of the vector

    for (int it = 0; it < pascal.size(); it++)
    {
        // cout << "I = " << it << endl;
        for (int j = 0; j < pascal[it].size(); j++) // J needs to run its condition through iterator in order to output correctly.
        {
            // cout << "J = " << j << endl;
            printf("%4d", pascal[it][j]);
        }
        printf("\n"); // Dijkstra and his alogirithm and the reason we use I and J for for loops because of him
    }
}