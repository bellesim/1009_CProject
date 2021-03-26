#include "Actor.h"

class Projectile;

class Enemy : public Actor
{
private:
    int reloadCounter;
    int currentReloadCounter;

public:
    Enemy();
    ~Enemy();
    Projectile *shoot(Animation projectileAnim);
};