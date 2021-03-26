#include "Projectile.h"

Projectile ::Projectile()
{
}

Projectile::Projectile(bool up, bool down, bool left, bool right)
{
    this->up = up;
    this->down = down;
    this->left = left;
    this->right = right;
    hitPoints = 1;
    speed = 7;
}

void Projectile::settings(Animation &a, Actor &actor)
{
    Actor::settings(a, actor.getX() + 20, actor.getY() - 40);
}

void Projectile::update()
{
    if (up)
        y -= speed;
    if (down)
        y += speed;
    if (left)
        x -= speed;
    if (right)
        x += speed;

    if (x > 1050 || x < 0 || y > 1150 || y < 0)
    {
        hitPoints = 0;
    }
}
