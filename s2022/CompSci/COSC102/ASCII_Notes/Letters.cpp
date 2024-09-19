#include <iostream>

using namespace std;

// Now we ant to create a function that converts case values of a letter

char toCharConversion(char letter)
{
    // Convert to upercase regardless of the current casing

    // IN CLASS CRUMPTON SOLUTION
    char returnLetter;
    const char Mask = 0b01011111; // This will be our flipper case, how would we convert to an upper case letter regardless of case?
    return letter & '_';
    // make a binary mask int that has a 1 on bit in a posotion

    // 0010_0000 = 32, and 32 stand for "SP" in ASCII

    // 01100001 is the binary for a
    // 01100010 is the binary for b
    // 01100011 is the binary for c
    // 01100100 is the binary for d

    // so it seems that the first 3 digits are what I want to compare and the rest I can mask.
}

char myConversionSolution(char letter)
{
    char returnMySolution;
    const char Masker = 0b00100000;
    if (letter >= 'a' && letter <= 'z')
    {
        return letter & ~Masker;
    }
    else if (letter >= 'A' && letter <= 'Z')
    {
        return letter | Masker;
    }
    else
    {
        return letter;
    }
}

int main()
{
    char inputChar;
    cout << "Enter a char value: ";
    cin >> inputChar;
    char letter = inputChar;
    char outputChar;

    outputChar = toCharConversion(letter);

    cout << outputChar << "\n";

    return 0;

    // a    = 0110_0001
    // A    = 0100_0001
    // mask = 0010_0001

    // b = 0110_0010
    // B = 0100_0010
}
