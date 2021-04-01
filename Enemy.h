#pragma once

#include "AliveObject.h"

class Projectile;

class Enemy : public AliveObject
{
private:
    vector<Position *> positions;
    void updateAnimation(RenderWindow &);

public:
    Projectile *shoot(Animation projectileAnim);
    void update();
    void deductHitPoint(int hit);
    void settings(Animation &animation, Animation &explosionAnimation,
                  vector<Position *> positions, int x, int y);
    void draw(RenderWindow &app);
};