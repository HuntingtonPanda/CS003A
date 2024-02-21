#ifndef ADD_ENTRY_H
#define ADD_ENTRY_H
#include <iostream>

#include "../../includes/array_functions/array_functions.h"

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

using namespace std;

template<class T>
T* add_entry(T* list, const T& new_entry, int& size, int& capacity);

template<class T>
T* remove_entry(T* list, const T& delete_me, int& size, int& capacity);

template <class T>
T *remove_last_entry(T *list, T &popped, int &size, int &capacity);

template <class T>
T *insert_entry(T *list, const T &insert_this, int insert_here, int &size, int &capacity);

template <class T>
T *erase_entry(T *list, int index, int &size, int &capacity);

template<class T>
T* add_entry(T* list, const T& new_entry, int& size, int& capacity){
    if(size >= capacity){
        capacity *= 2;
        list = reallocate(list, size, capacity);
    }
    append_array(list, size, new_entry);
    return list;
}

template<class T>
T* remove_entry(T* list, const T& delete_me, int& size, int& capacity){
    T* searchValue;
    searchValue = search_entry(list, size, delete_me);
    shift_left(list, size, searchValue);
    if(size <= capacity/4){
        capacity /= 2;
        if(capacity < 3)
            capacity = 3;
        list = reallocate(list, size, capacity);
    }
    return list;
}

template <class T>
T *remove_last_entry(T *list, T &popped, int &size, int &capacity){
    T* lastPosition = list + size - 1;
    popped = *lastPosition;
    shift_left(list, size, lastPosition);
    if(size <= capacity/4){
        capacity /= 2;
        if(capacity < 3)
            capacity = 3;
        list = reallocate(list, size, capacity);
    }
    return list;
}

template <class T>
T *insert_entry(T *list, const T &insert_this, int insert_here, int &size, int &capacity){
    if(size >= capacity){
        capacity *= 2;
        list = reallocate(list, size, capacity);
    }
    shift_right(list, size, insert_here);
    //append_array(list, insert_here, insert_this);
    T* placer = list + insert_here;
    *placer = insert_this;
    return list;
}

template <class T>
T *erase_entry(T *list, int index, int &size, int &capacity){
    if(size <= capacity/4){
        capacity /= 2;
        list = reallocate(list, size, capacity);
    }
    shift_left(list, size, index);
    return list;
}
#endif