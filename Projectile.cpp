#include "Projectile.h"

Projectile ::Projectile()
{
}

Projectile::Projectile(bool up, bool down, bool left, bool right, int speed, string origin)
{
    this->up = up;
    this->down = down;
    this->left = left;
    this->right = right;
    hitPoints = 1;
    this->speed = speed;
    this->origin = origin;
}

void Projectile::settings(Animation &a, Actor &actor)
{
    // Need to work on as the projectile seem to come from the back of the actor.
    Actor::settings(a, actor.getPosition().getX() + 20, actor.getPosition().getY() - 5);
}

void Projectile::update()
{
    if (up)
        position.addToY(-speed);
    if (down)
        position.addToY(speed);
    if (left)
        position.addToX(-speed);
    if (right)
        position.addToX(speed);

    if (position.getX() > 1050 || position.getX() < 0 ||
        position.getY() > 1150 || position.getY() < 0)
    {
        hitPoints = 0;
    }
}

string Projectile::getOrigin(){
    return origin;
}