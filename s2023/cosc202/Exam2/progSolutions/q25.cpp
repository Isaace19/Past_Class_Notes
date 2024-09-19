#include <iostream>

typedef unsigned int uint;

bool magic5(uint v0, uint v1=0, uint v2=1) {
  if (v0 == v1) return true;
  if (v0 < v2) return false;

  return magic5(v0, v2, v1+v2);
}

int main(){
    uint v0 = 25;

    std::cout << magic5(v0) << '\n';
}
