#include "Game.h"
#include "Animation.h"
#include "Actor.h"

Game::Game() : app(VideoMode(WIDTH, HEIGHT), "Ace Combat", Style::Default)
{
    app.setFramerateLimit(60);
}

void Game::run()
{
    // Set background texture.
    Texture backgroundTexture;
    backgroundTexture.loadFromFile("images/background.jpg");
    background.setTexture(backgroundTexture);

    // Texture explosionTexture;
    // explosionTexture.loadFromFile("images/explosions/type_B.png");
    // Animation explosion(explosionTexture, 0, 0, 192, 192, 64, 0.5);

    Texture spaceshipTexture;
    spaceshipTexture.loadFromFile("images/spaceship.png");
    Animation sPlayer(spaceshipTexture, 40, 0, 40, 40, 1, 0);

    Actor *actor = new Actor();
    actor->settings(sPlayer, 200, 200, 0, 20);

    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                app.close();
        }

        app.draw(background);
        // app.draw(explosion.sprite);
        actor->draw(app);
        // app.draw(actor->anim.sprite);
        app.display();
    }
}
