#include "Animation.h"

Animation::Animation() {}

Animation::Animation(vector<Texture> &textures)
{
    this->textures = textures;
    currentFrame = 0;

    sprite.setTexture(textures[currentFrame]);
    sprite.setScale(2, 2);
}

void Animation::update()
{
    sprite.setTexture(textures[currentFrame]);

    if (currentFrame >= textures.size() - 1)
        currentFrame = 0;
    else
        currentFrame++;
}

void Animation::setSpritePosition(int x, int y)
{
    sprite.setPosition(x, y);
}

Sprite Animation::getSprite()
{
    return sprite;
}