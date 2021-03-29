#include "Game.h"
#include "Animation.h"
#include "Actor.h"
#include "Spaceship.h"
#include "Projectile.h"
#include "AssetManager.h"
#include "Enums.h"
#include "MainMenu.h"
#include "GamePause.h"
#include "GameOver.h"

// WINDOWS
// ??
// MAC
// g++ main.cpp Animation.cpp Actor.cpp Spaceship.cpp AssetManager.cpp Game.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system
// g++ main.cpp Animation.cpp Actor.cpp Projectile.cpp Spaceship.cpp AssetManager.cpp Game.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system
Game::Game() : app(VideoMode(WIDTH, HEIGHT), "Ace Combat", Style::Default)
{
    app.setFramerateLimit(60);
}

void Game::run()
{
    AssetManager assetManager;
    GameState gameState = MAIN_MENU;
    // Set background texture.

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

    MainMenu menu;
    GamePause pauseMenu;

    while (app.isOpen())
    {
        Event event;

        if (gameState == MAIN_MENU)
        {
            printf("main menu\n");
            menu.run(app, event, gameState);
        }

        else if (gameState == GAME_PLAY || gameState == GAME_REPLAY)
        {
            printf("game play\n");
            while (app.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    app.close();
            }

            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                printf("Esc button clicked");
                gameState = GAME_PAUSE;
            }

            spaceship->keyPressed();

            if (spaceship->getCurrentStatus() == ALIVE || spaceship->getCurrentStatus() == INVULNERABLE)
            {
                Projectile *projectile = spaceship->shoot(projectileAnim);
                if (projectile != NULL)
                    projectiles.push_back(projectile);
            }

            app.draw(background);

            vector<Projectile *>::iterator projectileIt = projectiles.begin();
            while (projectileIt != projectiles.end())
            {
                (*projectileIt)->draw(app);
                (*projectileIt)->update();
                if ((*projectileIt)->getHitPoints() <= 0)
                {
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
        }

        else if (gameState == GAME_PAUSE)
        {
            printf("game paused\n");
            pauseMenu.run(app, event, gameState);
        }

        app.display();
    }
}
