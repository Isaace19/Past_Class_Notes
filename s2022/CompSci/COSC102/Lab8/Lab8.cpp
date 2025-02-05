#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class BITSET
{
    vector<int> mSets;

public:
    BITSET();
    bool Test(int index) const;
    void Set(int index);
    void Clear(int index);
    int GetNumSets() const;
    int GetSet(int index) const;
};
string ToBinary(int bit_set, int spacing = 4);
int main()
{
    BITSET sets;
    string command;
    int which;
    do
    {
        cout << "> ";
        if (!(cin >> command) || "q" == command)
        {
            break;
        }
        // Handle the commands here
        if ("t" == command)
        {
            if (!(cin >> which))
            {
                cout << "Invalid index\n";
            }
            else
            {
                cout << sets.Test(which) << '\n';
            }
        }
        else if ("s" == command)
        {
            if (!(cin >> which))
            {
                cout << "Invalid index\n";
            }
            else
            {
                sets.Set(which);
            }
        }
        else if ("g" == command)
        {
            int spacing;
            string line;
            getline(cin, line);
            istringstream sin{line};
x            if (!(sin >> which))
            {
                cout << "Invalid index\n";
            }
            else
            {
                if (!(sin >> spacing))
                {
                    spacing = 4;
                }
                cout << ToBinary(sets.GetSet(which), spacing) << '\n';
            }
        }
        else if ("c" == command)
        {
            if (!(cin >> which))
            {
                cout << "Invalid index\n";
            }
            else
            {
                sets.Clear(which);
            }
        }
        else if ("n" == command)
        {
            cout << sets.GetNumSets() << '\n';
        }
        else
        {
            cout << "Unknown command '" << command << "'\n";
        }
    } while (true);
    return 0;
}

string ToBinary(int bit_set, int spacing)
{
    string ret;
    int whitespace = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (bit_set & (1 << i))
        {
            ret += '1';
        }
        else
        {
            ret += '0';
        }
        if ((ret.size() - whitespace) % spacing == 0 && (ret.size() - whitespace) % 32 != 0)
        {
            ret += ' ';
            whitespace++;
        }
    }
    return ret;
}

// BITSET Class Members
BITSET::BITSET() : mSets(1, 0)
{
}

bool BITSET::Test(int index) const
{
    // Recall that each set has 32 bits
    int which_set = index / 32;
    int which_bit = index % 32;
    if (which_set >= GetNumSets())
    {
        return false;
    }
    else if ((mSets.at(which_set) & (1 << which_bit)) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void BITSET::Set(int index)
{
    int which_set = index / 32;
    int which_bit = index % 32;
    if (which_set >= GetNumSets())
    {
        mSets.resize(which_set + 1, 0);
    }
    mSets.at(which_set) |= (1 << which_bit);
}

void BITSET::Clear(int index)
{
    int which_set = index / 32;
    int which_bit = index % 32;
    if (which_set < GetNumSets())
    {
        mSets.at(which_set) &= ~(1 << which_bit);
        // Nesting a while loop to check the whichset and deleting the last character out of that
        // we want to check the mSets bits at the which set to make sure that they are cleared and then we want to check that
        // the size of the bits vector is greater than 0 before we delete the last item in the list.
        while (mSets.back() == 0 && (mSets.size() > 1))
        {
            mSets.pop_back();
        }
    }
}

int BITSET::GetNumSets() const
{
    return static_cast<int>(mSets.size());
}

int BITSET::GetSet(int which_set) const
{
    if (which_set < GetNumSets())
    {
        return mSets.at(which_set);
    }
    else
    {
        return 0;
    }
}
// Now the code iws fwinished awnd cweaws aww the test cases! >_< :3
