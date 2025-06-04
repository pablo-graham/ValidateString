//
// Created by Pablo Ruiz on 5/20/25.
//

#ifndef MALENATEST_STATE_H
#define MALENATEST_STATE_H

#include <iostream>
#include <string>

using namespace std;
struct States{
    char ch;
    enum STATE  {START, VALID, INVALID,};
    STATE self;
    string board;


    States(){}


    void setState(STATE stateInput){
        self = stateInput;
    }

    STATE getState(){
        return self;
    }
};


#endif //MALENATEST_STATE_H
