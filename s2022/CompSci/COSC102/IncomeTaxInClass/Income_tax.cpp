#include <vector>
#include <iostream>

using namespace std;

int main()
{
    string player1, player2;
    int strokes;
    int playerNum;

    vector<int> player1holes, player2holes;

    const int SHORT_GAME = 3;

    // Asking for Player name for player 1
    cout << "Welcome to Mini-Golf Scoring! " << endl;
    cout << "Player 1, what is your name? ";
    cin >> player1;

    // Asking for player name for player 2

    cout << "Player 2, what is your name? ";
    cin >> player2;

    for (int i = 0; i < SHORT_GAME; i++)
    {
        cout << "What was " << player1 << " 's score for hole " << i << "?";
        cin >> strokes;
        player1holes.push_back(strokes);

        cout << "What was " << player2 << " 's score for hole " << i << "?";
        cin >> strokes;
        player2holes.push_back(strokes);
    }

    for (int i = 0; i < player1holes.size(); i++)
    {
        cout << " Hole" << i << " score " << player1holes[i] << endl;
    }
}