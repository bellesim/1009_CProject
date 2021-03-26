#pragma once

#include "Animation.h"
#include "Enums.h"
using namespace std;
using namespace sf;

class Actor
{
protected:
    int speed, hitPoints;
    bool left, right, up, down;
    int x, y, width, height;
    Status currentStatus;

private:
    Animation animation;

public:
    Actor();
    virtual void settings(Animation &a, int x, int y);
    void draw(RenderWindow &app);
    void keyPressed();
    void update();
    int getHitPoints();
    int getX();
    int getY();
    void deductHitPoint(int hit);
    Status getCurrentStatus();
    void setCurrentStatus(Status currentStatus);
};