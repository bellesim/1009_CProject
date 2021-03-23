#include "Game.h"
#include "Animation.h"
#include "Actor.h"
#include "Spaceship.h"

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
    vector<Texture> spaceshipTextures;
    for (int i = 0; i < 2; i++)
    {
        Texture texture;
        texture.loadFromFile("images/spaceship/spaceship_straight" +
                             to_string((i + 1)) + ".png");
        spaceshipTextures.push_back(texture);
    }
    Animation spaceshipAnim(spaceshipTextures);

    // Set left spaceship textures.
    vector<Texture> leftSpaceshipTextures;
    for (int i = 0; i < 2; i++)
    {
        Texture texture;
        texture.loadFromFile("images/spaceship/spaceship_left" +
                             to_string((i + 1)) + ".png");
        leftSpaceshipTextures.push_back(texture);
    }
    Animation leftSpaceshipAnim(leftSpaceshipTextures);

    // Set right spaceship textures.
    vector<Texture> rightSpaceshipTextures;
    for (int i = 0; i < 2; i++)
    {
        Texture texture;
        texture.loadFromFile("images/spaceship/spaceship_right" +
                             to_string((i + 1)) + ".png");
        rightSpaceshipTextures.push_back(texture);
    }
    Animation rightSpaceshipAnim(rightSpaceshipTextures);

    // Set right explosion textures.
    vector<Texture> explosionTextures;
    for (int i = 0; i < 48; i++)
    {
        Texture texture;
        texture.loadFromFile("images/explosions/explosion_1/explosion_" +
                             to_string((i + 1)) + ".png");
        explosionTextures.push_back(texture);
    }
    Animation explosionAnim(explosionTextures);

    // Create Spaceship.
    Spaceship *spaceship = new Spaceship();
    spaceship->settings(spaceshipAnim, leftSpaceshipAnim, rightSpaceshipAnim,
                        (WIDTH + 20) / 2, ((HEIGHT + 20) / 4) * 3);

    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();

            spaceship->keyPressed();
        }

        app.draw(background);
        spaceship->draw(app);
        spaceship->update();
        app.display();
    }
}
