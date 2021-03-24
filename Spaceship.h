#include "Actor.h"

class Projectile;

class Spaceship : public Actor
{
private:
    int score;
    Animation leftAnimation;
    Animation rightAnimation;
    int reloadCounter;
    int currentReloadCounter;

public:
    Spaceship();
    ~Spaceship();
    void addToScore(int score);
    int getScore();
    Projectile *shoot(Animation projectileAnim);
    // Override from Actor.
    void settings(Animation &animation, Animation &leftAnimation, Animation &rightAnimation,
                  int x, int y);
    void draw(RenderWindow &app);
};