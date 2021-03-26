#include "Actor.h"

class Projectile;

class Enemy : public Actor
{
private:
    int reloadCounter;
    int currentReloadCounter;
    vector<Position *> positions;

public:
    Enemy();
    Projectile *shoot(Animation projectileAnim);
    void update();
    void settings(Animation &animation, vector<Position *> positions, int x, int y);
};