#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class NPC
{
private:
    
public:
    NPC();
    ~NPC();
    NPC(const NPC& src);
    NPC &operator=(const NPC& rhs);
    void init();
    int &get_time();
};


