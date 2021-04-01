#include "Actor.h"
#include "Game.h"

Actor::Actor()
{
    hitPoints = 1;
    speed = 10;
    width = 50;
    height = 50;
}

void Actor::settings(Animation &a, int x, int y)
{
    this->animation = a;
    this->position = Position(x, y);
}

void Actor::draw(RenderWindow &app)
{
    animation.setSpritePosition(position);
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
    if (currentStatus != EXPLODING)
    {
        if (up)
            position.addToY(-speed);
        if (down)
            position.addToY(speed);
        if (left)
            position.addToX(-speed);
        if (right)
            position.addToX(speed);

        if (position.getX() > 1050)
            position.setX(0);
        if (position.getX() < 0)
            position.setX(1050);
        if (position.getY() > 1150)
            position.setY(0);
        if (position.getY() < 0)
            position.setY(1150);
    }
};

int Actor::getHitPoints()
{
    return hitPoints;
}

Position Actor::getPosition()
{
    return position;
}

int Actor::getHeight()
{
    return height;
}

int Actor::getWidth()
{
    return width;
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

bool Actor::isCollide(int x, int y)
{
    if (x >= position.getX() && x <= position.getX() + this->getWidth())
    {
        if (y >= position.getY() && y <= position.getY() + this->getHeight())
            return true;
    }
    
    return false;
}