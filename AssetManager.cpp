#include "AssetManager.h"

AssetManager::AssetManager()
{
    try
    {
        // Load game music.
        if (!gamemusic.openFromFile("assets/music/game.wav"))
            throw runtime_error("assets/music/game.wav");

        // Load enemy fire sound.
        if (!efire.loadFromFile("assets/sounds/enemyfire.wav"))
            throw runtime_error("assets/sounds/enemyfire.wav");

        // Load enemy fire sound 2.
        if (!efire2.loadFromFile("assets/sounds/enemyfire2.wav"))
            throw runtime_error("assets/sounds/enemyfire2.wav");

        // Load enemy die sound.
        if (!edie.loadFromFile("assets/sounds/enemydie.wav"))
            throw runtime_error("assets/sounds/enemydie.wav");

        // Load enemy die sound 2.
        if (!edielow.loadFromFile("assets/sounds/enemydielow.wav"))
            throw runtime_error("assets/sounds/enemydielow.wav");

        // Load collide sound.
        if (!pcollide.loadFromFile("assets/sounds/playercollide.wav"))
            throw runtime_error("assets/sounds/playercollide.wav");

        // Load background textures.
        if (!backgroundTexture.loadFromFile("assets/images/background.jpg"))
            throw runtime_error("assets/images/background.jpg");

        // Load menu textures.
        if (!menuTexture.loadFromFile("assets/images/mainMenu_bg.jpg"))
            throw runtime_error("assets/images/mainMenu_bg.jpg");

        // Load spaceship textures.
        for (int i = 0; i < 2; i++)
        {
            Texture texture;
            if (!texture.loadFromFile("assets/images/spaceship/spaceship_straight" +
                                      to_string((i + 1)) + ".png"))
                throw runtime_error("assets/images/spaceship/spaceship.png");
            else
                spaceshipTextures.push_back(texture);
        }

        // Load spaceship left textures.
        for (int i = 0; i < 2; i++)
        {
            Texture texture;
            if (!texture.loadFromFile("assets/images/spaceship/spaceship_left" +
                                      to_string((i + 1)) + ".png"))
                throw runtime_error("assets/images/spaceship/spaceship_left.png");
            else
                spaceshipLeftTextures.push_back(texture);
        }

        // Load spaceship right textures.
        for (int i = 0; i < 2; i++)
        {
            Texture texture;
            if (!texture.loadFromFile("assets/images/spaceship/spaceship_right" +
                                      to_string((i + 1)) + ".png"))
                throw runtime_error("assets/images/spaceship/spaceship_right.png");
            else
                spaceshipRightTextures.push_back(texture);
        }

        // Load enemy textures.
        for (int i = 0; i < 2; i++)
        {
            Texture texture;
            if (!texture.loadFromFile("assets/images/enemy/enemy_" +
                                      to_string((i + 1)) + ".png"))
                throw runtime_error("assets/images/enemy/enemy.png");
            else
                enemyTextures.push_back(texture);
        }

        // Load explosion textures.
        for (int i = 0; i < 48; i++)
        {
            Texture texture;
            if (!texture.loadFromFile("assets/images/explosions/explosion_1/explosion_" +
                                      to_string((i + 1)) + ".png"))
                throw runtime_error("assets/images/explosions/explosion_1/explosion.png");
            else
                explosionTextures.push_back(texture);
        }

        // Load spaceship projectile textures.
        for (int i = 0; i < 16; i++)
        {
            Texture texture;
            if (!texture.loadFromFile("assets/images/bullets/spaceship/bullet_" +
                                      to_string((i + 1)) + ".png"))
                throw runtime_error("assets/images/bullets/spaceship/bullet.png");
            else
                spaceshipProjectileTextures.push_back(texture);
        }

        // Load enemy projectile projectile textures.
        for (int i = 0; i < 2; i++)
        {
            Texture texture;
            if (!texture.loadFromFile("assets/images/bullets/enemy/sphere_" +
                                      to_string((i + 1)) + ".png"))
                throw runtime_error("assets/images/bullets/enemy/sphere.png");
            else
                enemyProjectileTextures.push_back(texture);
        }

        // Load font.
        if (!font.loadFromFile("assets/fonts/ocraextended.ttf"))
            throw runtime_error("assets/fonts/ocraextended.ttf");
    }

    catch (exception e)
    {
        // cout << "Error: Failed to load " << e.what();
    }
}

void AssetManager::playGameMusic()
{
    gamemusic.play();
}

void AssetManager::playFire()
{
    if ((rand() % 2))
        fireSound.setBuffer(efire);
    else
        fireSound.setBuffer(efire2);

    fireSound.play();
}

void AssetManager::playDie()
{
    if ((rand() % 2))
        dieSound.setBuffer(edie);
    else
        dieSound.setBuffer(edielow);

    dieSound.play();
}

void AssetManager::playCollide()
{
    collideSound.setBuffer(pcollide);
    collideSound.play();
}

Texture AssetManager::getBackgroundTexture()
{
    return backgroundTexture;
}

Texture AssetManager::getMenuTexture()
{
    return menuTexture;
}

vector<Texture> AssetManager::getSpaceshipTextures()
{
    return spaceshipTextures;
}

vector<Texture> AssetManager::getSpaceshipLeftTextures()
{
    return spaceshipLeftTextures;
}

vector<Texture> AssetManager::getSpaceshipRightTextures()
{
    return spaceshipRightTextures;
}

vector<Texture> AssetManager::getEnemyTextures()
{
    return enemyTextures;
}

vector<Texture> AssetManager::getExplosionTextures()
{
    return explosionTextures;
}

vector<Texture> AssetManager::getSpaceshipProjectileTextures()
{
    return spaceshipProjectileTextures;
}

vector<Texture> AssetManager::getEnemyProjectileTextures()
{
    return enemyProjectileTextures;
}

Font AssetManager::getFont()
{
    return font;
}