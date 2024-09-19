#ifndef SUPPPORT_H
#define SUPPPORT_H

#include <set>

using namespace std;

extern bool is_forward;
extern bool is_verbose;

class prime_partition
{
public:
  prime_partition();
  void find_partition(int);
  void print_partition();

private:
  void expand_pset(int number);
  bool is_valid(int number, int terms);
  bool find_partition(int number, int terms);

  // pset and other data members
  set<int> pset;
  int partition[3];
};

#endif
