#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
//#include "Station.h"



using namespace std;

#define INF INT_MAX

struct directions {
	int x, y;
};

class Vehicle{
protected:
	int posX, posY; 
	int speed;
	int capacitate;
	int volum;
	int capacCurr, volCurr;
public:
	Vehicle();
	Vehicle(int, int, int, int, int);
	virtual int getDistance(int , int ) = 0;
	virtual int getDistance(directions, directions) = 0;
	virtual void afisare(ostream&) = 0;
	Vehicle& operator=(const Vehicle&);
	bool operator!=(const Vehicle&);
	void update(int, int);
	int getCapacity() {
		return capacCurr;
	}
	void downgrade(int, int);
	void updatePosition(int, int);
	virtual bool checkPossibility(bool) = 0;
	friend istream& operator>>(istream&, Vehicle&);
	friend ostream& operator<<(ostream&, const Vehicle&);
	~Vehicle();
};

