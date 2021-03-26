#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <list>

using namespace std;
using namespace sf;

class AssetManager
{
public:
    Texture getBackgroundTexture();
    vector<Texture> getSpaceshipTextures();
    vector<Texture> getSpaceshipLeftTextures();
    vector<Texture> getSpaceshipRightTextures();
    vector<Texture> getEnemyTextures();
    vector<Texture> getExplosionTextures();
    vector<Texture> getSpaceshipProjectileTextures();
    vector<Texture> getEnemyProjectileTextures();
    vector<Texture> getRockTextures();
    Font getFont();
};