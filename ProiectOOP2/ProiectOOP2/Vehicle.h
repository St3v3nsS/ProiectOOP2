#pragma once
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Vehicle{
protected:
	int posX, posY; 
	int speed;
	int capacitate;
	int volum;
public:
	Vehicle();
	Vehicle(int, int, int, int, int);
	virtual int getDistance(int , int ) = 0;
	virtual void afisare(ostream&) = 0;
	Vehicle& operator=(const Vehicle&);
	bool operator!=(const Vehicle&);
	friend istream& operator>>(istream&, Vehicle&);
	friend ostream& operator<<(ostream&, const Vehicle&);
	~Vehicle();
};

