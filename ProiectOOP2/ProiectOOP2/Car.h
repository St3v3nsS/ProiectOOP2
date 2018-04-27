#pragma once
#include "Vehicle.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Car :
	public Vehicle
{
public:
	Car();
	Car(int, int, int, int, int);
	int getDistance(int, int);
	void afisare(ostream&);
	Car& operator=(const Car&);
	bool operator!=(const Car&);
	friend istream& operator>>(istream&, Car&);
	~Car();
};

