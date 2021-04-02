#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <list>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class AssetManager
{
private:
    Music gamemusic;
    SoundBuffer efire;
    SoundBuffer efire2;
    SoundBuffer edie;
    SoundBuffer edielow;
    SoundBuffer pcollide;

    Sound fireSound;
    Sound dieSound;
    Sound collideSound;

    Texture backgroundTexture;
    Texture menuTexture;

    vector<Texture> spaceshipTextures;
    vector<Texture> spaceshipLeftTextures;
    vector<Texture> spaceshipRightTextures;
    vector<Texture> spaceshipProjectileTextures;
    vector<Texture> enemyTextures;
    vector<Texture> explosionTextures;
    vector<Texture> enemyProjectileTextures;

    Font font;

public:
    AssetManager();

    void playGameMusic();
    void playFire();
    void playDie();
    void playCollide();

    Texture getBackgroundTexture();
    Texture getMenuTexture();
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