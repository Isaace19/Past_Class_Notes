/* Program Name: Bowling
 * Student Name: Charlie Shin
 * Net ID: cshin2
 * Student ID: 000-63-2652
 * Program Description: This program finds players' total scores from input
 * scores for each roll in a game of bowling. */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> names(0);
vector<int> tScores;
string dummy;
int sMax, sMin, tScore;

int main()
{
    // Prompt player names
    cout << "Enter player's name (done for no more players): ";
    cin >> dummy;
    names.push_back(dummy);
    getline(cin, dummy);

    while (names[names.size() - 1] != "done")
    {
        // Prompt for frames
        vector<vector<int>> frames(10, vector<int>(3));
        for (size_t i = 0; i < 10; i++)
        {
            for (size_t k = 0; k < 3; k++)
            {
                if (frames[i][0] + frames[i][1] < 10 && k < 2)
                {
                    cout << "Enter score for frame " << i + 1 << ", roll " << k + 1
                         << ": ";
                    cin >> frames[i][k];
                    getline(cin, dummy);
                }
                else if (i == 9 && ((frames[i][0] + frames[i][1] > 9 && k == 2) || k == 1))
                {
                    cout << "Enter score for frame " << i + 1 << ", roll " << k + 1
                         << ": ";
                    cin >> frames[i][k];
                    getline(cin, dummy);
                }
                else
                {
                    frames[i][k] = 0;
                }
            }
        }
        // Determine scores
        tScore = 0;
        for (size_t i = 0; i < 9; i++)
        {
            // Strikes
            if (frames[i][0] == 10)
            {
                if (frames[i + 1][0] < 10)
                {
                    tScore += 10 + frames[i + 1][0] + frames[i + 1][1];
                }
                else if (i < 8)
                {
                    tScore += 20 + frames[i + 2][0];
                }
                else
                {
                    tScore += 20 + frames[i + 1][1];
                }
            }
            // Spares
            else if (frames[i][0] + frames[i][1] == 10)
            {
                tScore += 10 + frames[i + 1][0];
            }
            // Massive L
            else
            {
                tScore += frames[i][0] + frames[i][1];
            }
        }
        tScore += frames[9][0] + frames[9][1] + frames[9][2];

        // Save score
        tScores.push_back(tScore);

        // Reprompt player name
        cout << "Enter player's name (done for no more players): ";
        cin >> dummy;
        names.push_back(dummy);
        getline(cin, dummy);
    }

    names.resize(names.size() - 1);
    if (names.size() == 0)
    {
        cout << "No players were entered.\n";
        return 0;
    }
    else
    {
        cout << "\n";
        // Determine max and min scores
        sMax = 0;
        sMin = 0;
        for (size_t i = 0; i < names.size(); i++)
        {
            // Output scores
            cout << names[i] << " scored " << tScores[i] << ".\n";
            if (tScores[i] > tScores[sMax])
            {
                sMax = i;
            }
            else if (tScores[i] < tScores[sMin])
            {
                sMin = i;
            }
        }
        // Output max and min scores
        cout << names[sMin] << " did the worst by scoring " << tScores[sMin]
             << ".\n"
             << names[sMax] << " won the game by scoring " << tScores[sMax]
             << ".\n";
    }
}