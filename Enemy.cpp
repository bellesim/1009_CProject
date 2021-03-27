#include "Enemy.h"
#include "Projectile.h"

Enemy::Enemy()
{
    hitPoints = 1;
    speed = 6;
    currentReloadCounter = 0;
    reloadCounter = rand() % 50 + 50;
}

Projectile *Enemy::shoot(Animation projectileAnim)
{
    if (currentReloadCounter >= reloadCounter)
    {
        Projectile *projectile = new Projectile(false, true, false, false, 5,"enemy");
        projectile->settings(projectileAnim, *this);
        currentReloadCounter = 0;
        return projectile;
    }

    currentReloadCounter++;
    return NULL;
}
