#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

// here I want to create some structures for the data of the suits, value, and card
enum class Rank
{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};
enum class Suit // Spades, Clubs, etc...
{
    HEARTS,
    DIAMONDS,
    SPADES,
    CLUBS,
};

struct CardAtttributes
{
    int value;
    Rank rank;
    Suit suit;

    void BufferPrint()
    {
        OutputRank();

        cout << " of ";

        OutputSuits();

        cout << endl;
    }

    void OutputRank()
    {
        if (rank == Rank::JACK)
        {
            cout << "Jack";
        }
        if (rank == Rank::QUEEN)
        {
            cout << "Queen";
        }
        if (rank == Rank::KING)
        {
            cout << "King";
        }
        if (rank == Rank::ACE)
        {
            cout << "Ace";
        }
        else
        {
            cout << value;
        }
    }

    void OutputSuits()
    {
        if (suit == Suit::CLUBS)
        {
            cout << "Clubs";
        }
        if (suit == Suit::HEARTS)
        {
            cout << "Hearts";
        }
        if (suit == Suit::SPADES)
        {
            cout << "Spades";
        }
        if (suit == Suit::DIAMONDS)
        {
            cout << "Diamonds";
        }
    }
};

struct CardMaker
{
    CardAtttributes Card[52];

    // Now we need to return this into the main function with a void return
    // This will output every combination of cards

    void Printing()
    {
        for (int COLUMNS = (int)Suit::HEARTS; COLUMNS <= (int)Suit::CLUBS; COLUMNS++)
        {
            for (int ROWS = (int)Rank::ACE; ROWS <= (int)Rank::KING; ROWS++)
            {
                int index = (13 * COLUMNS) + ROWS - 1;
                Card[index].BufferPrint();
            }
            cout << endl;
        }
    }
    void OutputCards()
    {
        for (int COLUMNS = (int)Suit::HEARTS; COLUMNS <= (int)Suit::CLUBS; COLUMNS++)
        {
            for (int ROWS = (int)Rank::ACE; ROWS <= (int)Rank::KING; ROWS++)
            {
                CardAtttributes Cards;
                Cards.suit = (Suit)COLUMNS;
                Cards.rank = (Rank)ROWS;

                if (Cards.rank == Rank::JACK)
                {
                    Cards.value = 10;
                }
                else if (Cards.rank == Rank::QUEEN)
                {
                    Cards.value = 10;
                }
                else if (Cards.rank == Rank::KING)
                {
                    Cards.value = 10;
                }
                else
                {
                    Cards.value = (int)Cards.rank;
                }

                //  cout << (int)Cards.rank << " of " << (int)Cards.suit << endl;

                int index = (13 * COLUMNS) + ROWS - 1;
                Card[index] = Cards;
            }
        }
    }
};

int GetRandom(int min, int max)
{
    int random = (min + rand() % (max - min + 1));
    return random;
}

vector<int> DealingHands(CardMaker)
{
    CardMaker deck;

    vector<int> DealerHand(2);
    vector<int> PlayerHand(2);

    int Randomizer = GetRandom(0, deck - 1);
}

int main()
{
    cout << "WELCOME TO BLACKJACK" << endl;
}