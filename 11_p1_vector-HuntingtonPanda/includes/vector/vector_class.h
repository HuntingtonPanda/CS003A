#ifndef VECTOR_HH
#define VECTOR_HH


#include <iostream>
#include <iomanip>
#include "assert.h"
#include "../array_functions/array_functions.h"
#include "../add_entry/add_entry.h"


using namespace std;


template <class T>
class Vector{
public:


Vector(int capacity = 3);
Vector(T *arr, int size);

// big three:

Vector(const Vector& other);


Vector& operator =(const Vector& rhs);


~Vector();




//member access functions:
T& operator [](int index);
const T& operator [](int index) const;


T& at(int index);              //return reference to item at position index
const T& at(int index) const;  //return a const item at position index


T& front();                         //return item at position 0.
T& back();                          //return item at the last position




//Push and Pop functions:
Vector& operator +=(const T& item); //push_back
void push_back(const T& item);      //append to the end
T pop_back();                       //remove last item and return it




//Insert and Erase:
void insert(int insert_here, const T& insert_this); //insert at pos
void erase(int erase_this_index);        //erase item at position
int index_of(const T& item);             //search for item. retur index.


//size and capacity:
void set_size(int size);              //enlarge the vector to this size
void set_capacity(int capacity);      //allocate this space
int size() const {return _size;}  //return _size
int capacity() const {return _capacity;} //return _capacity


bool empty() const;                    //return true if vector is empty


//OUTPUT:
template <class U>
friend ostream& operator <<(ostream& outs, const Vector<U>& _a);


private:
int _size;
int _capacity;
T* a;
};


template<class T>
Vector<T>::Vector(int capacity){
    _size = 0;
    _capacity = capacity;
    a = allocate<T>(_capacity);
}

template<class T>
Vector<T>::Vector(T *arr, int size){
    _size = size;
    _capacity = 3;
    while (_capacity < _size)
        _capacity *= 2;

    a = allocate<T>(_capacity);    
    copy_array(a, arr, size);
}

// big three:
template<class T>
Vector<T>::Vector(const Vector& other){
    _size = other.size();
    _capacity = other.capacity();

    a = allocate<T>(_capacity);
    copy_array(a, other.a, _size);
}


template<class T>
Vector<T>& Vector<T>::operator =(const Vector& rhs){

    if(this == &rhs)
    {
        return *this;
    }

    delete[] a;
    _size = rhs.size();
    _capacity = rhs.capacity();

    a = allocate<T>(_capacity);
    copy_array(a, rhs.a, _size); //Maybe does not need this.
    return *this;
        
}


template<class T>
Vector<T>::~Vector(){
    //cout << "~dereference Attempt\n";
    delete[] a;
    //cout << "~dereference Complete\n";
}




//member access functions:
template<class T>
T& Vector<T>::operator [](int index){
    T* value;
    value = a + index;
    return *value;
}


template<class T>
const T& Vector<T>::operator [](int index) const{
    T* value;
    value = a + index;
    return *value;
}



template<class T>
T& Vector<T>::at(int index){
    T* value;
    value = a + index;
    return *value;
}              //return reference to item at position index

template<class T>
const T& Vector<T>::at(int index) const{
    T* value;
    value = a + index;
    return *value;
}  //return a const item at position index


template<class T>
T& Vector<T>::front(){
    return a[0];
}
                            //return item at position 0.
template<class T>
T& Vector<T>::back(){
    return a[_size-1];

}                          //return item at the last position




//Push and Pop functions:

template<class T>
Vector<T>& Vector<T>::operator +=(const T& item){
    push_back(item);
    return *this;
} //push_back

template<class T>
void Vector<T>::push_back(const T& item){
    // _size++;

    // if (_size > _capacity){
    //     _capacity *= 2;
    //     a = reallocate(a, _size - 1, _capacity);
    // }
    
    // T* aWalker = a + (_size - 1);

    // *aWalker = item;

    
    a = add_entry(a, item, _size, _capacity);

}      //append to the end

template<class T>
T Vector<T>::pop_back(){
    // T* aWalker = a + (_size - 1);
    // T temp = *aWalker;
    // shift_left(a, _size, aWalker);
    // return temp;

    assert(_size>0);
    T temp;
    a = remove_last_entry(a, temp, _size, _capacity);
    return temp;
}                       //remove last item and return it




//Insert and Erase:
template<class T>
void Vector<T>::insert(int insert_here, const T& insert_this){
    a = insert_entry(a, insert_this, insert_here, _size, _capacity);

} //insert at pos
template<class T>
void Vector<T>::erase(int erase_this_index){
    a = erase_entry(a, erase_this_index, _size, _capacity);

}        //erase item at position
template<class T>
int Vector<T>::index_of(const T& item){
    return search(a, _size, item);

}             //search for item. retur index.


//size and capacity:
template<class T>
void Vector<T>::set_size(int size){


}              //enlarge the vector to this size
template<class T>
void Vector<T>::set_capacity(int capacity){
    _capacity = capacity;
    if(_size > _capacity)
        _size = _capacity;
    reallocate(a, _size, _capacity);

}   //allocate this space




template<class T>
bool Vector<T>::empty() const{
    return _size == 0;

}                   //return true if vector is empty

template <class U>
ostream& operator <<(ostream& outs, const Vector<U>& _a){
    
    outs << "(" << _a.size() << "/" <<_a.capacity() << ")";
    outs << "[";
    for(int i = 0; i < _a.size(); i++)
        outs << setw(10) << _a[i];
    outs << "]";
    return outs;
}




#endif

