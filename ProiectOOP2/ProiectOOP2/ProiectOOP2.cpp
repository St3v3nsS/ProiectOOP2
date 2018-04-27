// ProiectOOP2.cpp : Defines the entry point for the console application.
// Morosan Ionut - Mihai ----- Curierat Rapid (Fan Courier)

#include <iostream>
#include <fstream>
#include "Vehicle.h"
#include "Scooter.h"
#include "Car.h"
#include "Vain.h"

using namespace std;

ifstream in("date.in");
ofstream out("date.out");

int main()
{
	int n, p, sp, vol, cap, posX, posY;
	bool isC;
	in >> n;
	Vehicle **arr = new Vehicle*[n + 1];
	for (int i = 1; i <= n; i++) {
		in >> p;
		switch (p)
		{
		case 1:
			
			in >> cap >> vol >> sp >> posX >> posY;
			arr[i] = new Scooter(cap, vol, sp, posX, posY);
			//in >> arr[i];
			break;
		case 2:
			in >> cap >> vol >> sp >> posX >> posY;
			arr[i] = new Car(cap, vol, sp, posX, posY);
			break;
		case 3:
			in >> cap >> vol >> sp >> isC >> posX >> posY;
			arr[i] = new Vain(cap, vol, sp, isC, posX, posY);
			break;
		default:
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		arr[i]->afisare(out);
	}
    return 0;
}

