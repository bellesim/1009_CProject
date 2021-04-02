#pragma once

#include "AliveObject.h"

class Projectile;

class Spaceship : public AliveObject
{
private:
    int score, blinkCounter, blinkTime;
    Animation leftAnimation, rightAnimation;
    void updateAnimation(RenderWindow &);

public:
    void settings(Animation &animation, Animation &leftAnimation, Animation &rightAnimation,
                  Animation &explosionAnimation, int x, int y);
    Projectile *shoot(Animation projectileAnim);
    void draw(RenderWindow &app);
    void deductHitPoint(int hit);
    int getHitPoints();
    void addToScore(int score);
    int getScore();
};