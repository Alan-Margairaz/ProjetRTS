#include "Soldiers.h"

#include <iostream>

using namespace std;

///		SOLDIER BASE CLASS 
///
///		TODO : in Soldiers::upgrade() implement the keyboard key for upragde and money consumption


// Constructor, creation of the oject
Soldiers::Soldiers(int _hp, int _moveDistance, int _level, int _damage, int _cost)
{

}

// Objects' destruction
Soldiers::~Soldiers()		
{
	if (_hp <= 0)
		return;
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
void Soldiers::upgrade(int _level, int _moveDistance, int _hp, Soldiers& _soldiers)
{
	switch (_level)		// Switch en fonction du level actuel du soldat pour améliorer ses caractéristiques
	{
	case 1: 
		_soldiers.getLevel() + 1;
		_moveDistance + 1;
		_hp + 10;
		_soldiers.setName("SoldierLVL2");
		cout << "Soldier successfully upgraded to LVL2 !" << endl;
		break;
	case 2:
		_soldiers.getLevel() + 1;
		_moveDistance + 1;
		_hp + 10;
		_soldiers.setName("SoldierLVL3");
		cout << "Soldier successfully upgraded to LVL3 !" << endl;
		break;
	default: 
		cout << "Unit is at max level." << endl;
		break;
	}
}

// Condition check if killing the enemy is possible or not:
void Soldiers::attackEnemy(Soldiers& _soldiers, int _damage, int _level)
{
	if(_level >= 2)
		_soldiers.setHP(_soldiers.getHP() - _damage);
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

// Level getter and setter:
void Soldiers::setLevel(int new_level)
{
	_level = new_level;
}
const int Soldiers::getLevel()
{
	return _level;
}



