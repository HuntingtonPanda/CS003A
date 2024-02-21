#ifndef DELETE_REPEATS_H
#define DELETE_REPEATS_H
#include <iostream>

#include "../../includes/array_functions/array_functions.h"

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

using namespace std;

template <class T>
//Deletes duplicates in arrays
void delete_repeats(T* a, int& size);

template <class T>
void delete_repeats(T* a, int& size){
    T* walker;
    T* searcher;

    const int amtOfRun = size;

    walker = a + 1;
    for (int i = 1; i < amtOfRun; i++){
        searcher = search_entry(a, size, *walker);
        if(walker != searcher)
            shift_left(a, size, walker);
        else
            walker++;
    }
}
//Precondition: It passes a pointer that points at an array and size
//      is the size of the array
//Postcondition: It deletes duplicates from the array
//

#endif