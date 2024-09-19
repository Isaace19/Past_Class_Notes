#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
class VigenereCipher
{
private:
    string key;
    char vTable[26][26];
    string fileToString(string fileName);
    void stringToFile(string s, string outputFileName);
    string makeKeystream(string msg);

public:
    VigenereCipher(string k);
    void encrypt(string inputFile, string outputFile);
    void decrypt(string inputFilename, string outputFilename);
    void printVTable();
};
string VigenereCipher::fileToString(string fileName)
{
    ifstream fin(fileName);
    string message;
    char character;
    if (!fin.is_open())
    {
        cerr << "file " << fileName << " unable to open." << endl;
        exit(1);
    }
    while (fin.get(character))
    {
        message.push_back(character);
    }
    fin.close();
    return message;
}
void VigenereCipher::stringToFile(string s, string outputFileName)
{
    ofstream fout(outputFileName);
    if (!fout.is_open())
    {
        cerr << "output file " << outputFileName << " unable to open." << endl;
        exit(1);
    }
    fout << s;
    fout.close();
}
string VigenereCipher::makeKeystream(string msg)
{
    // This here is taking the key and then matching it to the length of msg
    // Then it should be able to just
    string keystream;
    for (int i = 0; i < msg.size(); i++)
    {
        keystream.push_back(key[i % key.size()]);
    }
    return keystream;
}
VigenereCipher::VigenereCipher(string k)
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            vTable[i][j] = ((i + j) % 26) + 'A';
        }
    }
}
void VigenereCipher::encrypt(string inputFile, string outputFile)
{
    string message = fileToString(inputFile);
    string keystream = makeKeystream(message);
    string cipheredText;

    for (int i = 0; i < message.size(); i++)
    {
        int asciiValue = message[i];

        // If the current character is a letter, adjust the ASCII value to be in range [0, 25]
        if (isupper(message[i]))
        {
            asciiValue = toupper(message[i]) - 'A';
        }
        else
        {
            cipheredText.push_back(message[i]);
            continue;
        }

        int keyAsciiValue = toupper(key[i]) - 'A';

        // Calculate the shifted ASCII value using the Vigenere table
        char shiftedAsciiValue = vTable[asciiValue][keyAsciiValue];
        cipheredText.push_back(shiftedAsciiValue);
    }
    stringToFile(cipheredText, outputFile);
}
void VigenereCipher::decrypt(string inputFile, string outputFile)
{
    string cipheredText = fileToString(inputFile);
    string key = makeKeystream(cipheredText);

    // Decrypt ciphered text with Vigenere cipher
    string message;
    for (int i = 0; i < cipheredText.size(); i++)
    {
        int asciiValue = cipheredText[i];

        if (isalpha(cipheredText[i]))
        {
            asciiValue = toupper(cipheredText[i]) - 'A';
        }
        else
        {
            // If the current character is not a letter, leave it as is
            message.push_back(cipheredText[i]);
            continue;
        }

        int keyAsciiValue = toupper(key[i]) - 'A';

        // Find the index of the row in the Vigenere table corresponding to the current key character
        int rowIndex = keyAsciiValue;

        int colIndex = -1;
        for (int j = 0; j < 26; j++)
        {
            if (vTable[rowIndex][j] == toupper(cipheredText[i]))
            {
                colIndex = j;
                break;
            }
        }

        char unshiftedAsciiValue = colIndex + 'A';
        message.push_back(unshiftedAsciiValue);
    }

    stringToFile(message, outputFile);
}
void VigenereCipher::printVTable()
// Just a table print out of our vipher table
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            cout << " " << vTable[i][j] << " ";
        }
        cout << endl;
    }
}
int main(int argc, char **argv)
{
    VigenereCipher v("Lemon");
}
