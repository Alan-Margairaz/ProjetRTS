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
	int _hp, _moveDistance, _level, _damage;
	vector<int> _placement;
	string _name;

public:
	Soldiers(int _hp, int _moveDistance, int _level, int _damage);
	~Soldiers();
	Soldiers(const Soldiers& src);
	Soldiers& operator=(const Soldiers& rhs);

	void move(int _moveDistance);
	void upgrade(int _level, int _moveDistance, int _hp, string _name);
	void killEnemy(Soldiers& _soldiers, int _damage, int _level);
	void destroy();

	void setHP(int new_hp);
	const int getHP();

	void setName(string new_name);
	const string getName();

	void setPlacement(vector<int> new_placement);
	const vector<int> getPlacement();
};