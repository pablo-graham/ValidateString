//
// Created by Pablo Ruiz on 5/12/25.
//

#ifndef MALENATEST_TEXTINPUT_H
#define MALENATEST_TEXTINPUT_H
#include "Malena/common.hpp"
#include "Malena/Graphics/TextInput.h"
#include "../ValidateStr/ValidateStr.h"

using namespace std;
class TextInput : public ml::Application {
    ml::RectangleButton box1;
    ml::Typer typer;
    ml::Cursor cursor;
    sf::Vector2f pos;
    sf::Vector2f cursorPosition;

    string str;
    ValidateStr validate;

public:
    TextInput();
    void initialization() override;
    void registerEvents() override;
};


#endif //MALENATEST_TEXTINPUT_H
