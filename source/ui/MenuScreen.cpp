//
//  MenuScreen.cpp
//  Rac0r
//
//  Created by Jannes on Jun/13/13.
//  Copyright (c) 2013 Jan Schulte. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "MenuScreen.h"

#include "ResourcePath.hpp"

using namespace std;

MenuScreen::MenuScreen(const Rect& frame) : Screen(frame) {
    
    
}




void MenuScreen::handleEvent(sf::Event event) {
    bool down = (event.type == sf::Event::KeyPressed);
    bool up = (event.type == sf::Event::KeyReleased);
    if (down && event.key.code == sf::Keyboard::Down) {
    }
    else if (up && event.key.code == sf::Keyboard::Up)
    {
        if (Screen::playerCount < 5){
            Screen::playerCount++;
        }
        cout << "ein Spieler mehr " << Screen::playerCount << endl;
    }
    else if (up && event.key.code == sf::Keyboard::Down)
    {
        if (Screen::playerCount > 1){
            Screen::playerCount--;
        }
        cout << "ein Spieler weniger " << Screen::playerCount << endl;
    }
    else if (up && event.key.code == sf::Keyboard::Right)
    {
        if (Screen::trackNumber < 5){
            Screen::trackNumber++;
        }
        cout << "Ein Track weiter " << Screen::trackNumber << endl;
    }
    else if (up && event.key.code == sf::Keyboard::Left)
    {
        if (Screen::trackNumber > 1){
            Screen::trackNumber--;
        }
        cout << "Ein Track zurück " << Screen::trackNumber << endl;
    }
    if (up && event.key.code == sf::Keyboard::Return) {
        Screen::finished = true;
    }
}


void MenuScreen::exit() {
    Screen::exit = true;
}
