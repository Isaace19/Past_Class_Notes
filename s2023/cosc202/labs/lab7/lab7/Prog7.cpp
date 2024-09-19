#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

#include "bst.h"

template <typename Iterator>
void print_forward(Iterator i0, Iterator i1) {
  while (i0 != i1) {
    cout << " " << setw(3) << *i0;
    ++i0;
  }
  cout << "\n";
}

template <typename Iterator>
void print_reverse(Iterator i0, Iterator i1) {
  while (i0 != i1) {
    cout << " " << setw(3) << *i0;
    --i0;
  }
  cout << "\n";
}

typedef int data_t;

int main(int argc, char *argv[]) {
  int mode = 0;
  bool argv_is_OK = true;
  bool verbose = false;

  if (argc < 3 || 4 < argc) {
    argv_is_OK = false;
  } else {
	if (argv[1][0] == '-')
	  mode = argv[1][1]-'0';

    if (mode < 1 || 4 < mode)
      argv_is_OK = false;

    if (argc == 4) {
      if (strcmp(argv[2], "-verbose") == 0)
        verbose = true;
	  else
        argv_is_OK = false;
	}
  }

  if (argv_is_OK == false) {
    cerr << "usage: " << argv[0]
	     << " -1|2|3|4 [-verbose] data.txt\n";
    return 1;
  }

  data_t key;
  bst<data_t> T;

  ifstream fin(argv[argc-1]);

  while (fin >> key)
    T.insert(key);

  fin.close();

  if (T.empty())
    return 0;

  if (mode == 1) {
    T.print_bylevel();
	return 0;
  }

  if (mode < 4) 
    print_forward(T.begin(), T.end());

  if (mode == 2) 
    return 0;

  if (mode == 4)
    print_reverse(T.rbegin(), T.rend());

  data_t key0, key1;
  bst<data_t>::iterator p0, p1;

  while (1) {
    cout << "\n"
         << "Print [key0:key1] ";
    cin >> key0 >> key1; 

    if (cin.eof()) {
	  cout << "\n";
      break;
	}

    if (key1 < key0)
      continue;

    p0 = T.lower_bound(key0);
    p1 = T.upper_bound(key1);

	if (verbose) {
      cout << "*** lower bound ";
      if (p0 != T.end()) cout << *p0;
      else               cout << "NA";
      cout << "\n";
    
      cout << "*** upper bound ";
      if (p1 != T.end()) cout << *p1;
      else               cout << "NA";
      cout << "\n";
	}

	if (p0 == p1 || p0 == T.end())
	  ;
	else
	if (mode == 3)
      print_forward(p0, p1);
	else
	if (mode == 4) {
	  if (p1 != T.end()) {
	    --p0;
		--p1;
      } else {
		--p0;
		p1 = T.rbegin();
	  }
	  print_reverse(p1, p0);
	}
  }
}
