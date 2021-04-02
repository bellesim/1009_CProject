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
private:
    RenderWindow app;
    Sprite background;

public:
    static const int TOTAL_ENEMIES = 20;
    static const int WIDTH = 1050;
    static const int HEIGHT = 1150;
    static const int gameSpeed = 1000;
    bool up, down, left, right;
    Game();
    void run();
};