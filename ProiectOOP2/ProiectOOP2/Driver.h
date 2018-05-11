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
	int *timp;
	int rejected;
	bool CurrState;
	friend class Vehicle;
public:
	Driver();
	Driver(int, directions, directions);
	void aloca(int, directions, directions);
	P* begin() {
		return client;
	}
	P& operator[](int);
	void setrejected(int p) {
		rejected = p;
	}
	int get_rejected() {
		return rejected;
	}
	void setSizeC(int x) {
		sizeC = x;
	}
	void fistInfirstOut(Vehicle *);
	void closer(Vehicle *);
	int getTime(int pos) {
		return timp[pos];
	}
	void setCurrStatus(bool p) {
		CurrState = p;
	}
	bool getCurrState() {
		return CurrState;
	}
	int getSizec() {
		return sizeC;
	}
	void computeDistance(Vehicle*);
	void computeTime(Vehicle*);
	void priority(Vehicle* );
	void getRandomNumber(Vehicle *);
	~Driver();
};

