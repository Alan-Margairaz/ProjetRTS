#include "Farms.h"

#include <iostream>

using namespace std;

Farms::Farms(int _hp, int _cost, int _addIncome, int _currentIncome, vector<int> _placedFarms, Farms& _farms)
{
	_farmsNumber++;
	_placedFarms.push_back(1);

	if (_farmsNumber++)
	{
		_farms.setIncome(_farms.getIncome() + 2);
		cout << "Income increased by 3 gold." << endl;
	}
};

Farms::~Farms()
{
	if (_hp <= 0)
		return;
};

Farms::Farms(const Farms& src)
{

};

Farms &Farms::operator=(const Farms& rhs)
{

};

// HP setter & getter:
void Farms::setHP(int new_hp)
{
	_hp = new_hp;
}
const int Farms::getHP()
{
	return _hp;
}

// Name setter & getter:
void Farms::setName(string new_name)
{
	_name = new_name;
}
const string Farms::getName()
{
	return _name;
}

// Placement on the map setter & getter:
void Farms::setPlacement(vector<int> new_placement)
{
	_placement = new_placement;
}
const vector<int> Farms::getPlacement()
{
	return _placement;
}

// Income getter and setter:
void Farms::setIncome(int new_addedIncome)
{
	_currentIncome = new_addedIncome;
}
const int Farms::getIncome()
{
	return _currentIncome;
}

// Farm number getter and setter, to increment the players' income:
void Farms::setFarmsNumber(int new_farmsNumber)
{
	_farmsNumber = new_farmsNumber;
}
const int Farms::getFarmsNumber()
{
	return _farmsNumber;
}


