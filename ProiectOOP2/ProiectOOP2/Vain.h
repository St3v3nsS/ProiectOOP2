#pragma once
#include "Vehicle.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include "Station.h"

using namespace std;

class Vain :
	public Vehicle
{
	bool isCold;
public:
	Vain();
	Vain(int, int, int, bool, int, int);
	int getDistance(int, int);
	int getDistance(directions , directions);
	void afisare(ostream&);
	bool checkPossibility(bool);
	bool getCold() {
		return isCold;
	};
	Vain& operator=(const Vain&);
	bool operator!=(const Vain&);
	friend istream& operator>>(istream&, Vain&);
	~Vain();
};

