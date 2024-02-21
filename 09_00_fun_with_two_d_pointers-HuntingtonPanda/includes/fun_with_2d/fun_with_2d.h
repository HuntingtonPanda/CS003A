#ifndef FUN_WITH_2D_H

#define FUN_WITH_2D_H
#include <iostream>

#include "../../includes/array_functions/array_functions.h"
#include "../../includes/delete_repeats/delete_repeats.h"

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

using namespace std;

template <class T>
T** allocate_twod(int* sizes);

template <class T>
//Deletes duplicates in arrays
void delete_all_repeats(T** a, const int* oneDSizes, int& twoDSize);



template <class T>
T** allocate_twod(int* sizes){
    int counter = array_size(sizes);
    T** twoD = new T*[counter + 1];

    T** twoDWalker = twoD;

    int* sizesWalker = sizes;

    for (int i = 0; i < counter; i++, twoDWalker++, sizesWalker++){
        *twoDWalker = new T[*sizesWalker];
    }
    twoDWalker = twoD + counter;
    *twoDWalker = nullptr; //could be error

    return twoD;
} 


template <class T>
void delete_all_repeats(T** a, const int* oneDSizes, int& twoDSize, int*sizes){
    
    T** twoDWalker = a, twoDWalker2 = a;
    T* oneDWalker, oneDWalker2;

    T checkWith, checkAgainst;
    
    int colSize;
    while(*size > 0){
        colSize++;
    }

    for(int i = 0; i < colSize; i++)
        oneDWalker = *twoDWalker;

        for (int i = 0; i < *sizes; i++, oneDWalker++){
            check = *oneDWalker;
        }

        twoDWalker++;
        sizes++;
    }


}

#endif