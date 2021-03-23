#pragma once

#include "Animation.h"
using namespace std;
using namespace sf;

class Actor
{
protected:
    int speed, hitPoints;
    bool left, right, up, down;
    int x, y, width, height;

private:
    Animation animation;

public:
    Actor();
    void settings(Animation &a, int x, int y);
    void draw(RenderWindow &app);
    void keyPressed();
    void update();
    int getHitPoints();
};