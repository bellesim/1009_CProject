#pragma once

#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class MainMenu
{
public:
    MainMenu();
    void run();

private:
    RenderWindow main;
    static const int WIDTH = 1050;
    static const int HEIGHT = 1150;
    //std::list<MenuItem> _menuItems;
};