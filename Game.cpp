#include "Game.h"
#include "Animation.h"
#include "Actor.h"
#include "Spaceship.h"
#include "Projectile.h"
#include "Formation.h"
#include "AssetManager.h"
#include "Enums.h"

// WINDOWS
// ??
// MAC
// g++ main.cpp Animation.cpp Position.cpp Actor.cpp Spaceship.cpp AssetManager.cpp Game.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system
// g++ main.cpp Animation.cpp Position.cpp Formation.cpp Actor.cpp Projectile.cpp Enemy.cpp Spaceship.cpp AssetManager.cpp Game.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system

Game::Game() : app(VideoMode(WIDTH, HEIGHT), "Ace Combat", Style::Default)
{
    app.setFramerateLimit(60);
}

void Game::run()
{
    AssetManager assetManager;

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

    // Set spaceship projectile textures.
    vector<Texture> spaceshipProjectileTextures = assetManager.getSpaceshipProjectileTextures();
    Animation spaceshipProjectileAnim(spaceshipProjectileTextures);

    // Set enemy projectile textures.
    vector<Texture> enemyProjectileTextures = assetManager.getEnemyProjectileTextures();
    Animation enemyProjectileAnim(enemyProjectileTextures, 3);

    // Set enemy textures.
    vector<Texture> enemyTextures = assetManager.getEnemyTextures();
    Animation enemyAnim(enemyTextures, 4);

    // Create Spaceship.
    Spaceship *spaceship = new Spaceship();
    spaceship->settings(spaceshipAnim, leftSpaceshipAnim, rightSpaceshipAnim,
                        (WIDTH + 20) / 2, ((HEIGHT + 20) / 4) * 3);

    vector<Projectile *> projectiles;

    vector<Enemy *> enemies;

    // Setting up font for score and life.
    Text text;
    Font font = assetManager.getFont();
    text.setFont(font);
    text.setCharacterSize(32);
    text.setFillColor(Color::Red);
    text.setPosition(30, 30);

    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();

            spaceship->keyPressed();
        }

        // Draw background.
        app.draw(background);

        // Handle create enemy projectile and destroy.
        vector<Enemy *>::iterator enemyIt = enemies.begin();
        while (enemyIt != enemies.end())
        {
            Projectile *enemyProjectile = (*enemyIt)->shoot(enemyProjectileAnim);
            if (enemyProjectile != NULL)
                projectiles.push_back(enemyProjectile);

            // Draw enemy.
            (*enemyIt)->draw(app);
            (*enemyIt)->update();
            // if ((*enemyIt)->getHitPoints() <= 0)
            // {
            //     enemyIt = enemies.erase(enemyIt);
            // }
            ++enemyIt;
            // else ++enemyIt;
        }
        printf("\n%d", TOTAL_ENEMIES - enemies.size());
        if (enemies.size() < (TOTAL_ENEMIES / 10) * 8)
        {
            vector<Enemy *> newEnemies = Formation::generateRandomFormation((TOTAL_ENEMIES - enemies.size()),
                                                                            enemyAnim);
            enemies.insert(enemies.end(), newEnemies.begin(), newEnemies.end());
        }

        // Handle create spaceship projectile.
        Projectile *projectile = spaceship->shoot(spaceshipProjectileAnim);
        if (projectile != NULL)
            projectiles.push_back(projectile);

        // Draw all projectile.
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

        // Draw spaceship.
        spaceship->draw(app);
        spaceship->update();

        text.setString("Hit points left: " + to_string(spaceship->getHitPoints()) +
                       "\nScore: " + to_string(spaceship->getScore()));
        app.draw(text);

        app.display();
    }
}