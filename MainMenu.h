#pragma once

#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enums.h"
#include "State.h"

using namespace std;
using namespace sf;

class MainMenu : public State
{
public:
    MainMenu();
    void run(RenderWindow &app, Event event, GameState &gameState);
    void state(RenderWindow &app);

private:
    Sprite background;
    RectangleShape buttonS;
    RectangleShape buttonE;
};