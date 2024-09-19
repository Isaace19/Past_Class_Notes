/*

Name: Isaac Abella
Description: Use unix redirection to treat the .csv file as the std::cin input and output reformatted text

*/

#include <iostream>
#include <sstream>
#include <string>
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
    ss >> dat.month >> loc.city >> loc.state >> loc.geocode >> dat.precip >> dat.temp;
}

int main()
{
    std::string line;

    while (getline(std::cin, line))
    {
        location loc;
        data dat;

        extract_values(line, loc, dat);
        std::cout << dat.month << " " << loc.city << " " << loc.state << " " << loc.geocode << " " << std::fixed << std::setprecision(2) << dat.precip << " " << dat.temp << "\n";
    }
    return 0;
}
