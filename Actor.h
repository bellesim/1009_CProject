#pragma once

#include "Animation.h"
#include "Position.h"
#include "Enums.h"
using namespace std;
using namespace sf;

class Actor
{
protected:
    Position position;
    int speed, hitPoints;
    bool left, right, up, down;
    int width, height;

private:
    Animation animation;

public:
    Actor();
    virtual void settings(Animation &a, int x, int y);
    void draw(RenderWindow &app);
    void keyPressed();
    void update();
    int getHitPoints();
    Position getPosition();
    int getWidth();
    int getHeight();
    bool isCollide(int x ,int y);
};