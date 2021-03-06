#include "Actor.h"
#include "Game.h"

Actor::Actor()
{
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
};

Position Actor::getPosition()
{
    return position;
}

bool Actor::isCollide(int x, int y)
{
    if (x >= position.getX() && x <= position.getX() + width)
    {
        if (y >= position.getY() && y <= position.getY() + height)
            return true;
    }

    return false;
}