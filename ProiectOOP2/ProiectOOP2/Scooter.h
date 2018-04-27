#pragma once
#include "Vehicle.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Scooter :
	public Vehicle
{
public:
	Scooter();
	Scooter(int, int, int, int, int);
	int getDistance(int, int);
	void afisare(ostream&);
	Scooter& operator=(const Scooter&);
	bool operator!=(const Scooter&);
	friend istream& operator>>(istream&, Scooter&);
	~Scooter();
};

