#pragma once

#include "Actor.h"

class Projectile : public Actor
{
private:
    string origin;
public:
    Projectile();
    Projectile(bool up, bool down, bool left, bool right, int speed,string origin);
    void update();
    void settings(Animation &a, Actor &actor);
    string getOrigin();
};
