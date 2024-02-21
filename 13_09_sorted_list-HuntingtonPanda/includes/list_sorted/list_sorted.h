#ifndef LIST_SORTED_H
#define LIST_SORTED_H

#include <iostream>
#include <iomanip>
#include "assert.h"

#include "../linked_list_functions/linked_list_functions.h"
#include "../node/node.h"

using namespace std;

template <class T>
class List
{
public:
    class Iterator{
    public:
        friend class List;                          //give access to list to
                                                    //          access _ptr
        Iterator(){_ptr = nullptr;}                    //default ctor
        Iterator(node<T>* p) : _ptr(p) {}
                                                    //Point Iterator to where p
                                                    //  is pointing to
        T &operator*(){
            return _ptr->_item;
        }                             //dereference operator

        T *operator->(){ 
            return &(_ptr->_item);
        }                             //member access operator
        bool is_null(){ return _ptr == nullptr; }     //true if _ptr is NULL
        friend bool operator!=(const Iterator &left,
                               const Iterator &right)
        { return left._ptr != right._ptr; } //true if left != right

        friend bool operator==(const Iterator &left,
                               const Iterator &right)
        { return left._ptr != right._ptr; } //true if left == right

        Iterator &operator++(){ 
            if(_ptr)
                _ptr = _ptr->_next;
            return *this;
        }                            //member operator:
                                                        //  ++it; or
                                                        //  ++it = new_value

        friend Iterator operator++(Iterator &it,
                                   int unused){  
            Iterator temp = it;
            it._ptr = (it._ptr)->_next;
            return temp;
                                   
        }         //friend operator: it++          //friend operator: it++

    private:
        node<T>* _ptr;                          //pointer being encapsulated
    };

    List(bool order=true, bool unique=false);           //CTOR: default args
                                                        //BIG 3:
    ~List();
    List(const List<T> &copyThis);
    List& operator =(const List& RHS);

    Iterator insert(const T& i);                        //Insert i
    Iterator insert_and_add(const T& i);                //Insert i

    T Delete(List<T>::Iterator iMarker);                //delete node at marker
    void Print() const;
    Iterator search(const T &key) const;                //return Iterator to
                                                        //          node [key]
    Iterator prev(Iterator iMarker);                    //previous node: marker

    const T& operator[](int index) const;               //const version of the
                                                        //       operator [ ]
    T& operator[](int index);                           //return item at index
    Iterator begin() const;                             //Iterator to head node
    Iterator end() const;                               //Iterator to NULL
    Iterator last_node() const;                          //Iterator to last node
    bool empty() const { return _head_ptr == nullptr; }
    template <class U>                                  //Note template arg U
    friend ostream& operator <<(ostream& outs, const List<U>& l)
    {
        for(node<U>* walker = l._head_ptr; walker != nullptr; walker = walker->_next)
        {
            outs << walker->_item << "-> ";
        }
        outs << "|||";
        return outs;
    } 
    int size() const { return _size; }

private:
    node<T>* _head_ptr;
    bool _order;
    bool _unique;
    int _size;
};  

template <class T>
List<T>::List(bool order, bool unique){
    _head_ptr = nullptr;
    _order = order;
    _unique = unique;
    _size = 0;
}

template <class T>
List<T>::~List(){
    cout << "Derefrence fired ";
    _clear_list(_head_ptr);
    cout << "Derefrence complete\n";
}

template <class T>
List<T>::List(const List<T> &copyThis){
    //cout << "AHHHHHHHH\n";
    _head_ptr = _copy_list(copyThis._head_ptr);
    _order = copyThis._order;
    _unique = copyThis._unique;
    _size = copyThis._size;
}

template <class T>
List<T>& List<T>::operator =(const List& RHS){
    _copy_list(_head_ptr, RHS._head_ptr);
    _order = RHS._order;
    _unique = RHS._unique;
    _size = RHS._size;
    return *this;
}

template <class T>
typename List<T>::Iterator List<T>::insert(const T& i){
    return Iterator(_insert_sorted(_head_ptr, i, _order));
}                        //Insert i

template <class T>
typename List<T>:: Iterator List<T>::insert_and_add(const T& i){
    return Iterator(_insert_sorted_and_add(_head_ptr, i, _order));
}                //Insert i

// template <class T>
// node<T>* List<T>::insert_sorted(T i){

//     node<T>* Walker = head;
//     int counter = 0;
//     while(Walker->_item < i && counter++ < (_size - 1))
//         Walker = Walker->_next;
//     Walker = _insert_before(head, Walker, i);
//     _size++;
//     return Walker;
// }         //insert i. Assume sorted list



template <class T>
T List<T>::Delete(List<T>::Iterator iMarker){
    
    T a = _delete_node(_head_ptr, iMarker._ptr);
    _size--;
    return a;
}         //delete node pointed to by iMarker


template <class T>
void List<T>::Print() const{
    // node<T>* Walker = head;
    // while(Walker){
    //     cout << Walker->_item >> " -> ";
    // }
    // cout << Walker->_item;
    //cout << "sad";
    _print_list(_head_ptr);
}                                 //print the list

template <class T>
typename List<T>::Iterator List<T>::search(const T &key)const{
    
    Iterator temp = _search_list(_head_ptr, key);
    

    return temp; 
}      //return pointer to node containing
                                                    //  key. NULL if not there

template <class T>
typename List<T>::Iterator List<T>::prev(Iterator iMarker){
    
    Iterator temp = _previous_node(_head_ptr, iMarker._ptr);
    
    return temp; 
}    //get the previous node to iMarker


template <class T>
T& List<T>::operator[](int index){

    return _at(_head_ptr, index);
}                   //return the item at index

template <class T>
typename List<T>::Iterator List<T>::begin() const{
    return _head_ptr;
}                     //return the head of the list

template <class T>
typename List<T>::Iterator List<T>::end() const{
    return nullptr;
}

template <class T>
typename List<T>::Iterator List<T>::last_node() const{
    return Iterator(_last_node(_head_ptr));
}                          //Iterator to last node


#endif