
#pragma once

#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enums.h"

using namespace std;
using namespace sf;

class State
{
public:
    virtual void run(RenderWindow &app, Event event, GameState &gameState) = 0;
    virtual void state(RenderWindow &app) = 0;
};