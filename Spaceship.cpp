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
    hitPoints = 3;
    score = 0;
    currentReloadCounter = 0;
    reloadCounter = 10;
    currentStatus = ALIVE;
    blinkCounter = 0;
    blinkTime = 3;
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
        Projectile *projectile = new Projectile(true, false, false, false);
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
        if (currentStatus == ALIVE || currentStatus == EXPLODING)
        {
            leftAnimation.setSpritePosition(x, y);
            app.draw(leftAnimation.getSprite());
            leftAnimation.update();
        }
        else if (currentStatus == INVULNERABLE)
        {
            if (blinkTime == blinkCounter)
            {
                blinkCounter = 0;
                leftAnimation.setSpritePosition(x, y);
                app.draw(leftAnimation.getSprite());
                leftAnimation.update();
            }
            else
            {
                blinkCounter++;
            }
        }
    }
    else if (right == true)
    {
        if (currentStatus == ALIVE || currentStatus == EXPLODING)
        {
            rightAnimation.setSpritePosition(x, y);
            app.draw(rightAnimation.getSprite());
            rightAnimation.update();
        }
        else if (currentStatus == INVULNERABLE)
        {
            if (blinkTime == blinkCounter)
            {
                blinkCounter = 0;
                rightAnimation.setSpritePosition(x, y);
                app.draw(rightAnimation.getSprite());
                rightAnimation.update();
            }
            else
            {
                blinkCounter++;
            }
        }
    }
    else
    {
        if (currentStatus == ALIVE || currentStatus == EXPLODING)
        {
            Actor::draw(app);
        }
        else if (currentStatus == INVULNERABLE)
        {
            if (blinkTime == blinkCounter)
            {
                blinkCounter = 0;
                Actor::draw(app);
            }
            else
            {
                blinkCounter++;
            }
        }
    }
}

void Spaceship::deductHitPoint(int hit)
{
    if (currentStatus == INVULNERABLE)
    {
        // if invulnerable do nothing
    }
    else
    {
        this->hitPoints -= hit;
        currentStatus = INVULNERABLE;
    }
    if (hitPoints > 0)
    {
        // std::thread t([this]()
        // {
        //     std::this_thread::sleep_for(std::chrono::seconds(3));
        //     currentStatus = Status::ALIVE;
        // });
        // t.detach();
    }
    else
    {
        if (hitPoints <= 0)
        {
            // shld be explode
            currentStatus = DEAD;
            std::cout << currentStatus << std::endl;
        }
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