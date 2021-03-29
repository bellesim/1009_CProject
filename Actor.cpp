#include "Actor.h"
#include "Game.h"

Actor::Actor()
{
    hitPoints = 1;
    speed = 10;
}

void Actor::settings(Animation &a, int x, int y)
{
    this->animation = a;
    this->x = x;
    this->y = y;
}

void Actor::draw(RenderWindow &app)
{
    animation.setSpritePosition(x, y);
    app.draw(this->animation.getSprite());
    animation.update();
}

void Actor::keyPressed()
{
    if (Keyboard::isKeyPressed(Keyboard::W))
        up = true;

    else
        up = false;

    if (Keyboard::isKeyPressed(Keyboard::S))
        down = true;
    else
        down = false;

    if (Keyboard::isKeyPressed(Keyboard::A))
        left = true;
    else
        left = false;

    if (Keyboard::isKeyPressed(Keyboard::D))
        right = true;
    else
        right = false;
}

void Actor::update()
{
    if (up)
        y -= speed;
    if (down)
        y += speed;
    if (left)
        x -= speed;
    if (right)
        x += speed;

    if (x > 1050)
        x = 0;
    if (x < 0)
        x = 1050;
    if (y > 1150)
        y = 0;
    if (y < 0)
        y = 1150;
};

int Actor::getHitPoints()
{
    return hitPoints;
}

int Actor::getX()
{
    return x;
}

int Actor::getY()
{
    return y;
}

void Actor::deductHitPoint(int hit)
{
    this->hitPoints -= hit;
}

Status Actor::getCurrentStatus()
{
    return currentStatus;
}

void Actor::setCurrentStatus(Status currentStatus)
{
    this->currentStatus = currentStatus;
}