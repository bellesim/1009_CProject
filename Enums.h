#pragma once

enum Status
{
    ALIVE,
    INVULNERABLE,
    EXPLODING,
    DEAD
};

enum GameState
{
    MAIN_MENU,
    GAME_PLAY,
    GAME_PAUSE,
    GAME_OVER,
    GAME_REPLAY
};

enum ActorType
{
    ENEMY,
    SPACESHIP,
    PROJECTILE
};