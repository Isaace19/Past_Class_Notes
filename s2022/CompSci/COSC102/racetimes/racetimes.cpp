/* READING IN AN UNKNOWN AMT OF LINES with a KNOWN COLUMN ORG
   Right now spaces are the data separators
   FName LName H M S
   0. Include <fstream>
   1. Open the file and have an ifstream variable declared
   2. Check to see if the open failed
   3. Extract data
   4. close the file stream
   -----------
   Writing to a file. (i.e. creating an output file)
   1. ofstream fout
   */
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

string formatTime(int h, int m, int s)
{
    stringstream sout;
    sout << setfill('0') << h << ":" << setw(2) << m << ":" << setw(2) << s;
    return sout.str();
}

string calcPace(int h, int m, int s)
{
    ostringstream sout;
    int pMin, pSec;
    double marthonDist = 26.8;

    // Marathon Pace Calcuations
    int totalSeconds = (h * 3600) + (m * 60) + s;
    double totalPace = totalSeconds / marthonDist;
    pMin = (int)(totalPace / 60);
    pSec = (int)(totalPace + .5) % 60;

    sout << setfill('0') << h << ":" << setw(2) << pMin << setw(2) << pSec;
    return sout.str();
}

int main(int argc, char **argv)
{
    ifstream fin;
    ofstream fout;
    string first, last;
    int h, m, s;
    vector<string> firstNames;
    vector<string> lastNames;

    if (argc == 2)
    {
        cout << "You have 2 argument on the command line!" << endl;
    }
    string fileName = argv[1];
    string outputFileName = argv[2];

    fin.open("racetimesHMS.txt");
    if (!fin.is_open())
    {
        cout << "racetimesHMS.txt failed to open." << endl;
        return 1;
    }

    fout.open(outputFileName); // creates OR overwrites racetimesOutput.txt
    while (fin >> first >> last >> h >> m >> s)
    {
        /* Anything we do in this while loop will happen for
           every single line of data */
        firstNames.push_back(first);
        lastNames.push_back(last);
        // cout << "You read: " << last << ", " << first << endl;
        fout << "You read: " << last << ", " << first << "   ";
        fout << formatTime(h, m, s) << endl;
        fout << "Average Pace: " << calcPace(h, m, s) << endl;
    }

    fin.close();
    fout.close();
}