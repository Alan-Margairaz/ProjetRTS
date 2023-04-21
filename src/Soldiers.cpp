#include "Soldiers.h"

#include <iostream>

using namespace std;

///		SOLDIER BASE CLASS 
///
///		TODO : implement destroy(), pointers to ennemies & walls to apply damage, implement map movement
///		TODO : implement child classes for soldiers lvl 1,2 & 3


// Constructor, creation of the oject
Soldiers::Soldiers(int _hp, int _moveDistance, int _level, int _damage)
{

}

// Objects' destruction
Soldiers::~Soldiers()		
{

}

// Copy of the class
Soldiers::Soldiers(const Soldiers& src)	
{

}

// Instanciation of the copied class
Soldiers &Soldiers::operator=(const Soldiers& rhs)		
{

}

// Soldier's movement on the map
void Soldiers::move(int _moveDistance)
{

}

// Upgrade soldiers' rank
void Soldiers::upgrade(int _level, int _moveDistance, int _hp, string _name)
{

}

// Condition check if killing the enemy is possible or not:
void Soldiers::killEnemy(Soldiers& _soldiers, int _damage, int _level)
{
	
	_soldiers.setHP(_soldiers.getHP() - _damage);

	if (_soldiers.getHP() <= 0)
		_soldiers.destroy();
}

// Destruction method for the attacked ennemy:
void Soldiers::destroy()
{
	
}

// HP setter & getter:
void Soldiers::setHP(int new_hp)
{
	_hp = new_hp;
}
const int Soldiers::getHP()
{
	return _hp;
}

// Name setter & getter:
void Soldiers::setName(string new_name)
{
	_name = new_name;
}
const string Soldiers::getName()
{
	return _name;
}

// Placement on the map setter & getter:
void Soldiers::setPlacement(vector<int> new_placement)
{
	_placement = new_placement;
}
const vector<int> Soldiers::getPlacement()
{
	return _placement;
}


