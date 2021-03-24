#pragma once

#include "Actor.h"

class Projectile : public Actor
{
public:
    Projectile();
    Projectile(bool up, bool down, bool left, bool right);
    void update();
    void settings(Animation &a, Actor &actor);
};
