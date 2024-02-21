#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H
#include <iostream>

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

using namespace std;

const int MINIMUM_CAPACITY = 3;


// Appends a value to the end of a array
template<typename T>
void append_array(T *arr, int &size, T value);

//Create a dynamic array and assigns it to passed pointer
template<class T>
T* allocate(int capacity= MINIMUM_CAPACITY);            //allocate 'capacity' 
                                                        //      elements. 
                                                        //  return array

//Prints array
template<class T>
void print_array(T* a, int size, int capacity = 0, ostream& outs = cout);    //prints 
                                                        //  (size/capacity)
                                                        //  for debugging

//Prints part of a array
template <class T>
void print(T* a, unsigned int how_many, ostream& outs = cout);  //print array

//Return pointer at a position in an array
//search for 'find me'
template<class T>
T* search_entry(T* a, int size, const T& find_me);

//return index of a array where they find a value
template <class T>
int search(T* a, int size, const T& find_me);           //search for 'find_me' 

//shift a array left
template <class T>
void shift_left(T* a, int& size, T* shift_here);        //shift left @ pos: 
                                                        //    erases @ pos

//Shift array left
template <class T>
void shift_left(T* a, int& size, int shift_here);       //shift left @ pos:
                                                        //    erases @ pos

//shift array right
template <class T>
void shift_right(T *a, int &size, T* shift_here);       //shift right: 
                                                        //   make a hole

//Shift array right
template <class T>
void shift_right(T *a, int &size, int shift_here);      //shift right: 
                                                        //      make a hole

//Exports a array into another array
template<class T>
void copy_array(T *dest, const T* src, int many_to_copy);      //copy from src to dest

//Exports a array into another array
template <class T>
T* copy_array(const T *src, int size);                  //return a 
                                                        //  copy of src

//Change the capacity of an array
template<class T>
T* reallocate(T* a, int size, int capacity);            //take array, resize it 
                                                        //  return new array. 
                                                        //  delete old array

//Converts a array into a string
template <class T>
string array_string(const T *a, int size);              //return array 
                                                        //  as a string




template<typename T>
void append_array(T *arr, int &size, T value){
  T *walker = arr + size;
  *walker = value;
  size++;
}
//Precondition: The array has an extra space to accept a value
//
//Postcondition: append a value to the end of the array
//


template<class T>
T* allocate(int capacity){
    T* p;
    p = new T[capacity];
    return p;
}                                                        
//Precondition: Established pointer and "capacity" is how much the
//  array will be able to hold
//Postcondition: Create a dynamic array and assigns it to passed pointer
//


template<class T>
void print_array(T* a, int size, int capacity, ostream& outs){
    T* walker = a;
    if (capacity != 0)
        outs << "[" << setw(2) << size << "/" << capacity <<"] ";
    else
        outs << "[" << setw(2) << size << "] ";
    outs << "[";
    for (int i = 0; i < size; i++){
        outs << setw(10) << *walker;
        walker++;
    }
    outs << "]" << endl;
}
//Precondition: Pointer is pointing at the start of an array. "size" is size of array
//  and "capcity" is how big the array is 
//Postcondition: Prints the array
//


template <class T>
void print(T* a, unsigned int how_many, ostream& outs){
    print_array(a, how_many);
}
//Precondition: "how_many" is less then the capacity of "*a". "a" is pointing at the
//  beginning of an array
//Postcondition: prints part of a array
//



template<class T>
T* search_entry(T* a, int size, const T& find_me){
    T* walker = a;
    for (int i = 0; i < size; i++){
        if(*walker == find_me){
            return walker;
        }
        walker++;
    }
    return nullptr;
}
//Precondition: "a" is pointing at the start of an array. "size" is the size of "*a".
//  "find_me" is a possible content in "*a".
//Postcondition: Returns a pointer pointing at where "find_me" is in array "*a" or
//  nullptr if "find_me" is not in the array


