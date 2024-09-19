#include <iostream>
#include <vector>

using namespace std;

void bubbleSort (vector <int> &v) {
	for (int it = 0; it < v.size(); it++) {
		if (v[it] > v[it+1]) {
			int temp = v[it];
			v[it] = v[it+1];
			v[it+1] = temp;
		}
	}
}

int main () {
	vector <int> v = {5, 1, 4, 2, 8};
	bubbleSort(v);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}
