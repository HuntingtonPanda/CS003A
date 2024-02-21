    #include "mcounter.h"
    #include "assert.h"
    
    MCounter::MCounter(){
        _count = 0;
        _error = false;
    }

    int MCounter::add_1(){
        add(1);
        return count();
    }                //increment functions

    int MCounter::add_10(){
        add(10);
        return count();
    }

    int MCounter::add_100(){
        add(100);
        return count();
    }

    int MCounter::add_1000(){
        add(1000);
        return count();
    }

    int MCounter::reset(){
        _count = 0;
        _error = false;
    }                //reset error  state, _count

    int MCounter::count() const{
        return _count;
    }          //returns _count

    bool MCounter::error() const{
        return _error;
    }         //returns _error

    bool MCounter::is_error() const{
        if(count() > 9999 || count() < 0){
            return true;
        }
        return false;
    }      //true  if an error has occurred


    int MCounter::add(int n){
        if (!_error)
            _count += n;
        _error = is_error(); 
        if (_error)
            _count = -9999;
    }             //add n to _count
