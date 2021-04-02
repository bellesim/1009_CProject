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
    int speed, width, height;
    bool left, right, up, down;

private:
    Animation animation;

public:
    ActorType type;
    Actor();
    void settings(Animation &a, int x, int y);
    void draw(RenderWindow &app);
    void keyPressed();
    void update();
    Position getPosition();
    bool isCollide(int x, int y);
};