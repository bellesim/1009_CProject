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
    Texture getMenuTexture();
    vector<Texture> getSpaceshipTextures();
    vector<Texture> getSpaceshipLeftTextures();
    vector<Texture> getSpaceshipRightTextures();
    vector<Texture> getExplosionTextures();
    vector<Texture> getProjectileTextures();
    vector<Texture> getRockTextures();
    Font getFont();
};