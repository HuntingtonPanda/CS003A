#include "counter_type.h"
#include "assert.h"


Counter_Type::Counter_Type(){
    _count = 0;
    _error = false;
}
Counter_Type::Counter_Type(int n){
    _count = n;
    _error = is_error();
}            //set initial value of the counter
bool Counter_Type::inc(){
    if(_error)
        return false;
    _count++;
    return true;
}                     //increment by one
bool Counter_Type::dec(){
    _count--;
    _error = is_error();

    return _error;
}                     //decrement by one
bool Counter_Type::is_error() const{
    if(_count < 0)
        return true;
    else
        return false;
}          //true: the object is in error (underflow)
bool Counter_Type::reset(){
    _count = 0;
    _error = 0;
    return true;
}                   //reset _count to zero and _error to false
int Counter_Type::count() const{
    return _count;
}              //retrieve the _count
