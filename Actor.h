#pragma once

#include "Animation.h"
using namespace std;
using namespace sf;

class Actor
{
public:
    float x, y, dx, dy, radius, angle;
    bool life;
    string name;
    Animation animation;
    Actor();
    ~Actor();
    void settings(Animation &a, int x, int y, float angle, int radius);
    void draw(RenderWindow &app);
};