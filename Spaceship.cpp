#include "Spaceship.h"
#include "Projectile.h"
#include "Enums.h"
#include <iostream>
#include <chrono>
#include <thread>

void Spaceship::settings(Animation &a, Animation &l, Animation &r, Animation &e, int x, int y)
{
    AliveObject::settings(a, e, x, y, 10, 3);
    type = SPACESHIP;
    leftAnimation = l;
    rightAnimation = r;
    explosionAnimation = e;
    currentStatus = ALIVE;
    blinkCounter = 0;
    blinkTime = 3;
    score = 0;
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
    Projectile *projectile = AliveObject::shoot(projectileAnim, true, false, false, false, 12, SPACESHIP);
    return projectile;
}

void Spaceship::updateAnimation(RenderWindow &app)
{
    if (currentStatus == ALIVE || currentStatus == INVULNERABLE)
    {
        if (left)
        {
            leftAnimation.setSpritePosition(position);
            app.draw(leftAnimation.getSprite());
            leftAnimation.update();
        }
        else if (right)
        {
            rightAnimation.setSpritePosition(position);
            app.draw(rightAnimation.getSprite());
            rightAnimation.update();
        }
        else
            Actor::draw(app);
    }
    else if (currentStatus == EXPLODING)
    {
        Position newPosition = position;
        newPosition.addToX(-75);
        newPosition.addToY(-75);
        explosionAnimation.setSpritePosition(newPosition);
        app.draw(explosionAnimation.getSprite());
        explosionAnimation.update();
    }
}

void Spaceship::draw(RenderWindow &app)
{
    if (currentStatus == INVULNERABLE)
    {
        if (blinkTime == blinkCounter)
        {
            blinkCounter = 0;
            updateAnimation(app);
        }
        else
            blinkCounter++;
    }
    else if (currentStatus == ALIVE || currentStatus == EXPLODING)
    {
        updateAnimation(app);

        if (explosionAnimation.isEndOfAnimation())
            currentStatus = DEAD;
    }
}

void Spaceship::deductHitPoint(int hit)
{
    // Spaceship to explode as hit point is less than 1 when hit.
    if (currentStatus == ALIVE)
    {
        hitPoints -= hit;

        // When no more HP ships explodes.
        if (hitPoints < 1)
            currentStatus = EXPLODING;
        else
        {
            currentStatus = INVULNERABLE;
            thread t([this]() {
                this_thread::sleep_for(chrono::seconds(3));

                if (currentStatus != EXPLODING)
                    currentStatus = ALIVE;
            });
            t.detach();
        }
    }
}

int Spaceship::getHitPoints()
{
    if (hitPoints < 0)
        hitPoints = 0;

    return hitPoints;
}