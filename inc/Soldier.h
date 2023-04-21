#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class Soldier
{
private:
	int hp_;
	int armor_;


public:
	Soldier();
	~Soldier();
	Soldier(const Soldier& src);
	Soldier& operator=(const Soldier& rhs);

	void init();
	void move();
	void upgrade();
	void kill();

	int& get_time();
};