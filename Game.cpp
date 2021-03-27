#include "Game.h"
#include "Animation.h"
#include "Actor.h"
#include "Spaceship.h"
#include "Projectile.h"
#include "AssetManager.h"
#include "SoundMaster.h"

// WINDOWS
// ???
// MAC
// g++ main.cpp Animation.cpp Actor.cpp Spaceship.cpp AssetManager.cpp Game.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
// g++ main.cpp Animation.cpp Actor.cpp Projectile.cpp Spaceship.cpp AssetManager.cpp Game.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
Game::Game() : app(VideoMode(WIDTH, HEIGHT), "Ace Combat", Style::Default)
{
    app.setFramerateLimit(60);
}

void Game::run()
{
    AssetManager assetManager;
    // Set background texture.

    SoundMaster soundguy;
    // Load in audio.

    Texture backgroundTexture = assetManager.getBackgroundTexture();
    background.setTexture(backgroundTexture);

    // Set spaceship textures.
    vector<Texture> spaceshipTextures = assetManager.getSpaceshipTextures();
    Animation spaceshipAnim(spaceshipTextures, 2);

    // Set left spaceship textures.
    vector<Texture> leftSpaceshipTextures = assetManager.getSpaceshipLeftTextures();
    Animation leftSpaceshipAnim(leftSpaceshipTextures, 2);

    // Set right spaceship textures.
    vector<Texture> rightSpaceshipTextures = assetManager.getSpaceshipRightTextures();
    Animation rightSpaceshipAnim(rightSpaceshipTextures, 2);

    // Set right explosion textures.
    vector<Texture> explosionTextures = assetManager.getExplosionTextures();
    Animation explosionAnim(explosionTextures);

    // Set projectile textures.
    vector<Texture> projectileTextures = assetManager.getProjectileTextures();
    Animation projectileAnim(projectileTextures);

    // Create Spaceship.
    Spaceship *spaceship = new Spaceship();
    spaceship->settings(spaceshipAnim, leftSpaceshipAnim, rightSpaceshipAnim,
                        (WIDTH + 20) / 2, ((HEIGHT + 20) / 4) * 3);

    // Projectile *projectile = new Projectile(true, false, false, false);
    // projectile->settings(projectileAnim, (WIDTH + 20) / 2, ((HEIGHT + 20) / 4) * 3);
    vector<Projectile *> projectiles;
    // Setting up font for score and life.
    Text text;
    Font font = assetManager.getFont();
    text.setFont(font);
    text.setCharacterSize(32);
    text.setFillColor(Color::Red);
    text.setPosition(30, 30);

    // audio test section until more events to hook into are available
    soundguy.playGame();
    // soundguy.playFire();

    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();

            spaceship->keyPressed();
            // just to test, this thing is noisy af
            // soundguy.playFire();
        }

        Projectile *projectile = spaceship->shoot(projectileAnim);
        if (projectile != NULL)
            projectiles.push_back(projectile);
        else
            // printf("is null");

        app.draw(background);

        vector<Projectile *>::iterator projectileIt = projectiles.begin();
        while (projectileIt != projectiles.end())
        {
            (*projectileIt)->draw(app);
            (*projectileIt)->update();
            // printf("%d\n", (*projectileIt)->getHitPoints());
            if ((*projectileIt)->getHitPoints() <= 0)
            {
                // printf("delete");
                projectileIt = projectiles.erase(projectileIt);
            }

            else
                ++projectileIt;
        }

        spaceship->draw(app);
        spaceship->update();

        text.setString("Hit points left: " + to_string(spaceship->getHitPoints()) +
                       "\nScore: " + to_string(spaceship->getScore()));
        app.draw(text);

        app.display();
    }
}
