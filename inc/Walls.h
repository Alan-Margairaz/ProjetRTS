#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>

using namespace std; 

class Walls
{
protected:
	vector<int> _placement;
	int _hp, _level;
	string _name;

public: 
	Walls(int _hp, int _level, int _cost);
	~Walls();
	Walls(const Walls& src);
	Walls& operator=(const Walls& rhs);

	void upgrade(int _level, int _hp, Walls& _walls);

	void setHP(int new_hp);
	const int getHP();

	void setName(string new_name);
	const string getName();

	void setPlacement(vector<int> new_placement);
	const vector<int> getPlacement();

	void setLevel(int new_level);
	const int getLevel();
};