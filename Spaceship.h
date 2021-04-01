#pragma once

#include "AliveObject.h"

class Projectile;

class Spaceship : public AliveObject
{
private:
    int score;
    Animation leftAnimation;
    Animation rightAnimation;
    int blinkCounter;
    int blinkTime;
    void updateAnimation(RenderWindow &);

public:
    Spaceship();
    ~Spaceship();
    void addToScore(int score);
    int getScore();
    Projectile *shoot(Animation projectileAnim);

    // Override from Actor.
    void settings(Animation &animation, Animation &leftAnimation, Animation &rightAnimation,
                  Animation &explosionAnimation, int x, int y);
    void draw(RenderWindow &app);
    void deductHitPoint(int hit);
    int getHitPoints();
};