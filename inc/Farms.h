#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>

using namespace std; 

class Farms
{
protected:
	int _hp, _cost, _currentIncome, _addIncome, _farmsNumber;
	vector<int> _placement, _placedFarms;
	string _name;

public:
	Farms(int _hp, int _cost, int _addedIncome, int _currentIncome, vector<int> _placedFarms, Farms& _farms);
	~Farms();
	Farms(const Farms& src);
	Farms& operator=(const Farms& rhs);

	void setHP(int new_hp);
	const int getHP();

	void setName(string new_name);			
	const string getName();		

	void setPlacement(vector<int> new_placement);
	const vector<int> getPlacement();

	void setIncome(int new_addedIncome);
	const int getIncome();

	void setFarmsNumber(int new_farmNumber);
	const int getFarmsNumber();
};