#pragma once

#include "AliveObject.h"

class Projectile;

class Enemy : public AliveObject
{
private:
    vector<Position *> positions;
    void updateAnimation(RenderWindow &);

public:
    void settings(Animation &animation, Animation &explosionAnimation,
                  vector<Position *> positions, int x, int y);
    Projectile *shoot(Animation projectileAnim);
    void update();
    void draw(RenderWindow &app);
    void deductHitPoint(int hit);
};