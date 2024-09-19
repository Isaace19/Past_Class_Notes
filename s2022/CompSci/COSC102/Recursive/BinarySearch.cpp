/* Searching */
/* We are going to cover two searching algorithms. By searching, I mean seeing if
an element exists
in a data structure and locating said element.
As for the data structure, we are only considering an array or a vector
(the only two data structures we know so far).
*/
/* Linear search */
/* Linear search sequentially checks each element of the vector/array until a match
is found or
the whole vector/array has been searched.
In the worst case, we would have to check all 'n' elements of the vector/array,
where 'n' is the
size of the vector/array.
Linear search is honestly just a fancy way of saying "for loop".
In the code snippet below, we are holding data in the array, passing the size
of the array as
'n', and the element we want to locate in the array is 'x'.
int search(int arr[], int n, int x)
{
for (int i = 0; i < n; i++)
if (arr[i] == x)
return i;
return -1;
}
*/
/* Binary search */
/* Binary search is a faster way of finding an element in a list-like data
structure,
BUT the array/vector must be sorted first.
With binary search, we search a sorted array by repeatedly dividing the search
interval in half.
For example, let's say we have the following array:
1 3 4 6 8 11 15 20 21 200
And we want to search for 6.
Since the array is size 10, the "middle" of the array is index 4/5.
I'll use the lower of the two for the "middle" if we have an even length.
array[4] = 8 so I know that I can eliminate the top half of the whole vector.
So now I'm searching through
1 3 4 6
and the middle is sub-array[1] = 3.
I know I can eliminate the bottom half of this sub-array.
Now I'm searching through
4 6
and the middle is sub-sub-array[0] = 4.
I know I can eliminate the bottom half of this sub-sub-array, which only leaves
me with one element left.
I still need to check that element (what if it's 7?) just to make sure the
element
exists in the array at all.
It is 6, so we found it!
Notice this was the worst case scenario, but we only did 4 checks for an array
of size 10.
In the worst case scenario of linear search, we would do 10 checks.
HOWEVER, we must know the array is sorted! And that can take time too if it's
not already.
We can implement binary sort both iteratively (think: loop) OR recursively.
Work with a partner on the coding the *recursive* version.
Submit for today's participation grade - you must have recursive solution
attempt to receive credit.
Correct implementation will receive extra credit.
Below is the implementation of the iterative way to help.
*/
/* Implementation of iterative Binary Search */

#include <iostream>
#include <vector>
using namespace std;
/* Binary search function that returns the
location of x in given a vector arr[l..r] if present,
otherwise -1
*/
int binarySearch(vector<int> arr, int x, int l, int r)
{
    l = 0;
    r = arr.size() - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        // Check if x is present at midpoint
        if (arr[m] == x)
	  
            return m;
        // If x greater, ignore left half of vector
        if (arr[m] < x)
            l = m + 1;
	    binarySearch(arr, x, l, r);
        // If x is smaller, ignore right half of vector
        if(arr[m] > x){
	   r = m - 1;
	   binarySearch(arr, x, l, r);
	}
         
    }
    /* Element was not in the vector. */
    return -1;

}
/* Driver code - use C++11 to compile */
int main(void)
{
    vector<int> data = {2, 3, 4, 10, 40}; // Remember this line requires C++11
    int x = 10;

    /* Hint: to make it recursive, adding parameters... specifically 2
    parameters... will help. */
    int result = binarySearch(data, x, 0, data.size() - 1);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    cout << endl;
    return 0;
}

