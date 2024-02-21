#ifndef LIST_ITERATED_H
#define LIST_ITERATED_H

#include <iostream>
using namespace std;

#include "../node/node.h"
#include "../linked_list_functions/linked_list_functions.h"
// #include <iomanip>

template <class ITEM_TYPE>
class List
{
public:
class Iterator{
    public:
        friend class List;                              //give access to list to access _ptr
        Iterator() : _ptr(nullptr) { }                                     //default ctor
        Iterator(node<ITEM_TYPE>* p) : _ptr(p) { }                   //Point Iterator to where p is pointing to
        operator bool(){ return true; }                                //casting operator: true if _ptr not NULL
                                                        //      this turned out to be a pain!


        ITEM_TYPE& operator *(){  //dereference operator
            return _ptr->_item;
        }                        
        ITEM_TYPE* operator ->(){ 
            return &(_ptr->_item);
        } 
                              //member access operator
        ITEM_TYPE*  operator ->() const{ 
            return &(_ptr->_item);
        }  

        bool is_null(){ return _ptr == nullptr; }                                 //true if _ptr is NULL

        friend bool operator !=(const Iterator& left, const Iterator& right)
        { return left._ptr != right._ptr; } //true if left != right

        friend bool operator ==(const Iterator& left, const Iterator& right)
        { 
            return left._ptr == right._ptr;
        } //true if left == right

        Iterator& operator++(){ 
            if(_ptr)
                _ptr = _ptr->_next;
            return *this;
        }                 //member operator: ++it; or ++it = new_value

        friend Iterator operator++(Iterator& it,
                                   int unused)
        {  
            Iterator temp = it;
            it._ptr = (it._ptr)->_next;
            return temp;
                                   
        }         //friend operator: it++

    private:
        node<ITEM_TYPE>* _ptr;                          //pointer being encapsulated
    }; //end of iterator
    
    List();
    ~List();
    List(const List<ITEM_TYPE> &copyThis);
    
    List& operator =(const List& RHS);

    node<ITEM_TYPE>* simple_insert_head(ITEM_TYPE i);           //inset i at the head of list

    node<ITEM_TYPE>* simple_insert_after(ITEM_TYPE i,           //insert i after iMarker
                                 node<ITEM_TYPE>* iMarker);

    node<ITEM_TYPE>* simple_insert_before(ITEM_TYPE i,          //insert i before iMarker
                                  node<ITEM_TYPE>* iMarker);

    node<ITEM_TYPE>* simple_insert_sorted(ITEM_TYPE i);         //insert i. Assume sorted list



    ITEM_TYPE simple_Delete(node<ITEM_TYPE>* iMarker);         //delete node pointed to by iMarker


    void simple_Print() const;                                 //print the list

    node<ITEM_TYPE>* simple_search(const ITEM_TYPE &key);      //return pointer to node containing
                                                        //  key. NULL if not there

    node<ITEM_TYPE>* simple_prev(node<ITEM_TYPE>* iMarker);    //get the previous node to iMarker

    node<ITEM_TYPE>* simple_begin() const;                     //return the head of the list

    node<ITEM_TYPE>* simple_end() const;                       
                                                            
    int size() const{ return _size; }
    
    friend ostream& operator <<(ostream& outs,          //insertion operator for list
                                const List<ITEM_TYPE>& l)
    {
        for(node<ITEM_TYPE>* walker = l.head; walker != nullptr; walker = walker->_next)
        {
            outs << walker->_item << "-> ";
        }
        outs << "|||";
        return outs;
    } 

    //beginning of iterated list
    Iterator insert_head(ITEM_TYPE i);                           //insert at the head of list
    Iterator insert_after(ITEM_TYPE i,
                                          Iterator iMarker);    //insert after marker
    Iterator insert_before(ITEM_TYPE i,
                                           Iterator iMarker);   //insert before marker
    Iterator insert_sorted(ITEM_TYPE i);                         //insert in a sorted list

    ITEM_TYPE Delete(List<ITEM_TYPE>::Iterator iMarker);        //delete node pointed to by marker
    void Print() const;
    Iterator search(const ITEM_TYPE &key);                      //return Iterator to node [key]
    Iterator prev(Iterator iMarker);                            //previous node to marker

    ITEM_TYPE& operator[](int index);                           //return item at position index
    Iterator begin() const;                                     //Iterator to the head node
    Iterator end() const;                                       //Iterator to NULL
    Iterator last_node() const;                                  //Iterator to the last node
    bool empty()const {return head == nullptr;}                                         //Note the template arg U
    friend ostream& operator <<(ostream& outs, const List<ITEM_TYPE>& l);      
private:
    node<ITEM_TYPE>* head = nullptr;
    int _size;
};




