// ProiectOOP2.cpp : Defines the entry point for the console application.
// Morosan Ionut - Mihai ----- Curierat Rapid (JoKer)

#include <iostream>
#include <fstream>
#include "Vehicle.h"
#include "Scooter.h"
#include "Car.h"
#include "Vain.h"
#include "Station.h"

using namespace std;

ifstream in("date.in");
ofstream out("date.out");

int main()
{
	srand(time(nullptr));
	int n;
	in >> n;
	Station station(n);
	in >> station;
	out << station;
	station.getOrders(in);
	station.getOrders(in);
	station.getOrders(in);
	
	out << station.getCountOrders() << " ";
	return 0;
}

