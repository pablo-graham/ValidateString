//
// Created by Pablo Ruiz on 5/12/25.
//

#include "TextInput.h"
#include "Malena/Utilities//TextManipulators.h"

TextInput::TextInput() : Application(sf::VideoMode({720, 420}, 32), "Text Input", *this)
{}

void TextInput::initialization() {
    box1.setSize({200, 75});
    box1.setPosition({100, 100});
    box1.setFillColor({37,150,190});

    validate.setPosition({box1.getPosition().x, box1.getPosition().y + box1.getSize().y});

    typer.enableState(ml::Stateful::ENABLED);
    typer.enableState(ml::Stateful::HIDDEN);
    typer.setPosition(sf::Vector2f(100, 100));
    typer.setFillColor(sf::Color::Black);

    cursor.setPosition({100, 100});
    cursor.disableState(ml::Stateful::BLINKING);
    cursor.enableState(ml::Stateful::HIDDEN);
    cursor.setFillColor(sf::Color::Black);


    addComponent(box1);
    addComponent(typer);
    addComponent(cursor);
    addComponent(validate);
}

void TextInput::registerEvents() {
    auto f = [this](ml::RectangleButton& box, const string& text)
    {
        return [&box, this, text]()
        {
            box.enableState(ml::Stateful::FOCUSED);
            box.sf::RectangleShape::setOutlineColor(sf::Color::Blue);

            typer.setString(text);
            typer.enableState(ml::Stateful::ENABLED);

            cursor.enableState(ml::Stateful::ENABLED);
            cursor.enableState(ml::Stateful::BLINKING);
            cursorPosition = typer.findCharacterPos(str.size());
            cursor.setPosition({cursorPosition.x + 5, box1.getPosition().y});

            validate.validate(str);
        };
    };

    box1.onClick(f(box1, str));



    box1.onBlur([this]() {
                    str = typer.getString();
                    typer.disableState(ml::Stateful::ENABLED);
                    cursor.disableState(ml::Stateful::BLINKING);
                    cursor.disableState(ml::Stateful::ENABLED);
                    cursor.enableState(ml::Stateful::HIDDEN);
                    box1.sf::RectangleShape::setOutlineColor(sf::Color::Black);
                });

    typer.onUpdate([this]()
                   {
                       if(box1.checkState(ml::Stateful::FOCUSED))
                       {
                           str = typer.getString();

                           pos = cursor.getPosition();
                           cursorPosition = typer.findCharacterPos(str.size());


                           cursor.setPosition(sf::Vector2f(cursorPosition.x + 5, pos.y));
                           typer.disableState(ml::Stateful::HIDDEN);
                           validate.validate(str);
                       }

                   });
}