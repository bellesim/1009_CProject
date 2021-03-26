#pragma once

class Position
{
private:
    int x, y;

public:
    Position();
    Position(int x, int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void addToX(int val);
    void addToY(int val);
    double operator-(Position position);
};