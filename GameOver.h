#pragma once

#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enums.h"
#include "State.h"

using namespace std;
using namespace sf;

class GameOver : public State
{
private:
    int endScore;
    Sprite background;
    RectangleShape buttonS;
    RectangleShape buttonE;

public:
    GameOver();
    void run(RenderWindow &app, Event event, GameState &gameState);
    void state(RenderWindow &app);
    void setEndScore(int score);
};