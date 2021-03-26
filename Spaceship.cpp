#include "Spaceship.h"
#include "Projectile.h"
#include "Enums.h"

Spaceship::Spaceship()
{
    hitPoints = 3;
    score = 0;
    currentReloadCounter = 0;
    reloadCounter = 10;
}

void Spaceship::settings(Animation &a, Animation &l, Animation &r, int x, int y)
{
    Actor::settings(a, x, y);
    leftAnimation = l;
    rightAnimation = r;
}

void Spaceship::addToScore(int score)
{
    this->score += score;
}

int Spaceship::getScore()
{
    return score;
}

Projectile *Spaceship::shoot(Animation projectileAnim)
{
    if (currentReloadCounter >= reloadCounter)
    {
        Projectile *projectile = new Projectile(true, false, false, false, 12);
        projectile->settings(projectileAnim, *this);
        currentReloadCounter = 0;
        return projectile;
    }

    currentReloadCounter++;
    return NULL;
}

void Spaceship::draw(RenderWindow &app)
{
    if (left == true)
    {
        leftAnimation.setSpritePosition(position);
        app.draw(leftAnimation.getSprite());
        leftAnimation.update();
    }
    else if (right == true)
    {
        rightAnimation.setSpritePosition(position);
        app.draw(rightAnimation.getSprite());
        rightAnimation.update();
    }
    else
    {
        Actor::draw(app);
    }
}