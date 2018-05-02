#pragma once
#include "Vehicle.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include "Station.h"

using namespace std;

class Car :
	public Vehicle
{
public:
	Car();
	Car(int, int, int, int, int);
	int getDistance(int, int);
	int getDistance(directions, directions);
	void afisare(ostream&);
	bool checkPossibility(bool);
	Car& operator=(const Car&);
	bool operator!=(const Car&);
	friend istream& operator>>(istream&, Car&);
	~Car();
};

