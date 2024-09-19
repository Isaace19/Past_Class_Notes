/*Recursion is when a functionc alls itself, but we can think about this in terms of a porblem solving itself too*/

/*Components:

  -Base case - i.e. when to stop
  -Work Towards a sllution
  -Recursive Call 0 i.e. wen the function calls itself.

  The components don't have to be in this order, but having a recusrive call at the end is
  called "Tail recusrion"
 */


/*Factoral -> 5! = 5 * 4 * 3* 2 * 1*/



#include <iostream>


using namespace std;

int factorial(int n);


int main(){
  int number;

  cout << "Enter a Posistive Integer: ";
  cin >> number;
  cout << "The Factorial of " << number << " = " << factorial(number) << endl;
}

/*You can define the code below the main file; this is something tha you can do in C++
 */

int factorial(int n){
  if(n > 1){
    // The work towards the solution is "n"
    // and we see our recursive call
    return n * factorial(n-1);
  }else{
    // OUr base case
    return 1;
  }
}
