// Simple skelton for error checking in cin
/*
1. We want to see if cin is in a fail state
2. If so, we fix that!
*/

#include <iostream>
using namespace std;

void ignoreLine()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
    int i, j;
    /*
    1. one way to wrap (cin >> i) in an if satement -
        a. if it returns true, it worked and we are not in a fail state.
        b. We can also use cin.fail();
        c. We can also do cin.good();
    2. If so, we use cin.clear() to get out of that state
    3. Skip over the bad data.
        a. we can use cin.ignore() - this ignores data until a certain character/can ignore the next x chars
        b. read in the bad data with a garbage string
    */
    if (cin >> i)
    {
        cout << "I is " << i << endl;
    }
    else
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (cin.fail())
    {
        cout << "J is " << j << endl;
    }
    else
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}