/*
DEFINITION DEFINITION DEFINITION DEFINITION DEFINITION
DEFINITION DEFINITION DEFINITION DEFINITION DEFINITION
DEFINITION DEFINITION DEFINITION DEFINITION DEFINITION
DEFINITION DEFINITION DEFINITION DEFINITION DEFINITION
*/




template <class ITEM_TYPE>
List<ITEM_TYPE>::List(){
    head = nullptr;
    _size = 0;
}

template <class ITEM_TYPE>
List<ITEM_TYPE>::~List(){
    //cout << "Derefrence fired ";
    _clear_list(head);
    //cout << "Derefrence complete\n";
}

template <class ITEM_TYPE>
List<ITEM_TYPE>::List(const List<ITEM_TYPE> &copyThis){
    //cout << "AHHHHHHHH\n";
    head = _copy_list(copyThis.head);
    _size = copyThis._size;
}

template <class ITEM_TYPE>
List<ITEM_TYPE>& List<ITEM_TYPE>::operator =(const List& RHS){
    _copy_list(head, RHS.head);
    _size = RHS._size;
    return *this;
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::simple_insert_head(ITEM_TYPE i){
    head = _insert_head(head, i);
    _size++;
    return head;
}           //inset i at the head of list

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::simple_insert_after(ITEM_TYPE i,           //insert i after iMarker
                                node<ITEM_TYPE>* iMarker){
    node<ITEM_TYPE>* temp = _insert_after(head, iMarker, i);
    _size++;
    return temp;
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::simple_insert_before(ITEM_TYPE i,          //insert i before iMarker
                                node<ITEM_TYPE>* iMarker){
    node<ITEM_TYPE>* temp = _insert_before(head, iMarker, i);
    _size++;

    return temp;                                
}

// template <class ITEM_TYPE>
// node<ITEM_TYPE>* List<ITEM_TYPE>::insert_sorted(ITEM_TYPE i){

//     node<ITEM_TYPE>* Walker = head;
//     int counter = 0;
//     while(Walker->_item < i && counter++ < (_size - 1))
//         Walker = Walker->_next;
//     Walker = _insert_before(head, Walker, i);
//     _size++;
//     return Walker;
// }         //insert i. Assume sorted list



template <class ITEM_TYPE>
ITEM_TYPE List<ITEM_TYPE>::simple_Delete(node<ITEM_TYPE>* iMarker){
    
    ITEM_TYPE a = _delete_node(head, iMarker);
    _size--;
    return a;
}         //delete node pointed to by iMarker


template <class ITEM_TYPE>
void List<ITEM_TYPE>::simple_Print() const{
    // node<ITEM_TYPE>* Walker = head;
    // while(Walker){
    //     cout << Walker->_item >> " -> ";
    // }
    // cout << Walker->_item;
    //cout << "sad";
    _print_list(head);
}                                 //print the list

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::simple_search(const ITEM_TYPE &key){
    
    node<ITEM_TYPE>* temp = _search_list(head, key);
    

    return temp; 
}      //return pointer to node containing
                                                    //  key. NULL if not there

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::simple_prev(node<ITEM_TYPE>* iMarker){
    
    node<ITEM_TYPE>* temp = _previous_node(head, iMarker);
    
    return temp; 
}    //get the previous node to iMarker


template <class ITEM_TYPE>
ITEM_TYPE& List<ITEM_TYPE>::operator[](int index){

    return _at(head, index);
}                   //return the item at index

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::simple_begin() const{
    return head;
}                     //return the head of the list

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::simple_end() const{
    // node<ITEM_TYPE>* temp = head;
    // for(int i = 1; i < _size; i++)
    //     temp = temp->_next;
    // return temp;
    return nullptr;
}

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::insert_head(ITEM_TYPE i){
    return Iterator(simple_insert_head(i));
}                           //insert at the head of list

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::insert_after(ITEM_TYPE i,
                                        Iterator iMarker){
    return Iterator(simple_insert_after(i, iMarker._ptr));                                        
                                        }    //insert after marker
template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::insert_before(ITEM_TYPE i,
                                        Iterator iMarker){
    return Iterator(simple_insert_before(i, iMarker._ptr));                                        
                                        }   //insert before marker
template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::insert_sorted(ITEM_TYPE i){
    return Iterator(simple_insert_sorted(i));
}                         //insert in a sorted list

template <class ITEM_TYPE>
ITEM_TYPE List<ITEM_TYPE>::Delete(typename List<ITEM_TYPE>::Iterator iMarker){
    return simple_Delete(iMarker._ptr);
}        //delete node pointed to by marker

template <class ITEM_TYPE>
void List<ITEM_TYPE>::Print() const{
    simple_Print();
}

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::search(const ITEM_TYPE &key){
    return Iterator(simple_search(key));
}                      //return Iterator to node [key]

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::prev(Iterator iMarker){
    return Iterator(simple_prev(iMarker._ptr));
}                            //previous node to marker


template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::begin() const{
    return Iterator(simple_begin());
}                                     //Iterator to the head node

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::end() const{
    return Iterator(simple_end());
}                                       //Iterator to NULL

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::last_node() const{
    node<ITEM_TYPE>* temp = head;
    while(temp->_next)
        temp = temp->_next;
    return Iterator(temp);
}                                  //Iterator to the last node









#include "list_iterated.cpp"
#endif





/*
#ifndef LIST_H
#define LIST_H

#include "../node/node.h"

#include "../linked_list_functions/linked_list_functions.h"

template <class ITEM_TYPE>
class List
{
public:
    class Iterator{
    public:
        friend class List;                              //give access to list to access _ptr
        Iterator(){
            _ptr = nullptr;
        }                                     //default ctor
        Iterator(node<ITEM_TYPE>* p){
            _ptr = p;
        }                   //Point Iterator to where p is pointing to
        operator bool();                                //casting operator: true if _ptr not NULL
                                                        //      this turned out to be a pain!


        ITEM_TYPE& operator *(){
            return _ptr->_item;
        }                        //dereference operator
        ITEM_TYPE* operator ->(){
            return &(_ptr->_item);
        }                       //member access operator

        bool is_null(){
            if(_ptr)
                return false;
            return true;
        }                                 //true if _ptr is NULL

        friend bool operator !=(const Iterator& left,
                                const Iterator& right){
            return left._ptr != right._ptr;                             
        } //true if left != right

        friend bool operator ==(const Iterator& left,
                                const Iterator& right){
            return left._ptr == right._ptr;                           
        } //true if left == right

        Iterator& operator++(){
            return _ptr++;
        }                         //member operator: ++it; or ++it = new_value

        friend Iterator operator++(Iterator& it,
                                   int unused){

        }         //friend operator: it++

    private:
        node<ITEM_TYPE>* _ptr;                          //pointer being encapsulated
    };      
    List();                                                     //CTOR
                                                                //BIG 3:
    ~List();
    List(const List<ITEM_TYPE> &copyThis);
    List& operator =(const List& RHS);

    //int size();
    Iterator simple_insert_head(ITEM_TYPE i);                           //insert at the _head_ptr of list
    Iterator simple_insert_after(ITEM_TYPE i,
                                          Iterator iMarker);    //insert after marker
    Iterator simple_insert_before(ITEM_TYPE i,
                                           Iterator iMarker);   //insert before marker
    Iterator simple_insert_sorted(ITEM_TYPE i);                         //insert in a sorted list

    ITEM_TYPE simple_Delete(List<ITEM_TYPE>::Iterator iMarker);        //delete node pointed to by marker
    void simple_Print() const;
    Iterator simple_search(const ITEM_TYPE &key);                      //return Iterator to node [key]
    Iterator simple_prev(Iterator iMarker);                            //previous node to marker

    ITEM_TYPE& simple_operator[](int index);                           //return item at position index
    Iterator simple_begin() const;                                     //Iterator to the _head_ptr node
    Iterator simple_end() const;                                       //Iterator to NULL
    Iterator simple_last_node() const;                                  //Iterator to the last node
    bool empty()const {return _head_ptr == NULL;}
    template <class U>                                          //Note the template arg U
    friend ostream& operator <<(ostream& outs, const List<U>& l);
    int size()const { return _size; }

private:
    node<ITEM_TYPE>* _head_ptr;
    int _size;
};

template <class ITEM_TYPE>
List<ITEM_TYPE>::List(){
    _head_ptr = nullptr;
    _size = 0;
}

template <class ITEM_TYPE>
List<ITEM_TYPE>::~List(){
    //cout << "Derefrence fired ";
    _clear_list(_head_ptr);
    //cout << "Derefrence complete\n";
}

template <class ITEM_TYPE>
List<ITEM_TYPE>::List(const List<ITEM_TYPE> &copyThis){
    //cout << "AHHHHHHHH\n";
    _head_ptr = _copy_list(copyThis._head_ptr);
    _size = copyThis._size;
}

template <class ITEM_TYPE>
List<ITEM_TYPE>& List<ITEM_TYPE>::operator =(const List& RHS){
    _copy_list(_head_ptr, RHS._head_ptr);
    _size = RHS._size;
    return *this;
}

template <class ITEM_TYPE>
Iterator<ITEM_TYPE>* List<ITEM_TYPE>::simple_insert_head(ITEM_TYPE i){
    _head_ptr = _insert__head_ptr(_head_ptr, i);
    _size++;
    return _head_ptr;
}           //inset i at the _head_ptr of list

template <class ITEM_TYPE>
Iterator<ITEM_TYPE>* List<ITEM_TYPE>::simple_insert_after(ITEM_TYPE i,           //insert i after iMarker
                                Iterator<ITEM_TYPE>* iMarker){
    node<ITEM_TYPE>* temp = _insert_after(_head_ptr, iMarker, i);
    _size++;
    return temp;
}

template <class ITEM_TYPE>
Iterator<ITEM_TYPE>* List<ITEM_TYPE>::simple_insert_before(ITEM_TYPE i,          //insert i before iMarker
                                Iterator<ITEM_TYPE>* iMarker){
    Iterator<ITEM_TYPE>* temp = _insert_before(_head_ptr, iMarker, i);
    _size++;

    return temp;                                
}

// template <class ITEM_TYPE>
// Iterator<ITEM_TYPE>* List<ITEM_TYPE>::insert_sorted(ITEM_TYPE i){

//     Iterator<ITEM_TYPE>* Walker = _head_ptr;
//     int counter = 0;
//     while(Walker->_item < i && counter++ < (_size - 1))
//         Walker = Walker->_next;
//     Walker = _insert_before(_head_ptr, Walker, i);
//     _size++;
//     return Walker;
// }         //insert i. Assume sorted list



template <class ITEM_TYPE>
ITEM_TYPE List<ITEM_TYPE>::simple_Delete(Iterator<ITEM_TYPE>* iMarker){
    
    ITEM_TYPE a = _delete_node(_head_ptr, iMarker);
    _size--;
    return a;
}         //delete node pointed to by iMarker


template <class ITEM_TYPE>
void List<ITEM_TYPE>::simple_Print() const{
    // node<ITEM_TYPE>* Walker = _head_ptr;
    // while(Walker){
    //     cout << Walker->_item >> " -> ";
    // }
    // cout << Walker->_item;
    //cout << "sad";
    _print_list(_head_ptr);
}                                 //print the list

template <class ITEM_TYPE>
Iterator<ITEM_TYPE>* List<ITEM_TYPE>::simple_search(const ITEM_TYPE &key){
    
    node<ITEM_TYPE>* temp = _search_list(_head_ptr, key);
    

    return temp; 
}      //return pointer to node containing
                                                    //  key. NULL if not there

template <class ITEM_TYPE>
Iterator<ITEM_TYPE>* List<ITEM_TYPE>::simple_prev(Iterator<ITEM_TYPE>* iMarker){
    
    node<ITEM_TYPE>* temp = _previous_node(_head_ptr, iMarker);
    
    return temp; 
}    //get the previous node to iMarker


template <class ITEM_TYPE>
ITEM_TYPE& List<ITEM_TYPE>::operator[](int index){

    return _at(_head_ptr, index);
}                   //return the item at index

template <class ITEM_TYPE>
Iterator<ITEM_TYPE>* List<ITEM_TYPE>::simple_begin() const{
    return _head_ptr;
}                     //return the _head_ptr of the list

template <class ITEM_TYPE>
Iterator<ITEM_TYPE>* List<ITEM_TYPE>::simple_end() const{
    node<ITEM_TYPE>* temp = _head_ptr;
    for(int i = 1; i < _size; i++)
        temp = temp->_next;
    return temp;
}                       

template <class U>
ostream& operator <<(ostream& outs,          //insertion operator for list
                            const List<U>& l){
    // node<U>* walker = l._head_ptr; 
    // cout << "BBBB";
    // walker = nullptr;
    // while(walker != nullptr){
    //     outs << *walker << "->";
    //     walker = walker->_next;
    //     walker = nullptr;
    // }
    // cout << "AHHH";
    // outs << "| | |";
    node<U>* walker = l._head_ptr;  
    while(walker != nullptr){
        outs << *walker << "-> ";
        walker = walker -> _next;
    }
    outs << "| | |\n";                            
    return outs;
}

#endif*/