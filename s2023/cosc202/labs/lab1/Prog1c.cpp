#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "support.h"

int main(int argc, char *argv[])
{

    // checking bad input
    if (argc != 1 && argc != 2)
    {
        std::cerr << "usage: " << argv[0] << " [geocode] < datafile " << std::endl;
    }

    // if the user requests no geocode just proceed as normal.

    std::vector<summary> StationSummary;

    std::string line;
    while (getline(std::cin, line))
    {
        location loc;
        data dat;

        extract_values(line, loc, dat);

        // Implement a check for a certain geocode

        bool match = false;
        for (size_t i = 0; i < StationSummary.size(); i++)
        {
            if (StationSummary[i].get_station() == loc)
            {
                StationSummary[i].incorporate_data(dat);
                match = true;
                break;
            }
        }

        /*
        If we can't find a match with the current vecotr, then we
        push a new summary object into the StationSummary, then get data
        as normal.
        */
        if (!match)
        {
            StationSummary.push_back(summary(loc));
            StationSummary.back().incorporate_data(dat);
        }
    }

    if (argc == 2)
    {
        // Check if a geocode is provided and print data for that city only
        const std::string TargetUserGeocode = argv[1];
        for (size_t i = 0; i < StationSummary.size(); i++)
        {
            if (StationSummary[i].get_station().geocode == TargetUserGeocode)
            {
                StationSummary[i].print_station();
                StationSummary[i].print_data();
            }
        }
    }
    else
    {
        for (size_t i = 0; i < StationSummary.size(); i++)
        {
            if (!StationSummary[i].empty())
            {
                StationSummary[i].print_station();
                StationSummary[i].print_data();
            }
        }
    }
    return 0;
}
