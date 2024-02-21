#include "array_functions.h"
#include "assert.h"
 
 // fills an array
void _array_init(int a[], int size, int x){
    for (int i = 0; i < size; i++){
        a[i] = x;
    }
}
 
 // adds to a list
void _append(int a[], int& size, int append_me){
    a[size++] = append_me; 
}

//searches a list to see if somethings in it and if it
//is return the index if not return -1
int _find(const int a[], int size, int find_me){
    for (int i = 0; i < size; i++){
        if(a[i] == find_me){
            return i;
        }
    }
    return -1;
}
 
 //returns the array value at a specific index
int& _at(int a[], int size, int pos){
    assert(pos < size);
    return a[pos]; 
}
 
 //prints out the array
ostream& _print_array(const int a[], int size, ostream& outs){
    outs << "[";
    for (int i = 0; i < size; i++){
        outs << a[i] << "|";
    }
    outs << "]";
    return outs;
}