template <class T>
int search(T* a, int size, const T& find_me){
    T* found;
    found = search_entry(a, size, find_me);
    if(found){
        return found - a;
    } else {
        return -1;
    }
}
//Precondition: "a" is pointing at the start of an array. "size" is the size of "*a".
//  "find_me" is a possible content in "*a".
//Postcondition: return index of "*a" where "find_me" is found or -1 if not found
//


template <class T>
void shift_left(T* a, int& size, T* shift_here){
    T* walker = shift_here + 1;
    for(; walker < a + size; shift_here++, walker++){
        *shift_here = *walker;
    }
    size--;

}
//Precondition: "a" is pointing at the start of an array. "size" is the size of "*a".
//  "shift_here" is pointing somewhere in the array 
//Postcondition: Deletes value at "shift_here" and moves content in the array one left
//  filling the hole and making the size 1 smaller                                       


template <class T>
void shift_left(T* a, int& size, int shift_here){
    shift_left(a, size, a+shift_here);
}
//Precondition: "a" is pointing at the start of an array. "size" is the size of "*a".
//  "shift_here" is somewhere in the array 
//Postcondition: Deletes found value of "shift_here" in array and moves content 
//  in the array one left filling the hole and making the size 1 smaller    


template <class T>
void shift_right(T *a, int &size, T* shift_here){
    
    T* walker = a + size;
    T* changer = walker;
    for(; shift_here != walker; walker--){
        changer--;
        *walker = *changer;
    }
    size++;
}
//Precondition: "a" is pointing at the start of an array. "size" is the size of "*a".
//  "shift_here" is pointing somewhere in the array 
//Postcondition: Shift value at "shift_here" to the right and all the subsequent values 
//  moves right and increase the size by 1


template <class T>
void shift_right(T* a, int& size, int shift_here){
    shift_right(a, size, a + shift_here);
}
//Precondition: "a" is pointing at the start of an array. "size" is the size of "*a".
//  "shift_here" is pointing somewhere in the array 
//Postcondition: Shift value at "shift_here" to the right and all the subsequent values 
//  moves right and increase the size by 1                                                   


template<class T>
void copy_array(T *dest, const T* src, int many_to_copy){
    T* desWalker;
    desWalker = dest;
    const T* srcWalker;
    srcWalker = src;
    for(;srcWalker < src + many_to_copy; srcWalker++){
        *desWalker = *srcWalker;
        desWalker++;
    }
}
//Precondition: "dest" and "src" are pointing at the start of an array. "dest" array
//  can hold "many_to_copy" amount of values
//Postcondition: Move "many_to_copy" amt of values from "src" to "dest"
//


template <class T>
T* copy_array(const T *src, int size){
    T* newArray;
    newArray = allocate<int>(size);
    copy_array(newArray, src, size);
    return newArray;
}
//Precondition: ""src" is pointing at the start of an array. "size" is the size of "*src"
//Postcondition: returns a pointer that points at an array with the contents of "src" array
//                                                      


template<class T>
T* reallocate(T* a, int size, int capacity){
    T* newArray;
    newArray = allocate<T>(capacity);
    copy_array(newArray, a, size);
    // T* nArrayWalker = newArray;
    // for (int i = 0; i < size; i++){
    //     *nArrayWalker = 1;
    //     nArrayWalker++;
    // }


    delete []a;
    return newArray;
}
//Precondition: Pointer is pointing at the start of an array. Size is the
//  amount of content is in array and capacity is how big the new array will be
//Postcondition: Makes another dynamic array with new capacity of size "capacity"
//  and copies over old array into new array


template <class T>
string array_string(const T *a, int size){
    string s;
    const T* walker = a;
    s = "[";
    for(; walker < a + size; walker++){
        s += to_string(*walker);
        s += " ";
    }
    s += "][";
    s += to_string(size);
    s += "]";
    return s;
}
//Precondition: Pointer is pointing at the start of an array and size is size of array
//
//Postcondition: Converts a array into a string enclosed in brackets
//                                                      
#endif