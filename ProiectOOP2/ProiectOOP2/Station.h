#pragma once

#include <iostream>
#include <fstream>
#include "Vehicle.h"
#include "Scooter.h"
#include "Car.h"
#include "Vain.h"
#include <vector>
#include "Driver.h"

using namespace std;

#define INF INT_MAX


class Station
{
	
	Vehicle **arr;
	Driver *soferi;
	int sizeN;
	static int countOrders;
	static int time;
public:
	friend class Driver;
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
	int onTime();
	int mostCloser(int *) ;
	void getOrders(istream&);
	friend istream& operator>>(istream&, Station&);
	friend ostream& operator<<(ostream&, const Station&);
	~Station();
};

