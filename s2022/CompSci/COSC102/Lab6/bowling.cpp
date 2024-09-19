/*
Program Name: bowling.cpp
Student name: Isaac Abella
Net ID: iabella
Student ID: 000641840
Program Description - This program will ask the user for an amount of
players who want to play bowling than calculate their scores per frame
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// I changed the function from total rolls of 21 to a 2d vector of 10 frams with 3 rolls (only the 10th frame will use all 3)
vector<vector<int>> get_player_rolls()
{
    vector<int> NUMBER_OF_FRAMES(10);
    vector<int> ROLLS_PER_FRAME(3);

    const size_t TOTAL_FRAMES = 10;                // 10 frams with 2 rolls each, frame 10 contains 3 rolls
    vector<vector<int>> rolls(10, vector<int>(3)); // (size, value)

    // input first 20 rolls
    for (size_t frame = 0; frame < NUMBER_OF_FRAMES.size(); ++frame)
    {
        for (size_t roll = 0; roll < ROLLS_PER_FRAME.size(); ++roll)
        {
            // If statement checks for the first value of the first 9 rolls

            if (rolls[frame][0] + rolls[frame][1] < 10 && roll < 2)
            {
                cout << "Enter a score for frame " << frame + 1 << ", roll " << roll + 1 << ":" << endl;
                cin >> rolls[frame][roll];
            } // Now it will switch when we get to the 10th frame
            else if (frame == 9 && ((rolls[frame][0] + rolls[frame][1] > 9 && roll == 2) || roll == 1))
            {
                cout << "Enter a score for frame " << frame + 1 << ", roll " << roll + 1 << ":" << endl;
                cin >> rolls[frame][roll];
            }
            else
            {
                rolls[frame][roll] = 0;
            }
        }
    }
    return rolls;
}

int get_player_score(const vector<vector<int>> &rolls)
{
    int round_score = 0;
    vector<int> NUMBER_OF_FRAMES(10);
    int NUMBER_OF_PINS = 10;

    for (size_t frame_number = 0; frame_number < NUMBER_OF_FRAMES.size() - 1; ++frame_number)
    {
        // Strike calculation
        if (rolls[frame_number][0] == NUMBER_OF_PINS)
        {
            if (rolls[frame_number + 1][0] < NUMBER_OF_FRAMES.size()) // if not the 10th frame
            {
                round_score += NUMBER_OF_PINS + rolls[frame_number + 1][0] + rolls[frame_number + 1][1];
            }
            else if (frame_number < 8)
            {
                round_score += (NUMBER_OF_PINS * 2) + rolls[frame_number + 2][0];
            }
            else
            {
                round_score += (NUMBER_OF_PINS * 2) + rolls[frame_number + 1][1];
            }
        }
        // Spares calculations
        else if (rolls[frame_number][0] + rolls[frame_number][1] == NUMBER_OF_PINS)
        {
            round_score += NUMBER_OF_PINS + rolls[frame_number + 1][0];
        }
        else
        {
            round_score += rolls[frame_number][0] + rolls[frame_number][1];
        }
    }
    // The score for the 10th frame taking all 3 rolls
    round_score += rolls[9][0] + rolls[9][1] + rolls[9][2];
    return round_score;
}

void print_game_summary(const vector<string> &player_names, const vector<int> &player_scores)
{
    if (player_names.size() == 0)
    {
        cout << "No players were entered." << endl;
        return;
    }
    else
    {
        cout << endl;

        string worst_player_name = player_names[0];
        int worst_player_score = player_scores[0];

        string best_player_name = player_names[0];
        int best_player_score = player_scores[0];

        for (size_t i = 0; i < player_names.size(); i++)
        {
            cout << player_names[i] << " scored " << player_scores[i] << "." << endl;
            // The statement above will print out the scores as is, the below code will calculate who did the worst/best
            if (player_scores[i] > best_player_score)
            {
                best_player_score = player_scores[i];
                best_player_name = player_names[i];
            }
            else if (player_scores[i] < worst_player_score)
            {
                worst_player_score = player_scores[i];
                worst_player_name = player_names[i];
            }
        }
        cout << worst_player_name << " did the worst by scoring " << worst_player_score << endl;
        cout << best_player_name << " did the best by scoring " << best_player_score << endl;
    }
}

int main()
{
    string input_string;
    vector<string> player_names(0);
    vector<int> player_scores;

    while (true)
    {
        cout << "Enter player's name (done for no more players): ";
        cin >> input_string;
        player_names.push_back(input_string);

        if (input_string == "done")
        {
            break;
        }

        // Scoring Calculations from the functions above.
        // Changed to a double vector const.
        const vector<vector<int>> player_rolls = get_player_rolls();

        const string player_names = input_string;
        const size_t round_score = get_player_score(player_rolls);
        player_scores.push_back(round_score);
    }
    player_names.resize(player_names.size() - 1);
    print_game_summary(player_names, player_scores);

    return 0;
}
