#pragma once

#include "Actor.h"

class Projectile : public Actor
{
private:
    ActorType origin;

public:
    Projectile();
    Projectile(bool up, bool down, bool left, bool right, int speed, ActorType origin);
    void update();
    void settings(Animation &a, Actor &actor);
    bool outOfScreen();

    ActorType getOrigin();
};
