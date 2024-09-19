int get_player_score(const vector<int> &rolls)
{
    int round_score = 0;
    vector<int> NUMBER_OF_FRAMES(10);

    for (size_t frame_number = 0; frame_number < NUMBER_OF_FRAMES.size() - 1; ++frame_number)
    {
        if (rolls[frame_number][0] == 10)
        {
            if (rolls[frame_number + 1][0] < 10)
            {
                round_score += 10 + rolls[frame_number + 1][0] + rolls[frame_number + 1][1];
            }
            else if (frame_number < 8)
            {
                round_score += 20 + rolls[frame_number + 2][0];
            }
            else
            {
                round_score += 20 + rolls[frame_number + 1][1];
            }
        }
        else if (rolls[frame_number][0] + rolls[frame_number][1] == 10)
        {
            round_score += 10 + rolls[frame_number + 1][0];
        }
        else
        {
            round_score += rolls[frame_number][0] + rolls[frame_number][1];
        }
    }
    round_score += rolls[9][0] + rolls[9][1] + rolls[9][2];

    return round_score;
}