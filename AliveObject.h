#pragma once

#include "Actor.h"

class Projectile;

class AliveObject : public Actor
{

protected:
    Animation explosionAnimation;
    int hitPoints;
    Status currentStatus;

    Projectile *shoot(Animation projectileAnim, bool up, bool down,
                      bool left, bool right, int speed, ActorType type);
    void settings(Animation &animation, Animation &explosionAnimation,
                  int x, int y, int reloadCounter, int hitPoints);

private:
    int reloadCounter, currentReloadCounter;
    virtual void updateAnimation(RenderWindow &) = 0;

public:
    AliveObject();
    virtual void draw(RenderWindow &app) = 0;
    Status getCurrentStatus();
    void setCurrentStatus(Status currentStatus);
};