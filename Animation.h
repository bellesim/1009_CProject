#pragma once

#include <SFML/Graphics.hpp>
#include "Position.h"
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
    void setSpritePosition(Position position);
    Sprite getSprite();
};