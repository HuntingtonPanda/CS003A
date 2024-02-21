#ifndef RPN_H
#define RPN_H
#include <iostream>
#include <iomanip>
#include <cmath>
#include "assert.h"

#include "../node/node.h"
#include "../linked_list_functions/linked_list_functions.h"
#include "../queue/MyQueue.h"
#include "../stack/MyStack.h"
#include "../token/operator.h"
#include "../token/function.h"
#include "../token/constant.h"


#include "../token/token.h"

using namespace std;

class RPN{
    public:
    RPN();
    RPN(Queue<Token*> a);
    void set_input(Queue<Token*> a);

    double operator()(double varValue = 0);

    //double rpn(int varValue);


    private:
        Queue<Token *> _postfix;
};

#endif