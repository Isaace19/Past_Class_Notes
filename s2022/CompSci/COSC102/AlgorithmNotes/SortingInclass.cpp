#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void BubbleBort(vector<int> &v)
{
    bool swapp = true;
    while (swapp)
    {
        for (int ik = 0; ik < v.size(); ik++)
        {
            for (int it = 0; it < v.size() - 1; it++)
            {
                if (v[it] > v[it + 1])
                {
                    swap(v[it], v[it + 1]);
                }
                else
                {
                    swapp = false;
                    cout << v[it] << endl;
                }
            }
        }
    }

    return;
}

int main()
{
    vector<int> v = {5, 1, 4, 2, 8};

    BubbleBort(v);
    // CODE A BUBBLE SORT ALOGIRTHM
}
