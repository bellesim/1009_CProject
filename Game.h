#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <math.h>
#include <iostream>

using namespace std;
using namespace sf;

class Game
{
public:
    bool up, down, left, right;
    Game();
    void run();

private:
    RenderWindow app;
    Sprite background;
    static const int WIDTH = 1050;
    static const int HEIGHT = 1150;
    static const int gameSpeed = 1000;
};