#include "AssetManager.h"

Texture AssetManager::getBackgroundTexture()
{
    Texture backgroundTexture;
    backgroundTexture.loadFromFile("images/background.jpg");
    return backgroundTexture;
}

vector<Texture> AssetManager::getSpaceshipTextures()
{
    vector<Texture> spaceshipTextures;
    for (int i = 0; i < 2; i++)
    {
        Texture texture;
        texture.loadFromFile("images/spaceship/spaceship_straight" +
                             to_string((i + 1)) + ".png");
        spaceshipTextures.push_back(texture);
    }
    return spaceshipTextures;
}

vector<Texture> AssetManager::getSpaceshipLeftTextures()
{
    vector<Texture> leftSpaceshipTextures;
    for (int i = 0; i < 2; i++)
    {
        Texture texture;
        texture.loadFromFile("images/spaceship/spaceship_left" +
                             to_string((i + 1)) + ".png");
        leftSpaceshipTextures.push_back(texture);
    }
    return leftSpaceshipTextures;
}

vector<Texture> AssetManager::getSpaceshipRightTextures()
{
    vector<Texture> rightSpaceshipTextures;
    for (int i = 0; i < 2; i++)
    {
        Texture texture;
        texture.loadFromFile("images/spaceship/spaceship_left" +
                             to_string((i + 1)) + ".png");
        rightSpaceshipTextures.push_back(texture);
    }
    return rightSpaceshipTextures;
}

vector<Texture> AssetManager::getExplosionTextures()
{
    vector<Texture> explosionTextures;
    for (int i = 0; i < 48; i++)
    {
        Texture texture;
        texture.loadFromFile("images/explosions/explosion_1/explosion_" +
                             to_string((i + 1)) + ".png");
        explosionTextures.push_back(texture);
    }
    return explosionTextures;
}

Font AssetManager::getFont()
{
    Font font;
    if (!font.loadFromFile("fonts/ocraextended.ttf"))
    {
        printf("error");
    }
    return font;
}