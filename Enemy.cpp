#include "Enemy.h"
#include "Projectile.h"

void Enemy::settings(Animation &a, Animation &e, vector<Position *> positions, int x, int y)
{
    this->positions = positions;
    AliveObject::settings(a, e, x, y, rand() % 50 + 50, 1);
    speed = 5;
    type = ENEMY;
    currentStatus = ALIVE;
}

Projectile *Enemy::shoot(Animation projectileAnim)
{
    Projectile *projectile;
    int shootDirection = rand() % (3) + 1;

    if (shootDirection == 1)
        projectile = AliveObject::shoot(projectileAnim, false, true, false, false, 5, ENEMY);

    else if (shootDirection == 2)
        projectile = AliveObject::shoot(projectileAnim, false, true, true, false, 5, ENEMY);

    else
        projectile = AliveObject::shoot(projectileAnim, false, true, false, true, 5, ENEMY);

    return projectile;
}

void Enemy::updateAnimation(RenderWindow &app)
{
    if (currentStatus == ALIVE)
        Actor::draw(app);

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

void Enemy::draw(RenderWindow &app)
{
    if (currentStatus == ALIVE || currentStatus == EXPLODING)
    {
        updateAnimation(app);

        if (explosionAnimation.isEndOfAnimation())
            currentStatus = DEAD;
    }
}

void Enemy::deductHitPoint(int hit)
{
    if (currentStatus == ALIVE)
    {
        hitPoints = hitPoints - hit;

        if (hitPoints < 1)
            currentStatus = EXPLODING;
    }
}

void Enemy::update()
{
    if (currentStatus != EXPLODING)
    {
        vector<char> directions = this->position - this->positions[0];

        if (find(directions.begin(), directions.end(), 'u') != directions.end())
            up = true;
        else
            up = false;

        if (find(directions.begin(), directions.end(), 'd') != directions.end())
            down = true;
        else
            down = false;

        if (find(directions.begin(), directions.end(), 'l') != directions.end())
            left = true;
        else
            left = false;

        if (find(directions.begin(), directions.end(), 'r') != directions.end())
            right = true;
        else
            right = false;

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
}
