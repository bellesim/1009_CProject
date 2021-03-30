#include "Spaceship.h"
#include "Projectile.h"
#include "Enums.h"
#include <iostream>
#include <chrono>
#include <thread>

// temporary to print out the States of spaceship
ostream &operator<<(ostream &strm, Status tt)
{
    const string nameTT[] = {"ALIVE", "INVULNERABLE", "EXPLODING", "DEAD"};
    return strm << nameTT[tt];
}

Spaceship::Spaceship()
{
    hitPoints = 2;
    score = 0;
    currentReloadCounter = 0;
    reloadCounter = 10;
    currentStatus = ALIVE;
    blinkCounter = 0;
    blinkTime = 3;
}

void Spaceship::settings(Animation &a, Animation &l, Animation &r, Animation &e, int x, int y)
{
    Actor::settings(a, x, y);
    leftAnimation = l;
    rightAnimation = r;
    explosionAnimation = e;
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
        Projectile *projectile = new Projectile(true, false, false, false, 12, "spaceship");
        projectile->settings(projectileAnim, *this);
        currentReloadCounter = 0;
        return projectile;
    }

    currentReloadCounter++;
    return NULL;
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
        explosionAnimation.setSpritePosition(position);
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
        {
            printf("\nis dead");
            currentStatus = DEAD;
        }
    }
}

void Spaceship::deductHitPoint(int hit)
{
    // Spaceship to explode as hit point is less than 1 when hit.
    if (currentStatus == ALIVE)
    {
        hitPoints -= hit;

        if (hitPoints < 1)
        {
            // shld be explode.
            currentStatus = EXPLODING;
            // currentStatus = DEAD;
            std::cout << currentStatus << std::endl;
        }
        else
        {
            printf("\n GOING INVULNERABLE");
            currentStatus = INVULNERABLE;
        }
    }
    else if (currentStatus == INVULNERABLE)
    {
        thread t([this]() {
            this_thread::sleep_for(chrono::seconds(3));
            currentStatus = ALIVE;
        });
        t.detach();
    }
}

int Spaceship::getHitPoints()
{
    if (hitPoints < 0)
    {
        hitPoints = 0;
    }
    return hitPoints;
}