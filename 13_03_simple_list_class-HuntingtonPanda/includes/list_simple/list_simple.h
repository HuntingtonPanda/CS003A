#ifndef LIST_SIMPLE_H
#define LIST_SIMPLE_H

#include "../node/node.h"

#include "../linked_list_functions/linked_list_functions.h"
template <class ITEM_TYPE>
class List
{
public:
    List();

    ~List();
    List(const List<ITEM_TYPE> &copyThis);
    List& operator =(const List& RHS);

    node<ITEM_TYPE>* insert_head(ITEM_TYPE i);           //inset i at the head of list

    node<ITEM_TYPE>* insert_after(ITEM_TYPE i,           //insert i after iMarker
                                 node<ITEM_TYPE>* iMarker);

    node<ITEM_TYPE>* insert_before(ITEM_TYPE i,          //insert i before iMarker
                                  node<ITEM_TYPE>* iMarker);

    //node<ITEM_TYPE>* insert_sorted(ITEM_TYPE i);         //insert i. Assume sorted list



    ITEM_TYPE Delete(node<ITEM_TYPE>* iMarker);         //delete node pointed to by iMarker


    void Print() const;                                 //print the list

    node<ITEM_TYPE>* search(const ITEM_TYPE &key);      //return pointer to node containing
                                                        //  key. NULL if not there

    node<ITEM_TYPE>* prev(node<ITEM_TYPE>* iMarker);    //get the previous node to iMarker


    ITEM_TYPE& operator[](int index);                   //return the item at index

    node<ITEM_TYPE>* begin() const;                     //return the head of the list

    node<ITEM_TYPE>* end() const;                       
                                                        
    bool empty() const { return head == nullptr; }      
    
    int size() const{ return _size; }
    template <class U>
    friend ostream& operator <<(ostream& outs,          //insertion operator for list
                                const List<U>& l);
private:
    node<ITEM_TYPE>* head;
    int _size;
};













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
node<ITEM_TYPE>* List<ITEM_TYPE>::insert_head(ITEM_TYPE i){
    head = _insert_head(head, i);
    _size++;
    return head;
}           //inset i at the head of list

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::insert_after(ITEM_TYPE i,           //insert i after iMarker
                                node<ITEM_TYPE>* iMarker){
    node<ITEM_TYPE>* temp = _insert_after(head, iMarker, i);
    _size++;
    return temp;
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::insert_before(ITEM_TYPE i,          //insert i before iMarker
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
ITEM_TYPE List<ITEM_TYPE>::Delete(node<ITEM_TYPE>* iMarker){
    
    ITEM_TYPE a = _delete_node(head, iMarker);
    _size--;
    return a;
}         //delete node pointed to by iMarker


template <class ITEM_TYPE>
void List<ITEM_TYPE>::Print() const{
    // node<ITEM_TYPE>* Walker = head;
    // while(Walker){
    //     cout << Walker->_item >> " -> ";
    // }
    // cout << Walker->_item;
    //cout << "sad";
    _print_list(head);
}                                 //print the list

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::search(const ITEM_TYPE &key){
    
    node<ITEM_TYPE>* temp = _search_list(head, key);
    

    return temp; 
}      //return pointer to node containing
                                                    //  key. NULL if not there

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::prev(node<ITEM_TYPE>* iMarker){
    
    node<ITEM_TYPE>* temp = _previous_node(head, iMarker);
    
    return temp; 
}    //get the previous node to iMarker


template <class ITEM_TYPE>
ITEM_TYPE& List<ITEM_TYPE>::operator[](int index){

    return _at(head, index);
}                   //return the item at index

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::begin() const{
    return head;
}                     //return the head of the list

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::end() const{
    // node<ITEM_TYPE>* temp = head;
    // for(int i = 1; i < _size; i++)
    //     temp = temp->_next;
    // return temp;
    return nullptr;
}                       

template <class U>
ostream& operator <<(ostream& outs,          //insertion operator for list
                            const List<U>& l){
    // node<U>* walker = l.head; 
    // cout << "BBBB";
    // walker = nullptr;
    // while(walker != nullptr){
    //     outs << *walker << "->";
    //     walker = walker->_next;
    //     walker = nullptr;
    // }
    // cout << "AHHH";
    // outs << "| | |";
    node<U>* walker = l.head;  
    while(walker != nullptr){
        outs << *walker << "-> ";
        walker = walker -> _next;
    }
    outs << "| | |\n";                            
    return outs;
}

#endif