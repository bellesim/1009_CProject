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
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;

public:
    Game();
    void run();

private:
    sf::RenderWindow app;
    sf::Sprite background;
    static const int WIDTH = 1050;
    static const int HEIGHT = 1150;
    static const int gameSpeed = 1000;
};