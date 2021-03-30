#include "SoundMaster.h"
#include <iostream>

SoundMaster::SoundMaster()
{
    try
    {
        // ready to stream music audio, NOT fully loaded into memory:
        if (!gamemusic.openFromFile("music/game.wav"))
        {
            throw runtime_error("game.wav");
        }
        if (!overmusic.openFromFile("music/gameover.wav"))
        {
            throw runtime_error("gameover.wav");
        }

        // load up samples:
        if (!efire.loadFromFile("sounds/enemyfire.wav"))
        {
            throw runtime_error("enemyfire.wav");
        }
        if (!efire2.loadFromFile("sounds/enemyfire2.wav"))
        {
            throw runtime_error("enemyfire2.wav");
        }
        if (!edie.loadFromFile("sounds/enemydie.wav"))
        {
            throw runtime_error("enemydie.wav");
        }
        if (!edielow.loadFromFile("sounds/enemydielow.wav"))
        {
            throw runtime_error("enemydielow.wav");
        }
        if (!mselect.loadFromFile("sounds/menuselect.wav"))
        {
            throw runtime_error("menuselect.wav");
        }
        if (!mpause.loadFromFile("sounds/pausesig.wav"))
        {
            throw runtime_error("pausesig.wav");
        }
        if (!pcollide.loadFromFile("sounds/playercollide.wav"))
        {
            throw runtime_error("playercollide.wav");
        }
    }

    catch (exception e)
    {
        cout << "Error: Failed to load " << e.what();
    }
}

// main game music control

void SoundMaster::playGameMusic()
{
    gamemusic.play();
}

void SoundMaster::pauseGameMusic()
{
    gamemusic.pause();
}

void SoundMaster::stopGameMusic()
{
    gamemusic.stop();
}

// game over music control

void SoundMaster::playOverMusic()
{
    overmusic.play();
}

void SoundMaster::stopOverMusic()
{
    overmusic.stop();
}

// sfx fire controls

void SoundMaster::playFire()
{
    if ((rand() % 2))
    {
        sound.setBuffer(efire);
    }
    else
    {
        sound.setBuffer(efire2);
    }

    sound.play();
}

void SoundMaster::playDie()
{
    if ((rand() % 2))
    {
        sound.setBuffer(edie);
    }
    else
    {
        sound.setBuffer(edielow);
    }

    sound.play();
}

void SoundMaster::playMenuSelect()
{
    sound.setBuffer(mselect);
    sound.play();
}

void SoundMaster::playPause()
{
    sound.setBuffer(mpause);
    sound.play();
}

void SoundMaster::playCollide()
{
    sound.setBuffer(pcollide);
    sound.play();
}