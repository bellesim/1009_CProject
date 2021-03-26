#include "Position.h"

Position::Position() {}

Position::Position(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Position::getX()
{
    return x;
}

int Position::getY()
{
    return y;
}

void Position::setX(int x)
{
    this->x = x;
}

void Position::setY(int y)
{
    this->y = y;
}

void Position::addToX(int val)
{
    this->x += val;
}

void Position::addToY(int val)
{
    this->y += val;
}

double Position::operator-(Position position)
{
    // calcuate distance between both position.
    return 1;
}
