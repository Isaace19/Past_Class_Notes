/*reading in an unknown amount of lines with a known column ONG
    Right now spaces are the data seperators
    1. Include <fstream>
    2.
*/

/*
StringStreams:

sin sout -> strings
1. #include <sstream>
2. createa an ostringstream variable
    ostringstream sout;
3. use sout w/operator <<
    and any formatting to create a string
    sout << retfill('o') << h << ":" << setw(2) << m << ":" << sestw(2) << s;

    3 note -> sout is a string otuput buffer

4. sout.str() -> this terturns a string

*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    string first, last;
    int h, m, s;

    vector<string> firstNames;
    vector<string> lastNames;

    fin.open("racetimesHMS.txt");
    if (!fin.is_open())
    {
        cout << "racetimesHMS.txt failed to open." << endl;
        return 1;
    }

    fout.open("racetimesOutput.txt"); // creates OR overwrties racetimesOutput.txt
    while (fin >> first >> last >> h >> m >> s)
    {
        /*anything that we do in this while loop will hapeen for
            every single line of data
        */
        firstNames.push_back(first);
        lastNames.push_back(last);
        fout << "You read: " << last << ", " << first << endl;
    }
    fin.close();
    fout.clear();
}
