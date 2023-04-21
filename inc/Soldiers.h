#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class Soldiers
{
private:
	int hp_;
	int armor_;


public:
	Soldiers();
	~Soldiers();
	Soldiers(const Soldier& src);
	Soldiers& operator=(const Soldiers& rhs);

	void create();
	void move();
	void upgrade();
	void kill();

	int& get_time();
};