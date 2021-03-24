#pragma once

#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Animation
{
private:
    Sprite sprite;
    int currentFrame;
    vector<Texture> textures;

public:
    Animation();
    Animation(vector<Texture> &textures, int scale = 1);
    void update();
    void setSpritePosition(int x, int y);
    Sprite getSprite();
};