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

vector<char> Position::operator-(Position *position)
{
    vector<char> directions;

    // Move towards the point enemy should go.
    if (this->getX() < position->getX())
        directions.push_back('r');

    if (this->getX() > position->getX())
        directions.push_back('l');

    if (this->getY() < position->getY())
        directions.push_back('d');

    if (this->getY() > position->getY())
        directions.push_back('u');

    if (this->getY() == position->getY() && this->getX() == position->getX())
        directions.push_back('c');

    return directions;
}
