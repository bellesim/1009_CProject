#include "Game.h"
#include "Animation.h"
#include "Actor.h"
#include "Spaceship.h"
#include "Projectile.h"
#include "Enemy.h"
#include "AssetManager.h"
#include "Enums.h"

// WINDOWS
// ??
// MAC
// g++ main.cpp Animation.cpp Position.cpp Actor.cpp Projectile.cpp Enemy.cpp Spaceship.cpp AssetManager.cpp Game.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system
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
    Animation enemyProjectileAnim(enemyProjectileTextures, 4);

    // Set enemy textures.
    vector<Texture> enemyTextures = assetManager.getEnemyTextures();
    Animation enemyAnim(enemyTextures, 4);

    // Create Spaceship.
    Spaceship *spaceship = new Spaceship();
    spaceship->settings(spaceshipAnim, leftSpaceshipAnim, rightSpaceshipAnim, explosionAnim,
                        (WIDTH + 20) / 2, ((HEIGHT + 20) / 4) * 3);

    // Create test enemy.
    Enemy *enemy = new Enemy();
    enemy->settings(enemyAnim, 200, 200);

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

        // Shoot only when spaceship is alive.
        if (spaceship->getCurrentStatus() == ALIVE || spaceship->getCurrentStatus() == INVULNERABLE)
        {
            Projectile *projectile = spaceship->shoot(spaceshipProjectileAnim);
            if (projectile != NULL)
                projectiles.push_back(projectile);
        }

        // Enemy shoot.
        Projectile *enemyProjectile = enemy->shoot(enemyProjectileAnim);
        if (enemyProjectile != NULL)
            projectiles.push_back(enemyProjectile);

        // Draw background.
        app.draw(background);

        // Draw, check if outside of screen and whether it collide with other actors.
        vector<Projectile *>::iterator projectileIt = projectiles.begin();
        while (projectileIt != projectiles.end())
        {
            (*projectileIt)->draw(app);
            (*projectileIt)->update();

            Position projectilePosition = (*projectileIt)->getPosition();

            if ((*projectileIt)->getOrigin() == "enemy")
            {
                if (spaceship->isCollide(projectilePosition.getX(), projectilePosition.getY()))
                {
                    printf("PROJECTILE COLLIDED \n");
                    spaceship->deductHitPoint(1);
                }
            }
            else if ((*projectileIt)->getOrigin() == "spaceship")
            {
                if (enemy->isCollide(projectilePosition.getX(), projectilePosition.getY()))
                {
                    printf("ENEMY PROJECTILE COLLIDED \n");
                    enemy->deductHitPoint(1);
                }
            }

            // Erase projectile if projectile is outside of screen or hit enemy.
            if ((*projectileIt)->getHitPoints() <= 0)
            {
                projectileIt = projectiles.erase(projectileIt);
            }

            else
                ++projectileIt;
        }

        enemy->draw(app);
        enemy->update();

        spaceship->draw(app);
        spaceship->update();

        //detect collision with enemy.
        Position en = enemy->getPosition();
        if (spaceship->isCollide(en.getX(), en.getY()))
        {
            printf("\nenemy collide with spaceship");
            spaceship->deductHitPoint(1);
        }

        text.setString("Hit points left: " + to_string(spaceship->getHitPoints()) +
                       "\nScore: " + to_string(spaceship->getScore()));
        app.draw(text);

        app.display();
    }
}
