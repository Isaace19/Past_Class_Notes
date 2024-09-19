/*

Name: Isaac Abella
Description: Use unix redirection to treat the .csv file as the std::cin input and output reformatted text
Now includes a class summary that should take loc objects and set them to station objects.

*/

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include "support.h"

bool location::empty() const
{
    return geocode.empty();
}

void location::set_geocode(const char *code)
{
    geocode = code;
}

bool location::operator==(const location &locc) const
{
    return geocode == locc.geocode;
}

const location &summary::get_station() const
{
    return station;
}

summary::summary()
    // initalizing variables
    : monthly_data()
{
}
summary::summary(const location &loc)
    : monthly_data(), station(loc)
{
}
summary::DataPoint::DataPoint()
{
    total_precip = 0.0;
    max_precip = 0.0;
    min_precip = std::numeric_limits<float>::infinity();

    total_temp = 0;
    max_temp = 0;
    min_temp = 0;

    N = 0;
}

bool summary::empty()
{
    return station.empty();
}

void summary::set_station(const location &loc)
{
    station = loc;
}

void summary::incorporate_data(const data &dat)
{
    DataPoint &Curr = monthly_data[dat.month - 1];
    Curr.total_precip += dat.precip;
    Curr.total_temp += dat.temp;
    Curr.N++;

    if (Curr.N == 1)
    {
        Curr.max_precip = Curr.min_precip = dat.precip;
        Curr.max_temp = Curr.min_temp = dat.temp;
    }
    else
    {
        if (dat.precip > Curr.max_precip)
        {
            Curr.max_precip = dat.precip;
        }
        if (dat.precip < Curr.min_precip)
        {
            Curr.min_precip = dat.precip;
        }

        if (dat.temp > Curr.max_temp)
        {
            Curr.max_temp = dat.temp;
        }
        if (dat.temp < Curr.min_temp)
        {
            Curr.min_temp = dat.temp;
        }
    }
}

void summary::print_station()
{
    std::cout << "------------------------------------------\n";
    std::cout << station.city << ", " << station.state << " (" << station.geocode << ")\n";
    std::cout << "------------------------------------------\n";
}

void summary::print_data()
{
    // have the month data as a static const so it can be used in our print out.
    static const char *months[12] = {"Jan",
                                     "Feb",
                                     "Mar",
                                     "Apr",
                                     "May",
                                     "Jun",
                                     "Jul",
                                     "Aug",
                                     "Sep",
                                     "Oct",
                                     "Nov",
                                     "Dec"};

    for (int i = 0; i < 12; ++i)
    {
        DataPoint const &Curr = monthly_data[i];
        std::cout << months[i] << ": " << std::fixed << std::setprecision(2)
                  << std::setw(5) << Curr.total_precip << " " << std::setw(5) << (Curr.total_precip / Curr.N) << " "
                  << std::setw(5) << Curr.max_precip << "  " << std::setw(5) << Curr.min_precip << " : "
                  << std::setw(5) << (Curr.total_temp / Curr.N) << "  "
                  << std::setw(5) << Curr.max_temp << "  " << std::setw(5) << Curr.min_temp << "\n";
    }
    std::cout.flush();
}

void extract_values(std::string &line, location &loc, data &dat)
{
    for (size_t i = 0; i < line.length(); i++)
    {
        if (line[i] == ' ')
        {
            line[i] = '_';
        }
        if (line[i] == ',')
        {
            line[i] = ' ';
        }
    }
    std::stringstream ss(line);

    // Extract values one by one
    ss >> dat.month;
    ss >> loc.city;
    ss >> loc.state;
    ss >> loc.geocode;
    ss >> dat.precip;
    ss >> dat.temp;
}
