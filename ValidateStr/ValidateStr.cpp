//
// Created by Pablo Ruiz on 5/14/25.
//

#include "ValidateStr.h"

void ValidateStr::validate(string input) {
    valid = isValidIdentifier(input);
    str = input;
}

bool ValidateStr::isValidIdentifier(const string& input) {
    // Validating input
    /// START
    state.setState(States::START);
    for(char ch : input){
        // first char check
        if(state.getState() == States::START){
            if(!(isalpha(ch) || ch == '_')){
                state.setState(States::INVALID);
                return false;
            }else{
                state.setState(States::VALID);
                continue;
            }
        // not first char check
        } else if(state.getState() == States::VALID){
            if(!(isalnum(ch) || ch == '_')){
                return false;
            }else{
                state.setState(States::VALID);
                continue;
            }
        }
    }

    /// KEYWORD check
    if (state.getState() == States::VALID && isReservedKeyword(input)) {
        return true;
    }
    return false;
}

bool ValidateStr::isReservedKeyword(const string& word) {
    // Checking if word is in the file
    ifstream inputFile("/Users/pabloruiz/CLionProjects/Validate/ValidateStr/C++ Keywords.txt");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            if(line == word){
                return false;
            }
        }
        inputFile.close();
    }

    return true;


}
