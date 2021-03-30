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

    Sound fireSound;

    Sound sound;

    SoundMaster();
    void playGameMusic();
    // void pauseGameMusic();
    // void stopGameMusic();
    // void playOverMusic();
    // void stopOverMusic();

    void playFire();
    // void playDie();
    // void playMenuSelect();
    // void playPause();
    void playCollide();
};
