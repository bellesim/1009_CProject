#include "Enemy.h"
#include "Projectile.h"

Enemy::Enemy()
{
    hitPoints = 1;
    speed = 5;
    currentReloadCounter = 0;
    reloadCounter = rand() % 50 + 50;
}

Projectile *Enemy::shoot(Animation projectileAnim)
{
    if (currentReloadCounter >= reloadCounter)
    {
        Projectile *projectile;
        int shootDirection = rand() % (3) + 1;
        if (shootDirection == 1)
        {
            projectile = new Projectile(false, true, false, false, 5, "enemy");
        }
        else if (shootDirection == 2)
        {
            projectile = new Projectile(false, true, true, false, 5, "enemy");
        }
        else
        {
            projectile = new Projectile(false, true, false, true, 5, "enemy");
        }

        return projectile;
    }

    currentReloadCounter++;
    return NULL;
}

void Enemy::settings(Animation &a, vector<Position *> positions, int x, int y)
{
    this->positions = positions;
    Actor::settings(a, x, y);
}

void Enemy::update()
{
    vector<char> directions = this->position - this->positions[0];

    for (int i = 0; i < directions.size(); i++)
    {
        printf("%c", directions[i]);
    }

    if (find(directions.begin(), directions.end(), 'u') != directions.end())
    {
        up = true;
    }
    else
    {
        up = false;
    }

    if (find(directions.begin(), directions.end(), 'd') != directions.end())
    {
        down = true;
    }
    else
    {
        down = false;
    }

    if (find(directions.begin(), directions.end(), 'l') != directions.end())
    {
        left = true;
    }
    else
    {
        left = false;
    }

    if (find(directions.begin(), directions.end(), 'r') != directions.end())
    {
        right = true;
    }
    else
    {
        right = false;
    }

    if (find(directions.begin(), directions.end(), 'c') != directions.end())
    {
        Position *currentPosition = positions[0];
        positions.erase(positions.begin());
        positions.push_back(currentPosition);
    }

    if (up)
        position.addToY(-speed);
    if (down)
        position.addToY(speed);
    if (left)
        position.addToX(-speed);
    if (right)
        position.addToX(speed);
}
