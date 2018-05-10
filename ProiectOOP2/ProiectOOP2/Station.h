#pragma once

#include <iostream>
#include <fstream>
#include "Vehicle.h"
#include "Scooter.h"
#include "Car.h"
#include "Vain.h"
#include <vector>
#include "Driver.h"
#include <time.h>


using namespace std;

#define INF INT_MAX


class Station
{
	
	vector <Vehicle*> arr;
	Driver *soferi;
	int sizeN;
	static int countOrders;
	static int time;
public:
	//friend class Driver;
	Station();
	Station(int );
	int getCountOrders() {
		return countOrders;
	}
	int getTime() {
		return time;
	}
	//Station(int );
	int lessWeight();
	int getNumber(int *);
	int onTime(int, int);
	int onInterval(int, int, int);
	int kindaFast(int, int);
	int mostCloser(int *) ;
	bool checkRejection(int );
	void getOrders(istream&, ostream& );
	void addVehicle(int, bool, directions, int, int);
	friend istream& operator>>(istream&, Station&);
	friend ostream& operator<<(ostream&, const Station&);
	~Station();
};

