#ifndef RIGHTPAREN_H
#define RIGHTPAREN_H

#include <iostream>
#include <iomanip>
#include "assert.h"

#include "token.h"
#include "constant.h"


class RightParen:public Token{
    public:
        RightParen(const string& n=")"):Token(n, RIGHTPARENTH){}
};

#endif