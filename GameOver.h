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
    void run(RenderWindow &app, Event event, GameState &gameState, int endScore);
    void GameOverState(RenderWindow &app, int endScore);

private:
    Sprite background;
    RectangleShape buttonS;
    RectangleShape buttonE;
};