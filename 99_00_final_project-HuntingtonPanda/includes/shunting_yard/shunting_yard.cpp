#include "shunting_yard.h"
#include "assert.h"

ShuntingYard::ShuntingYard(): _infix(), _postfix(){}

ShuntingYard::ShuntingYard(Queue<Token*> preFix): _infix(preFix), _postfix(){infix(_infix);}
    
void ShuntingYard::infix(Queue<Token*> preFix){   
    while(!(_postfix.empty())){
        _postfix.pop();
    }
    _infix = preFix;

    Stack<Token*> stack;
    typename Stack<Token*>:: Iterator stackIt;

    Token* tokenIt;

    Operator* queueOper;
    Operator* stackOper = 0;

    Function* queueFunc;

    int currentPrec;

    done:while(preFix.begin() != preFix.end()){
        tokenIt = preFix.pop();
        switch(tokenIt->type()){
            case INTEGER: _postfix.push(tokenIt); //tokenIt is a pointer but push wants a item
                          break;
            
            case OPERATION:
                 currentPrec = 0;

                 queueOper = static_cast<Operator*> (tokenIt);
                 if(queueOper -> get_prec() == POWER){
                    stack.push(queueOper);
                    goto done;
                 }

                 while(!stack.empty() && stack.top()->type() == FUNCTION){
                    _postfix.push(stack.pop());    
                 }

                 while(!stack.empty() && stack.top()->type() != LEFTPARENTH){
                    stackOper = static_cast<Operator*> (stack.top());
                    currentPrec = stackOper -> get_prec();
                    if(queueOper -> get_prec() <= currentPrec){
                        _postfix.push(stack.pop());
                    }else{
                        stack.push(queueOper);
                        goto done;
                    }
                 }
                 
                 stack.push(queueOper);
                 break;
            
            case LEFTPARENTH:
                stack.push(tokenIt);
                currentPrec = 0;
                break;

            case RIGHTPARENTH: 
                while((stack.top())->type() != LEFTPARENTH){
                    _postfix.push(stack.pop());
                }
                stack.pop();
                break;

            case FUNCTION:
                queueFunc = static_cast<Function*>(tokenIt);
                if(queueFunc -> getIsVariable())
                    _postfix.push(tokenIt); //tokenIt is a pointer but push wants a item
                else{
                    stack.push(tokenIt);
                }
                break;
            default:
                assert(false);
        }

    }

    while(!stack.empty()){
        stackOper = static_cast<Operator*> (stack.pop());
        _postfix.push(stackOper);
    }   
}


Queue<Token*> ShuntingYard::postfix(){
    return _postfix;
}


Queue<Token*> ShuntingYard::postfix(Queue<Token*> preFix){
    infix(preFix);
    return _postfix;
}

void ShuntingYard::print(){
    for (Queue<Token *>::Iterator it = _postfix.begin(); it != _postfix.end(); it++){
        cout <<setw(3)<< *it;
    } 
    cout << "\n\n";
}