// John Cordwell III
// This program tests the goldbach conjecture (sum of three primes)
#include <iostream>
#include <set>

#include "Support.h"

using namespace std;

bool is_forward = false;
bool is_verbose = false;

int main(int argc, char *argv[])
{
  prime_partition goldbach;

  if (argc < 2 || argc > 3) // bad or missing arguments
  {
    cerr << "usage: ./Prog8 -forward|reverse [-verbose]" << endl;
    return 1;
  }

  string forward = argv[1];
  // string verbose = argv[2];

  /*if (verbose == "-verbose")
    is_verbose = true;
  else if (argv[2] && verbose != "-verbose")
  {
    cerr << "usage: ./Prog8 -forward|reverse [-verbose]\n";
    return 1;
  } */ 

  if (forward == "-forward")
    is_forward = true;
  else if (forward == "-reverse")
    is_forward = false;
  else
  {
    cerr << "usage: ./Prog8 -forward|reverse [-verbose]\n";
    return 1;
  }

  while (1)
  {
    int input;
    cout << "number = "; // stdin: prompt for number
    cin >> input;

    if (cin.fail()) // check for end-of-file
	{
	  cout << endl;
      return 0;
    }

    if (input < 6) // check number is not too small
    {
      cout << "Too small. Try again.\n";
      continue; // restart the while loop
    }

    goldbach.find_partition(input);
  }

  return 0;
}
