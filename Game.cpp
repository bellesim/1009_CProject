#include "Game.h"

using namespace sf;
using namespace std;

Game::Game() : app(sf::VideoMode(WIDTH, HEIGHT), "Ace Combat", sf::Style::Default)
{
    app.setFramerateLimit(60);
}

void Game::run()
{
    // Set background texture.
    Texture backgroundTexture;
    backgroundTexture.loadFromFile("images/background.jpg");
    background.setTexture(backgroundTexture);

    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                app.close();
        }

        app.clear();
        app.draw(background);
        app.display();
    }
}
