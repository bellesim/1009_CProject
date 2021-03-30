#include "Actor.h"

class Projectile;

class Enemy : public Actor
{
private:
    int reloadCounter;
    int currentReloadCounter;
    Animation explosionAnimation;
    vector<Position *> positions;
    void updateAnimation(RenderWindow &);

public:
    Enemy();
    Projectile *shoot(Animation projectileAnim);
    void update();
    void deductHitPoint(int hit);
    void settings(Animation &animation, Animation &explosionAnimation, vector<Position *> positions,
                  int x, int y);
    void draw(RenderWindow &app);
};