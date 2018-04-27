#pragma once
#include "Vehicle.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Vain :
	public Vehicle
{
	bool isCold;
public:
	Vain();
	Vain(int, int, int, bool, int, int);
	int getDistance(int, int);
	void afisare(ostream&);
	Vain& operator=(const Vain&);
	bool operator!=(const Vain&);
	friend istream& operator>>(istream&, Vain&);
	~Vain();
};

