#pragma once

#include "Enemy.h"
#include "Position.h"

using namespace std;
using namespace sf;

class Formation
{
public:
    Formation();
    static vector<Enemy *> generateRandomFormation(int count, Animation enemyAnim);
    static vector<Position *> generateHorizontalLeft();
    static vector<Position *> generateHorizontalRight();
    static vector<Position *> generateDiagonalLeft();
    static vector<Position *> generateDiagonalRight();
};