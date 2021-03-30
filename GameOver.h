#pragma once

#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enums.h"

using namespace std;
using namespace sf;

class GameOver
{
public:
    GameOver();
    void run(RenderWindow &app, Event event, GameState &gameState);
    void GameOverState(RenderWindow &app);

private:
    Sprite background;
    RectangleShape buttonS;
    RectangleShape buttonE;
};