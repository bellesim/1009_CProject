#include "Spaceship.h"

Spaceship::Spaceship()
{
    hitPoints = 3;
    score = 0;
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

void Spaceship::draw(RenderWindow &app)
{
    if (left == true)
    {
        leftAnimation.setSpritePosition(x, y);
        app.draw(leftAnimation.getSprite());
        leftAnimation.update();
    }
    else if (right == true)
    {
        rightAnimation.setSpritePosition(x, y);
        app.draw(rightAnimation.getSprite());
        rightAnimation.update();
    }
    else
    {
        printf("\ndrawing from spaceship");
        Actor::draw(app);
    }
}