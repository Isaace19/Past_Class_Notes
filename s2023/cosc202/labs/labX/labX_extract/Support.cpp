#include "Support.h"
#include <fstream>
#include <iostream>
#include <sstream>

// extract files

void database::extract_rawdata(const string &line)
{
    std::string modifiedString = line;
    for (size_t i = 0; i < line.length(); i++)
    {
        if (modifiedString[i] == ' ')
        {
            modifiedString[i] = '_';
        }
        if (modifiedString[i] == ',')
        {
            modifiedString[i] = ' ';
        }
    }
    std::stringstream ss(modifiedString);
    location loc;
    rawdata dat;

    // Extract values one by one
    ss >> dat.month;
    ss >> loc.city;
    ss >> loc.state;
    ss >> loc.geocode;
    ss >> dat.precip;
    ss >> dat.temp;
}