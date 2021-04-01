#pragma once

#include "Actor.h"

class Projectile;

class AliveObject : public Actor
{

protected:
    Animation explosionAnimation;
    int hitPoints;
    Projectile *shoot(Animation projectileAnim, bool up, bool down,
                      bool left, bool right, int speed, ActorType type);
    void settings(Animation &animation, Animation &explosionAnimation,
                  int x, int y, int reloadCounter, int hitPoints);

private:
    int reloadCounter, currentReloadCounter;
    // void updateAnimation(RenderWindow &);

public:
    AliveObject();
    // Override from Actor.
    // void draw(RenderWindow &app);
    // void deductHitPoint(int hit);
};