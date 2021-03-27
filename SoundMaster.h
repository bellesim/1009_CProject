#pragma once

#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class SoundMaster
{
public:
    Music gamemusic;
    Music overmusic;
    
    SoundBuffer efire;
    SoundBuffer efire2;
    SoundBuffer edie;
    SoundBuffer edielow;
    SoundBuffer mselect;
    SoundBuffer mpause;
    SoundBuffer pcollide;

    Sound sound;

    SoundMaster();
    void playGame();
    void playFire();
};
