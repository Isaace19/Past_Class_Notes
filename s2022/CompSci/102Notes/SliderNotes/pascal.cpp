#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

typedef vector <int> iVec;

int main(int argc, char **argv) {
    vector <iVec> pascal;
    int r;
    istringstream sin; //stringstream ss; is a bidirectional ss

    if (argc != 2) {
        cerr << "usage: ./pascal rows\n";
        return 1;
    }

    //argv[1] holds the number of rows. 
    //argv[1] can easily be changed to a c++ string, currently a c-style
    //could get this into an integer data type 2 ways: stoi() or stringstreams
    sin.str(argv[1]);
    if (!(sin >> r)) { 
        cerr << "Bad rows - need an integer\n";
        return 1;
    }

    //cout << "you entered " << r << " rows" << endl;
    /* Resize: 
    - increasing - will give null/0 zeros if we don't specify
    - decreasing - removes off the back end of the vector */
    pascal.resize(r); //this changes the outer vector to be the size of the # of rows
    for (int i = 0; i < pascal.size(); i++) { //i will be the row number
        for (int j = 0; j <= i; j++ ) { // j will be the cell number... p[i][j]
            if (j == 0 || j == i) {
                pascal[i].push_back(1);
            }
            else {
                pascal[i].push_back(pascal[i-1][j-1] + pascal[i-1][j]);
            }
        }
    }

    // print for sanity check
    for (int i = 0; i < pascal.size(); i++) {
        for (int j = 0; j < pascal[i].size(); j++) {
            printf(" %4d", pascal[i][j]);
        }
        printf("\n");
    }

}