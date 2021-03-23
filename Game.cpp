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

    // Set spaceship textures.
    vector<Texture> textures;
    for (int i = 0; i < 2; i++)
    {
        Texture texture;
        texture.loadFromFile("images/spaceship/spaceship_straight" +
                             to_string((i + 1)) + ".png");
        textures.push_back(texture);
    }
    Animation spaceshipAnim(textures);

    Actor *actor = new Actor();
    actor->settings(spaceshipAnim, (WIDTH + 20) / 2, ((HEIGHT + 20) / 4) * 3);

    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
            actor->keyPressed();
        }

        app.draw(background);
        actor->draw(app);
        actor->update();
        app.display();
    }
}
