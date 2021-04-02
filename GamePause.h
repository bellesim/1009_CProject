#pragma once

#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enums.h"
#include "State.h"

using namespace std;
using namespace sf;

class GamePause : public State
{
private:
    Sprite background;
    RectangleShape buttonC;
    RectangleShape buttonE;

public:
    GamePause();
    void run(RenderWindow &app, Event event, GameState &gameState);
    void state(RenderWindow &app);
};