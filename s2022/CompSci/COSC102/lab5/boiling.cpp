/*
Program Name: speeding.cpp
Student name: Isaac Abella
Net ID: iabella
Student ID: 000641840
Program Description - This program will ask a user to input the number for which city they want to calculate
the boiling point of water for when they want to make coffee or tea
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <istream>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct CityRecord
{
    string city;
    string state;
    int elevation;
};

double calculation(int elevationout)
{
    double pressure = 29.921 * pow((1 - .0000068753 * elevationout), 5.2559);
    double boilingpoint = 49.161 * log(pressure) + 44.932;
    return boilingpoint;
};

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cerr << "usage" << argv[0] << " filename" << endl;
    }
    const string csv_filename = argv[1];

    ifstream fin(csv_filename);

    if (!fin.is_open())
    {
        cout << "File failed to open. " << endl;
        return 1;
    }

    vector<int> elevation;
    vector<string> cityName;
    vector<CityRecord> city_records;

    string line;
    getline(fin, line); // this gets the line of the column data not actual nums
    while (getline(fin, line))
    {
        // line;
        string buffer;
        string cityName;
        string state;

        istringstream sin(line);

        getline(sin, cityName, ',');
        getline(sin, state, ',');
        getline(sin, buffer, ',');

        int elevation = stoi(buffer);

        CityRecord city_record = {cityName, state, elevation};

        city_records.push_back(city_record);
    }
    int search;
    int num = 0;

    cout << "Boiling Point at Altitude Calculator \n";

    for (int it = 0; it < city_records.size(); ++it)
    {
        num = it + 1;
        cout << num << '.' << " " << city_records[it].city << "\n";
    }
    cout << "Enter City Number: ";
    cin >> search;
    string cityout = city_records[search - 1].city;
    int elevationout = city_records[search - 1].elevation;
    cout << "The boiling point at " << cityout << " is " << setprecision(3) << fixed << calculation(elevationout) << " degrees fahrenheight" << endl;

    fin.close();

    return 0;
}