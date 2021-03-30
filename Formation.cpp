#include "Formation.h"
#include "Game.h"

Formation::Formation() {}

vector<Enemy *> Formation::generateRandomFormation(int count, Animation &enemyAnim,
                                                   Animation &explosionAnim)
{
    vector<Enemy *> enemies;

    if (rand() % 4 + 1 != 1)
    {
        return enemies;
    }

    int randomFormation = rand() % 4 + 1;
    vector<Position *> positions;

    if (randomFormation == 1)
    {
        positions = generateHorizontalLeft();
    }
    else if (randomFormation == 2)
    {
        positions = generateHorizontalRight();
    }

    else if (randomFormation == 3)
    {
        positions = generateDiagonalLeft();
    }

    else if (randomFormation == 4)
    {
        positions = generateDiagonalRight();
    }

    int randomEnemyCount = rand() % (count / 4) + 1;
    if (randomEnemyCount > 5)
    {
        randomEnemyCount = 5;
    }

    int space = -50;
    int startX = ((rand() % 1000 + 1) + 4) / 5 * 5;
    for (int i = 0; i < randomEnemyCount; i++)
    {
        Enemy *enemy = new Enemy();
        enemy->settings(enemyAnim, explosionAnim, positions,
                        startX,
                        space);
        enemies.push_back(enemy);
        space -= 100;
    }

    return enemies;
}

vector<Position *> Formation::generateHorizontalLeft()
{
    vector<Position *> positions;

    int position = rand() % 2 + 1;

    if (position == 1)
    {
        positions.push_back(new Position(Game::WIDTH - 80, 150));
        positions.push_back(new Position(Game::WIDTH - 300, 150));
    }
    else if (position == 2)
    {
        positions.push_back(new Position(Game::WIDTH - 150, 100));
        positions.push_back(new Position(50, 100));
    }
    else
    {
        positions.push_back(new Position(Game::WIDTH - 80, 300));
        positions.push_back(new Position(Game::WIDTH - 300, 300));
    }

    return positions;
}

vector<Position *> Formation::generateHorizontalRight()
{
    vector<Position *> positions;

    int position = rand() % 3 + 1;

    if (position == 1)
    {
        positions.push_back(new Position(50, 150));
        positions.push_back(new Position(300, 150));
    }
    else if (position == 2)
    {
        positions.push_back(new Position(150, 100));
        positions.push_back(new Position(Game::WIDTH - 150, 100));
    }
    else
    {
        positions.push_back(new Position(50, 300));
        positions.push_back(new Position(300, 300));
    }

    return positions;
}

vector<Position *> Formation::generateDiagonalLeft()
{
    vector<Position *> positions;

    int position = rand() % 3 + 1;

    if (position == 1)
    {
        positions.push_back(new Position(Game::WIDTH - 100, 100));
        positions.push_back(new Position(Game::WIDTH - 250, 250));
    }
    else if (position == 2)
    {
        positions.push_back(new Position(Game::WIDTH - 100, 200));
        positions.push_back(new Position(Game::WIDTH - 250, 350));
    }
    else
    {
        positions.push_back(new Position(Game::WIDTH - 100, 150));
        positions.push_back(new Position(Game::WIDTH - 350, 400));
    }
    return positions;

    return positions;
}

vector<Position *> Formation::generateDiagonalRight()
{
    vector<Position *> positions;

    int position = rand() % 3 + 1;

    // Create formation in a random position, 3 choices.
    if (position == 1)
    {
        positions.push_back(new Position(100, 100));
        positions.push_back(new Position(250, 250));
    }
    else if (position == 2)
    {
        positions.push_back(new Position(100, 200));
        positions.push_back(new Position(250, 350));
    }
    else
    {
        positions.push_back(new Position(100, 150));
        positions.push_back(new Position(350, 400));
    }
    return positions;

    return positions;
}