/*

Name: Isaac Abella
Description: Use unix redirection to treat the .csv file as the std::cin input and output reformatted text
Now includes a class summary that should take loc objects and set them to station objects.

*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

struct location
{
    std::string city;
    std::string state;
    std::string geocode;
};

struct data
{
    int month;
    float precip;
    int temp;
};

class summary
{
public:
    summary()
    {
        N = 0;
        total_precip = 0.0;
        max_precip = 0.0;
        min_precip = 0.0;

        total_temp = 0;
        max_temp = 0;
        min_temp = 0;

        station.city = "";
        station.state = "";
        station.geocode = "";
    }

    bool empty()
    {
        return station.geocode.empty();
    }

    void set_station(const location &loc)
    {
        station = loc;
    }

    void incorporate_data(const data &dat)
    {
        N++;
        total_precip += dat.precip;
        total_temp += dat.temp;

        if (N == 1)
        {
            max_precip = min_precip = dat.precip;
            max_temp = min_temp = dat.temp;
        }
        else
        {
            if (dat.precip > max_precip)
            {
                max_precip = dat.precip;
            }
            if (dat.precip < min_precip)
            {
                min_precip = dat.precip;
            }

            if (dat.temp > max_temp)
            {
                max_temp = dat.temp;
            }
            if (dat.temp < min_temp)
            {
                min_temp = dat.temp;
            }
        }
    }

    void print_station()
    {
        std::cout << station.city << ", " << station.state << " (" << station.geocode << ")\n";
    }

    void print_data()
    {
        std::cout << ">>>  " << std::fixed << std::setprecision(2)
                  << std::setw(5) << total_precip << "  " << std::setw(5) << (total_precip / N) << "  "
                  << std::setw(5) << max_precip << "  " << std::setw(5) << min_precip << " : "
                  << std::setw(5) << std::setw(5) << (total_temp / N) << " "
                  << std::setw(5) << max_temp << " " << std::setw(5) << min_temp << "\n";
    }

private:
    location station;

    int N;

    float total_precip;
    float max_precip;
    float min_precip;

    int total_temp;
    int max_temp;
    int min_temp;
};

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

int geocode_to_index(const std::string &geocode)
{
    return ((geocode[0] - 'A') / 3) + 9 * ((geocode[1] - 'A') / 3) + 81 * ((geocode[2] - 'A') / 3);
}

int main()
{
    std::vector<summary> StationSummary(729);

    std::string line;
    while (getline(std::cin, line))
    {
        location loc;
        data dat;

        extract_values(line, loc, dat);
        int index = geocode_to_index(loc.geocode);

        if (StationSummary[index].empty())
            StationSummary[index].set_station(loc);

        StationSummary[index].incorporate_data(dat);
    }

    for (size_t i = 0; i < StationSummary.size(); i++)
    {
        if (!StationSummary[i].empty())
        {
            StationSummary[i].print_station();
            StationSummary[i].print_data();
        }
    }
}
