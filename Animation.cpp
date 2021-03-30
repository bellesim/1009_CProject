#include "Animation.h"

Animation::Animation() {}

Animation::Animation(vector<Texture> &textures, int scale)
{
    this->textures = textures;
    currentFrame = 0;

    sprite.setTexture(textures[currentFrame]);
    sprite.setScale(scale, scale);
}

void Animation::update()
{
    sprite.setTexture(textures[currentFrame]);

    if (currentFrame >= textures.size() - 1)
        currentFrame = 0;
    else
        currentFrame++;
}

void Animation::setSpritePosition(Position position)
{
    sprite.setPosition(position.getX(), position.getY());
}

Sprite Animation::getSprite()
{
    return sprite;
}

bool Animation::isEndOfAnimation()
{
    return (textures.size() - 1) <= currentFrame;
}