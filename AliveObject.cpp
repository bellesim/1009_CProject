#include "AliveObject.h"
#include "Projectile.h"
#include "Enums.h"
#include <iostream>
#include <chrono>
#include <thread>

AliveObject::AliveObject()
{
    hitPoints = 1;
    reloadCounter = 50;
    currentReloadCounter = 0;
}

void AliveObject::settings(Animation &a, Animation &e, int x, int y, int reloadCounter, int hitPoints)
{
    Actor::settings(a, x, y);
    this->explosionAnimation = e;
    this->hitPoints = hitPoints;
    this->reloadCounter = reloadCounter;
    currentReloadCounter = 0;
}

Projectile *AliveObject::shoot(Animation projectileAnim, bool up, bool down,
                               bool left, bool right, int speed, ActorType type)
{
    if (currentReloadCounter >= reloadCounter)
    {
        Projectile *projectile = new Projectile(up, down, left, right, speed, type);
        projectile->settings(projectileAnim, *this);
        currentReloadCounter = 0;
        return projectile;
    }

    currentReloadCounter++;
    return NULL;
}

Status AliveObject::getCurrentStatus()
{
    return currentStatus;
}

void AliveObject::setCurrentStatus(Status currentStatus)
{
    this->currentStatus = currentStatus;
}
