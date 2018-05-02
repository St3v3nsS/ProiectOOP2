#pragma once

#include <iostream>
#include <fstream>
#include "Vehicle.h"
/*#include "Scooter.h"
#include "Car.h"
#include "Vain.h"
include "Station.h"
*/
using namespace std;

typedef pair<directions, directions> P;
typedef pair<bool, bool> B;
typedef pair<int, int> dir;

class Driver
{protected:
	P *client;
	B *livrate;
	dir *distances;
	int sizeC;
	friend class Vehicle;
public:
	Driver();
	Driver(int, directions, directions);
	void aloca(int, directions, directions);
	P* begin() {
		return client;
	}
	P& operator[](int);
	void setSizeC(int x) {
		sizeC = x;
	}
	P* fistInfirstOut();
	P closer();
	void computeDistance(Vehicle*);
	P priority();
	int outDist() {
		return distances[1].first;
	}
	~Driver();
};

