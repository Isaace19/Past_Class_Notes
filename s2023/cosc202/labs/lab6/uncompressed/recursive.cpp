/*Name: Sully Varnadoe
 *NetID: svarnad1
 *Program: Lab 6
 *Summary: This program will take with N terms and compute the required integer operators make the 0 - N-1 terms eqaul to the Nth value.
		   
		   The values can be computed in any permutations and also all possible solutions. Aditionally it can output the actal equation
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>

using namespace std;

bool success = false;
bool findall = false;
bool verbose = false;

void show_solution(vector<int>& numbers, vector<int>& operations) {
    if (verbose) {//outputs full equation
	    for (size_t i = 0; i < numbers.size(); ++i) {
		    cout << numbers[i];
	        if (i < numbers.size() - 1) {// operations are reprsented as ints 1 = +, 2 = -, 3 = *, and 4 = /
			    int op = operations[i];
		        switch (op) {
	                case 1: 
						cout << '+';
						break;
	                case 2: 
						cout << '-';
						break;
	                case 3: 
						cout << '*';
						break;
	                case 4: 
						cout << '/';
						break;
	                default:
						cout << '=';
						break;
			    }
		    }
	    } cout << ' ';
	}	
	
	for (size_t i = 0; i < numbers.size(); ++i) {//outputs only operations
        if (i < numbers.size() - 1) {
            int op = operations[i];
            switch (op) {
                case 1: 
					cout << '+';
					break;
                case 2: 
					cout << '-';
					break;
                case 3: 
					cout << '*';
					break;
                case 4: 
					cout << '/';
					break;
                default:
					break;
            }
        }
    } cout << endl;
}

bool find_solution(vector<int>& numbers, vector<int>& operations, int k = 0, int fvalue = 0) {
	if (k  == numbers.size() - 2) {//check if it is at the last COMPUTABLE value
        if (fvalue == numbers.back()) {//check if the value is correct and return accordingly
			show_solution(numbers, operations);
            success = true;
            return !findall;
        }
        return false;
    }

    bool found = false;

	if(k == 0) fvalue += numbers[0];//on the first loop our current value needs to be equal to N[0]

    for (int op = 1; op <= 4; ++op) {
        operations[k] = op;
		int temp_fvalue = fvalue;

        switch (op) {
            case 1:
				temp_fvalue += numbers[k+1];// +
				break;
            case 2:
				temp_fvalue -= numbers[k+1];// -
				break;
            case 3:
				temp_fvalue *= numbers[k+1];// *
				break;
            case 4:
                if (numbers[k] != 0) {// /
                    temp_fvalue /= numbers[k+1];
                }
                break;
            default:
				break;
        }

        if (find_solution(numbers, operations, k + 1, temp_fvalue)) {
			found = true;
		}
		
		if (found && !findall) {
            return true;
        }
    }

    return found;
}


int main(int argc, char* argv[]) {	
	if (argc < 3 || 4 < argc || (string(argv[1]) != "-inorder" && string(argv[1]) != "-anyorder") || (string(argv[2]) != "-2" && string(argv[2]) != "-1")) {
        cerr << "usage: ./Prog6 -inorder|anyorder -1|2 [-verbose] < numbers.txt" << endl;
        return 1;
    }//error checking

    if (atoi(argv[2]) == -2) {
        findall = true;
    }

    if (argc == 4 && string(argv[3]) == "-verbose") {
        verbose = true;
    }

	vector<int> numbers;
    int num;

	while (cin >> num) {
        numbers.push_back(num);
    }

    vector<int> operations(numbers.size() - 1, 0);

	if (string(argv[1]) == "-inorder") {
        find_solution(numbers, operations);
    } else {// == "-anyorder"
		sort(numbers.begin(), numbers.end()-1);
        do {
            find_solution(numbers, operations);
        } while (next_permutation(numbers.begin(), numbers.end()-1));//while there is another permutation of computable terms loop
    }

    if (!success) {
        return 1;
	}//error checking for no solution

    return 0;
}
