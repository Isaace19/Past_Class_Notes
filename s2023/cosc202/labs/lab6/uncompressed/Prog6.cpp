/*
Author: Isaac Abella
Description: Recursive solver implementation given a text file of numbers.

Calculations all possible permutations of 0 -N-1 equal to the nth term

there are two different viewing outputs, either all possible permutations or all solutions find_answer
Both can be outputted with the equation that was solved as terminal text
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool success = false;
bool findall = false;
bool verbose = false;

void show_solution(vector<int> &numbers, vector<int> &operations)
{
    // check to see if true, than print out the full equation

    // 1 is for addition, 2 is subtraction, 3 is multiplication, and 4 is division.
    if (verbose)
    {
        for (size_t i = 0; i < numbers.size(); ++i)
        {
            cout << numbers[i];
            if (i < numbers.size() - 1)
            {
                // create int to store the current increment, than use it to output the proper symbol
                int op = operations[i];
                if (op == 1)
                {
                    cout << '+';
                }
                else if (op == 2)
                {
                    cout << '-';
                }
                else if (op == 3)
                {
                    cout << '*';
                }
                else if (op == 4)
                {
                    cout << '/';
                }
                else
                {
                    cout << '=';
                }
            }
        }
        cout << ' ';
    }
    // if verbose is not true, than just output the operations and continue;
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        if (i < numbers.size() - 1)
        {
            int op = operations[i];
            if (op == 1)
            {
                cout << '+';
            }
            else if (op == 2)
            {
                cout << '-';
            }
            else if (op == 3)
            {
                cout << '*';
            }
            else if (op == 4)
            {
                cout << '/';
            }
        }
    }
    cout << endl;
}

bool find_solution(vector<int> &numbers, vector<int> &operations, int k = 0, int fvalue = 0)
{

    /*
    general instruction: we have to subtract two from the size because we have to look at the value we can actually use.
    Than it has to verify and check that this matches with fvalue and the last number in the numbers vector
    */
    if (k == numbers.size() - 2)
    {
        if (fvalue == numbers.back())
        {
            show_solution(numbers, operations);
            success = true;
            if (!findall)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return false;
    }
    bool find_answer = false;

    // check to see if the first loop through is 0, if so we just want to actually set it to the first data stored in numbers vector
    if (k == 0)
    {
        fvalue += numbers[0];
    }

    /*
    function to temporarily store the result of applying an operation to the current value (fvalue)
    and the next number in the sequence (numbers[k+1]).

    use of holder allows for the function to explore all possible combinations
    */

    for (int op = 1; op <= 4; ++op)
    {
        operations[k] = op;
        int holder = fvalue;
        switch (op)
        {
        case 1:
            holder += numbers[k + 1];
            break;
        case 2:
            holder -= numbers[k + 1];
            break;
        case 3:
            holder *= numbers[k + 1];
            break;
        case 4:
            if (numbers[k] != 0)
            {
                holder /= numbers[k + 1];
            }
            break;
        default:
            break;
        }

        /*
        if the current calculation from the above case statements in k +1 matches a holder value
        than we can flag it as true to our answer,

        than we check check the first two if statements, if we only find a match true value than we have not
        find_answer; all possible permutations and must keep searching.
        */

        if (find_solution(numbers, operations, k + 1, holder))
        {
            find_answer = true;
        }

        if (find_answer && !findall)
        {
            return true;
        }
    }

    return find_answer;
}

int main(int argc, char *argv[])
{
    if (argc < 3 || argc > 4 || (strcmp(argv[1], "-inorder") != 0 && strcmp(argv[1], "-anyorder") != 0) || (strcmp(argv[2], "-2") != 0 && strcmp(argv[2], "-1") != 0))
    {
        cerr << "usage: ./Prog6 -inorder|anyorder -1|2 [-verbose] < numbers.txt" << endl;
        return 1;
    }

    if (atoi(argv[2]) == -2)
    {
        findall = true;
    }

    if (argc == 4 && strcmp(argv[3], "-verbose") == 0)
    {
        verbose = true;
    }

    /*
    after grabbing txt file and putting into the numbers vector, we want to create an operations vector
    contains the size of numbers -1 and just empty values.

    sort in ascending value -1 because the target value cannot be touched or used
    do while loop will call possible permutations until outputting
    */

    vector<int> numbers;
    int num;

    while (cin >> num)
    {
        numbers.push_back(num);
    }

    vector<int> operations(numbers.size() - 1, 0);

    if (strcmp(argv[1], "-inorder") == 0)
    {
        find_solution(numbers, operations);
    }
    else
    {
        sort(numbers.begin(), numbers.end() - 1);
        do
        {
            find_solution(numbers, operations);
        } while (next_permutation(numbers.begin(), numbers.end() - 1));
    }

    if (!success)
    {
        return 1;
    }

    return 0;
}