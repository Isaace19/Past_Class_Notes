#ifndef SUPPORT_H
#define SUPPORT_H

#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue> // for bst

using namespace std;

struct location
{
    string city;
    string state;
    string geocode;

    // order locations first by state, then by city
    bool operator<(const location &other) const;
    // output location by 42 characters wide
    void print() const; // output is constant 42 char width
};

struct rawdata
{
    int month;
    float precip;
    int temp;

    void print() const;
};

struct summary
{
    int N;

    float precip_avg;
    float precip_max;
    float precip_min;

    float temp_avg;
    float temp_max;
    float temp_min;

    summary();

    // takes a reference of the rawdata extracted
    void operator+(const rawdata &data);
    void print() const;
};

class database
{
public:
    void init_rawdata(const string &filename);
    void print_rawdata() const;

    void init_summary();
    void print_summary(const string &target) const;

private:
    void extract_rawdata(const string &line);
    void extract_summary();

    // requires appropriate data structure for each

    // map: location --> data
    // vector<list>: rawdata
    std::map<location, list<int>> location_map;
    std::vector<rawdata> rawdata_cache;

    // hash map: state --> geocode
    // hash map: geocode --> location
    // vector<vector>: summary
    std::map<string, string> state_map;
    std::map<string, location> geocode_map;

    // 2D vector
    std::vector<std::vector<summary>> summary_cache;
};

#endif