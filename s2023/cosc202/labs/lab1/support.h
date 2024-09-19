/*

Name: Isaac Abella
Description: Use unix redirection to treat the .csv file as the std::cin input and output reformatted text
Now includes a class summary that should take loc objects and set them to station objects.

*/
#ifndef SUPPORT_H
#define SUPPORT_H
#include <string>
#include <vector>

struct location
{
    std::string city;
    std::string state;
    std::string geocode;

    bool empty() const;
    void set_geocode(const char *);
    bool operator==(const location &) const;
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
    summary();
    summary(const location &loc);

    bool empty();

    void set_station(const location &loc);
    void incorporate_data(const data &dat);
    void print_station();
    void print_data();

    const location &get_station() const;

private:
    struct DataPoint
    {
        DataPoint();
        // total_precip is a monthly calculation.
        float total_precip;
        float max_precip;
        float min_precip;

        int total_temp;
        int max_temp;
        int min_temp;

        int N;
    };
    // data for each month
    DataPoint monthly_data[12];

    location station;
};

void extract_values(std::string &line, location &loc, data &dat);

#endif
