#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>

using namespace std;

class Soldiers
{
protected:
	int _hp, _moveDistance, _level, _damage, _cost;
	vector<int> _placement;
	string _name;

public:
	Soldiers(int _hp, int _moveDistance, int _level, int _damage, int _cost);
	~Soldiers();
	Soldiers(const Soldiers& src);
	Soldiers& operator=(const Soldiers& rhs);

	void move(int _moveDistance);
	void upgrade(int _level, int _moveDistance, int _hp, Soldiers& _soldiers);
	void attackEnemy(Soldiers& _soldiers, int _damage, int _level);

	void setHP(int new_hp);
	const int getHP();

	void setName(string new_name);
	const string getName();

	void setPlacement(vector<int> new_placement);
	const vector<int> getPlacement();

	void setLevel(int new_level);
	const int getLevel();
};