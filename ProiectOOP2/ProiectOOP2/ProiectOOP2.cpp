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
	int carCap, carVol;
	station.getOrders(in, cout);
	int opt;
	directions d;
	char charac;
	int typeCar;
	//out << station.getCountOrders() << " ";
	do {
		cout << "Ne bucuram ca ati sunat la firma de curierat JoKer! Cu ce va putem ajuta?\n"
			<< "--------1. Vizualizati vehiculele disponibile!-------\n"
			<< "--------2. Adaugati un vehicul-----------------------\n"
			<< "--------3. Adaugati o comanda!-----------------------\n"
			<< "--------4. Aflati numarul de comenzi din ziua de azi-\n"
			<< "--------5. Exit--------------------------------------\n";
		cin >> opt;
		switch (opt)
		{
		case 1:
			cout << station;
			break;
		case 2:
			
			cout << "Introduceti tipul Vehiculelor:\n1.) Scuter\n"
				<< "2.) Duba\n"
				<< "3.) Masina\n";
			cin >> typeCar;
			cout << "Introduceti capacitatea si volumul: ";
			cin >> carCap >> carVol;
			cout << "Introduceti pozitiile (x si apoi y): ";
			cin >> d.x >> d.y;
			switch (typeCar)
			{
			case 1:
				station.addVehicle(20, 0, d, carCap, carVol);
				break;
			case 2:
				cout << "Contine lada frigorifica? Y/N\n";
				cin >> charac;
				cin.get();
				if (charac == 'Y')
					station.addVehicle(5, 1, d, carCap, carVol);
				else
					station.addVehicle(5, 0, d, carCap, carVol);
				break;
			case 3: 
				station.addVehicle(10, 0, d, carCap, carVol);
				break;
			default:
				break;
			}
			break;
			
		case 3:
			station.getOrders(cin, cout);
			break;
		case 4:
			cout << station.getCountOrders() << '\n';
			break;
		case 5:
			exit(EXIT_SUCCESS);
		default:
			break;
		}
	} while (opt <= 5);
	
	return 0;
}

