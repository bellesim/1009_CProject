#pragma once

#include "Animation.h"
using namespace std;
using namespace sf;

class Actor
{
public:
    int x, y, speed, hitPoints;
    bool left, right, up, down;
    string name;
    Animation animation;
    Actor();
    ~Actor();
    void settings(Animation &a, int x, int y);
    void draw(RenderWindow &app);
    void keyPressed();
    virtual void update();
};