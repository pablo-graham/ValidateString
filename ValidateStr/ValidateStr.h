//
// Created by Pablo Ruiz on 5/14/25.
//

#ifndef MALENATEST_VALIDATESTR_H
#define MALENATEST_VALIDATESTR_H

#include "Malena/common.hpp"
#include "State/State.h"
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
class ValidateStr : public ml::RectangleButton{
private:
    string str;
    bool valid;
    States state;


    sf::Vector2f position;


    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        // Drawing valid/invalid based on input
        if(!str.empty() && valid){
            sf::Text text(ml::FontManager::getDefault(), "valid");
            text.setPosition({position.x, position.y});
            target.draw(text, states);
        }else if(!str.empty() && !valid){
            sf::Text text(ml::FontManager::getDefault(), "not valid");
            text.setPosition({position.x, position.y});
            target.draw(text, states);
        }
    }

public:

    ValidateStr() : str(""){ state.setState(States::START); }
    ValidateStr(string input) : str(input) { validate(input); }
    void validate(string input);

    bool isValidIdentifier(const string& input);
    bool isReservedKeyword(const string& input);


    void setPosition(const sf::Vector2f& pos){ position = pos; }

};


#endif //MALENATEST_VALIDATESTR_H
