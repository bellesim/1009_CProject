#include "Actor.h"

Actor::Actor()
{
    life = 1;
}

void Actor::settings(Animation &a, int x, int y, float angle, int radius)
{
    this->animation = a;
    this->x = x;
    this->y = y;
    this->angle = angle;
    this->radius = radius;
}

void Actor::draw(RenderWindow &app)
{
    animation.sprite.setPosition(x, y);
    animation.sprite.setRotation(angle + 90);
    app.draw(this->animation.sprite);

    CircleShape circle(radius);
    circle.setFillColor(Color(255, 0, 0, 170));
    circle.setPosition(x, y);
    circle.setOrigin(radius, radius);
    //app.draw(circle);
}