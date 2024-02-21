#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H
#include <iostream>
 
using namespace std;
 
 //Function decleration
void _array_init(int a[], int size, int x=0);
 //Precondition: There's a integer array and a int
 //          variable that holds the size of the array
 //Postcondition: It fills the array with 0s or a given
 //          number

void _append(int a[], int& size, int append_me);
 //Precondition: There's a integer array, a int
 //     variable that holds the size of the array, and
 //     append_me is a integer
 //Postcondition: append_me will be added to the end of
 //     the array and the variable for size will increase 1

int _find(const int a[], int size, int find_me);
 //Precondition: The 'a' array is an int array and
 //     "size" variable tells the size of the 'a' array.
 //     "find_me" tells what integer you want to look for
 //     in the array.
 //Postcondition: Returns the index of the 'a' array where
 //     "find_me" value was located

int& _at(int a[], int size, int pos);
 //Precondition: The 'a' array is an int array and
 //     "size" variable tells the size of the 'a' array. "pos"
 //     tells the index of the array you want to access
 //Postcondition: Returns the arrdess of the array at index "pos"
 //

ostream& _print_array(const int a[], int size, ostream& outs = cout);
 //Precondition: The 'a' array is an int array and
 //     "size" variable tells the size of the 'a' array.
 //Postcondition: Prints the entire array in square brackets with
 //     pipes between each number
 
#endif
