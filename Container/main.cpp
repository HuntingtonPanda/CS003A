#include <iostream>
#include <vector>
#include "includes/stuff/container.h"
#include "includes/stuff/token.h"
#include "includes/stuff/integer.h"
#include "includes/stuff/double.h"

using namespace std;
void f(token& t){
    cout<<t<<endl;
}

int main()
{
    cout<<endl<<endl;
    Integer i(7);
    cout<<"print integer from insertion operator: "<<i<<endl;
    cout<<"printing i (Integer) ";
    i.Print();
    cout<<endl;
    Double d(3.14);
    cout<<"printing d (Double) ";
    d.Print();
    cout<<endl;
    Integer* iptr = new Integer(17);
    Double* dptr = new Double(3.77);
    cout<<"printing *iptr: Integer Pointer: ";
    iptr->Print(cout);
    cout<<endl;
    cout<<"printing *dptr: Double Pointer";
    dptr->Print(cout);
    cout<<endl;
    /*
         token* p ---> [Integer: 88 ]
         A token pointer ONLY understands token universe!
          only uderstands functions that exist in token,.
              if you want to envoke something in the child,
              the function better be virtual!
              that's why, Print must be virtual
          the call to the virtual function will go to
              the class that the pointer is pointing to, not
              the class that the pointer is from.
    */
    cout<<"----- from the parent pointer -------"<<endl;
    token* p = new Integer(88);
    p->Print(cout);
    cout<<"\n\nlet's do one with arrays:"<<endl;
    vector<token*> tokens;
    tokens.push_back(new Integer(5));
    tokens.push_back(new Double(5.5));
    for (int i=0; i<tokens.size(); i++){
        tokens[i]->Print();
        cout<<endl;
    }
    return 0;
    //--------- casting -----------------
    cout<<"calling the child -only- functions: "<<endl;
    //accessing a child -only- function from a parent pointer:
    // cast the parent pointer as a child:
    cout<<static_cast<Integer*>(tokens[0])->IntegerOnly()<<endl;
    cout<<"\n\n---------------\n\n";
    cout<<endl<<endl<<endl;

    cout<<"+++++++++ container: ++++++++"<<endl;
    //container of pointers to parent class:
    Container<token*> c;

    //Adding pointers to child classes to the container:
    token* hold;
    hold = new Integer(54);
    c.Add(hold );

    c.Add(new Double("3.1415"));


    cout<<c.Length()<<endl;
    cout<<"elements in the container: ";
    for (int i=0; i<c.Length(); i++){
        cout<<*c[i]<<"    ";  //what is cout seeing?

        //calls << which calls the child's Print virtual function

        //calling virtual functions present in parent
        //token pointer -> integer object
        //arrow operator thinks that the object is a token,
        //      not an integer
        //but the programmer wants to look at the typeof function
        //  in the child object not in the parent object.

        switch(c[i]->TypeOf()){


        //this is how you call functions in the child that do not exist
        // in the parent:
        case INTEGER: cout<<"Function from Integer: "<<
                static_cast<Integer*>(c[i])->IntegerOnly()<<endl;
            break;
        case DOUBLE: cout<<"Function from Double: "<<
                static_cast<Double*>(c[i])->DoubleOnly()<<endl;
            break;
        }
    }
    cout<<endl;

//    Q<Token*> postfix;
//    postfix.push(new Integer(5));
//    postfix.push(new Integer(3));
//    postfix.push(new Operator('*'));

//    while (!postfix.empty()){
//        p = postfix.pop()


//    }



    cout <<endl<<endl<<endl<<"-------------------------------" << endl;
    return 0;
}

