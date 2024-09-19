/*
Program Name: speeding.cpp
Student name: Isaac Abella
Net ID: iabella
Student ID: 000641840
Program Description - This program will open a file of data to calculate the proper
speeding tax to fine someone given the type of road they were caught on.
*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// declaring the speeding multipliers
const double INTERSTATE_MULT = 5.2243;
const double HIGHWAY_MULT = 9.4312;
const double RESIDENTIAL_MULT = 17.2537;
const double DEFAULT_MULT = 17.916;

// Calcuation for the fine multiplier
double fineCalculation(int Speed, int SpeedLimit, char Roadtype)
{
    double fine = (Speed - SpeedLimit);
    switch (Roadtype)
    {
    case 'i':
        fine *= INTERSTATE_MULT;
        break;
    case 'h':
        fine *= HIGHWAY_MULT;
        break;
    case 'r':
        fine *= RESIDENTIAL_MULT;
        break;
    case 'p':
        fine *= DEFAULT_MULT;
    }
    if (fine < 0)
        fine = 0;
    return fine;
}

int main()
{
    const string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int dds, mms, yyyys, Speed, SpeedLimit, ddf, mmf, yyyyf;
    int dd, mm, yyyy;
    char Roadtype;
    string ticket_FileName, CitationNumber, ReportFile_Name;

    ostringstream sout;
    ifstream fin;
    ofstream fout;

    cout << "Enter a ticket file: \n";
    cin >> ticket_FileName;
    fin.open(ticket_FileName);
    if (!fin.is_open())
    {
        cerr << "Unable to Open " << ticket_FileName << "." << endl;
        return 1;
    }

    cout << "Enter a report file: \n";
    cin >> ReportFile_Name;
    fout.open(ReportFile_Name);
    if (fout.fail())
    {
        cerr << "Failed to write into file " << endl;
        return 1;
    }

    cout << "Enter a report start date: (mm dd yyyy)\n";
    cin >> mms >> dds >> yyyys;
    cout << "Enter a report end date:   (mm dd yyyy)\n";
    cin >> mmf >> ddf >> yyyyf;

    // Calculations section to write into the file.
    while (fin >> CitationNumber >> mm >> dd >> yyyy >> Speed >> SpeedLimit >> Roadtype)
    {
        if (yyyy < yyyys || yyyyf < yyyy)
        {
            continue;
        }
        if (yyyy == yyyys && mm < mms)
        {
            continue;
        }
        if (yyyy == yyyys && dd < dds)
        {
            continue;
        }
        // Calculations section
        if (yyyy < 100)
            yyyy += 2000;
        if (yyyys >= yyyy && yyyy <= yyyyf)
        {
            fout << setfill('0') << setw(2) << dd << "-" << months[mm - 1] << "-" << yyyy << " " << left << setfill(' ') << setw(10) << CitationNumber << fixed << right << " $ " << setw(9) << setprecision(2) << fineCalculation(Speed, SpeedLimit, Roadtype) << endl;
        }
    }

    fin.close();
    fout.close();

    return 0;
}