#include "Walls.h"

#include <iostream>
#include <string>

Walls::Walls(int _hp, int _level, int _cost)
{

}

Walls::~Walls()
{
	if (_hp <= 0)
		return;
}

Walls::Walls(const Walls& src)
{

}

Walls& Walls::operator=(const Walls& rhs)
{

}

// Upgrade of the wall from lvl1 to 2
void Walls::upgrade(int _level, int _hp, Walls& _walls)
{
	if (_level == 1)
	{
		_walls.getLevel() + 1;
		_hp + 10;
	}
}

// HP setter & getter:
void Walls::setHP(int new_hp)
{
	_hp = new_hp;
}
const int Walls::getHP()
{
	return _hp;
}

// Name setter & getter:
void Walls::setName(string new_name)
{
	_name = new_name;
}
const string Walls::getName()
{
	return _name;
}

// Placement on the map setter & getter:
void Walls::setPlacement(vector<int> new_placement)
{
	_placement = new_placement;
}
const vector<int> Walls::getPlacement()
{
	return _placement;
}

// Level getter and setter:
void Walls::setLevel(int new_level)
{
	_level = new_level;
}
const int Walls::getLevel()
{
	return _level;
}
