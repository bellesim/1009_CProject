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
    // printsf("hi");
    printf("\nthis is my x %d", this->getX());
    printf("\nthis is the other x %d", position->getX());
    // Move towards the point enemy should go.
    if (this->getX() < position->getX())
    {
        directions.push_back('r');
        // moveRight();
    }
    if (this->getX() > position->getX())
    {
        directions.push_back('l');
        // moveLeft();
    }
    if (this->getY() < position->getY())
    {
        // moveDown();
        directions.push_back('d');
    }
    if (this->getY() > position->getY())
    {
        directions.push_back('u');
        // moveUp();
    }

    if (this->getY() == position->getY() && this->getX() == position->getX())
    {
        directions.push_back('c');
    }

    return directions;
}
