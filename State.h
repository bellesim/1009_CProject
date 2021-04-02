#pragma once

#include "Enums.h"

class State
{
public:
    virtual void run(RenderWindow &app, Event event, GameState &gameState) = 0;
    virtual void state(RenderWindow &app) = 0;
};