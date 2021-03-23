#include "Actor.h"
class Spaceship : public Actor
{
private:
    int score;
    Animation leftAnimation;
    Animation rightAnimation;

public:
    Spaceship();
    ~Spaceship();
    void addToScore(int score);
    int getScore();

    // Override from Actor.
    void settings(Animation &animation, Animation &leftAnimation, Animation &rightAnimation,
                  int x, int y);
    void draw(RenderWindow &app);
};