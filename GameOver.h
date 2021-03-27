#pragma once

#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class GameOverMenu
{
public:
    GameOverMenu();
    void run();

private:
    RenderWindow main;
    Sprite background;
    static const int WIDTH = 1050;
    static const int HEIGHT = 1150;
};