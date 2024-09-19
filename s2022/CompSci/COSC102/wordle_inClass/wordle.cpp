#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cerr << "usage: ./world guessFile and solutionsFile" << endl;
        return 1;
    }
    string guessesFile, answersFile;
    guessesFile = argv[1];
    answersFile = argv[2];

    /*Here is where we will read in the Guesses File*/
    ifstream fin;
    fin.open(guessesFile);
    if (!fin.is_open())
    {
        cerr << "Guesses file failed to open." << endl;
        return 1;
    }
    vector<string> validGuesses;
    string word;
    while (fin >> word)
    {
        validGuesses.push_back(word);
        // cout << word;
    }
    fin.close();

    /**/
    vector<string> validAsnwers;
    fin.open(answersFile);
    if (!fin.is_open())
    {
        cerr << "Ansers file failed to open." << endl;
        return 1;
    }
    vector<string> validAnswers;
    while (fin >> word)
    {
        validAnswers.push_back(word);
        // cout << word;
    }

    /*Input data done here*/
    // Now pick the word of the day
    srand(1);
    srand(time(NULL));
    int randomNum = rand() % validAnswers.size();
    cout << randomNum << endl;

    string todaysWord = validAnswers[randomNum];
    cout << todaysWord << endl;

    int n = 6;
    string printword = "-----";
    string guess;

    cout << "Welcome to Wordle!" << endl;
    cout << "You have " << n << " guesses remaining." << endl;
    cout << printword << endl;

    cin >> guess;
    if (guess.size() != 5)
    {
        cout << "5 letter wrods only, Now Guess: ";
        cin >> guess;
    }
    if (guess == todaysWord)
    {
        cout << "WINNER WINNER" << endl;
        return 0;
    }
    /*Is this word allowed to be guesse? */
    bool found = false;
    // For loop through valid guesses
    // if guess is equal to validGuesses[it] set flag
}