#include "Game.h"
#include "Animation.h"
#include "Actor.h"
#include "Spaceship.h"
#include "Projectile.h"
#include "Formation.h"
#include "AssetManager.h"
#include "Enums.h"
#include "MainMenu.h"
#include "GamePause.h"
#include "GameOver.h"
// WINDOWS
// ??
// MAC
// g++ -std=c++11 main.cpp MainMenu.cpp GamePause.cpp GameOver.cpp Animation.cpp Position.cpp Actor.cpp Projectile.cpp Enemy.cpp Formation.cpp Spaceship.cpp AssetManager.cpp Game.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system
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
    spaceship->settings(spaceshipAnim, leftSpaceshipAnim, rightSpaceshipAnim, explosionAnim,
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

    MainMenu menu;
    GamePause pauseMenu;
    GameOver overMenu;
    int endScore;
    
    while (app.isOpen())
    {
        Event event;
        if (gameState == MAIN_MENU)
        {
            printf("Main menu\n");
            menu.run(app, event, gameState);
        }

        else if (gameState == GAME_PLAY || gameState == GAME_REPLAY)
        {
            if (spaceship->getCurrentStatus() == DEAD)
            {
                endScore = spaceship->getScore();
                gameState = GAME_OVER;
            }
            printf("Game play\n");

            while (app.pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    app.close();
                }

                if (Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    printf("Esc button clicked");
                    gameState = GAME_PAUSE;
                }

                spaceship->keyPressed();
            }
            // Draw background.
            app.draw(background);

            // Handle enemies generation.
            if (enemies.size() < (TOTAL_ENEMIES / 10) * 8)
            {
                printf("\ngen");
                vector<Enemy *> newEnemies = Formation::generateRandomFormation((TOTAL_ENEMIES - enemies.size()),
                                                                                enemyAnim, explosionAnim);
                enemies.insert(enemies.end(), newEnemies.begin(), newEnemies.end());
            }

            printf("\n enemies size %d", enemies.size());
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

                // Destroy enemy less than 0.
                if ((*enemyIt)->getCurrentStatus() == DEAD)
                {
                    enemyIt = enemies.erase(enemyIt);
                }
                else
                    ++enemyIt;
            }

            // Shoot only when spaceship is alive.
            if (spaceship->getCurrentStatus() == ALIVE || spaceship->getCurrentStatus() == INVULNERABLE)
            {
                Projectile *projectile = spaceship->shoot(spaceshipProjectileAnim);
                if (projectile != NULL)
                    projectiles.push_back(projectile);
            }

            // Draw all projectile.
            vector<Projectile *>::iterator projectileIt = projectiles.begin();
            while (projectileIt != projectiles.end())
            {
                bool hit = false;

                (*projectileIt)->draw(app);
                (*projectileIt)->update();

                Position projectilePosition = (*projectileIt)->getPosition();

                if ((*projectileIt)->getOrigin() == "enemy" && !hit)
                {
                    if (spaceship->isCollide(projectilePosition.getX(), projectilePosition.getY()))
                    {
                        printf("PROJECTILE COLLIDED \n");
                        spaceship->deductHitPoint(1);
                        hit = true;
                    }
                }
                else if ((*projectileIt)->getOrigin() == "spaceship" && !hit)
                {
                    for (Enemy *enemy : enemies)
                    {
                        if (enemy->isCollide(projectilePosition.getX(), projectilePosition.getY()))
                        {
                            printf("ENEMY PROJECTILE COLLIDED \n");
                            spaceship->addToScore(50);
                            enemy->deductHitPoint(1);
                            hit = true;
                        }
                    }
                }

                // Erase projectile if projectile is outside of screen or hit enemy.
                if (hit)
                    projectileIt = projectiles.erase(projectileIt);
                else
                    ++projectileIt;
            }

            // Draw spaceship.
            spaceship->draw(app);
            spaceship->update();

            //detect collision with enemy.
            for (Enemy *enemy : enemies)
            {
                Position en = enemy->getPosition();
                if (spaceship->isCollide(en.getX(), en.getY()))
                {
                    printf("\nenemy collide with spaceship");
                    spaceship->deductHitPoint(1);
                }
            }

            text.setString("Hit points left: " + to_string(spaceship->getHitPoints()) +
                           "\nScore: " + to_string(spaceship->getScore()));
            app.draw(text);
        }

        else if (gameState == GAME_PAUSE)
        {
            printf("game paused\n");
            pauseMenu.run(app, event, gameState);
        }

        else if (gameState == GAME_OVER)
        {
            printf("game over\n");
            overMenu.run(app, event, gameState, endScore);

            projectiles.clear();
            enemies.clear();
            spaceship = new Spaceship();

            spaceship->settings(spaceshipAnim, leftSpaceshipAnim, rightSpaceshipAnim, explosionAnim,
                                (WIDTH + 20) / 2, ((HEIGHT + 20) / 4) * 3);
        }

        app.display();
    }
}