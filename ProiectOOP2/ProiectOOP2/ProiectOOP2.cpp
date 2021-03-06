// ProiectOOP2.cpp : Defines the entry point for the console application.
// Morosan Ionut - Mihai ----- Curierat Rapid (JoKer)

#include <iostream>
#include <fstream>
#include "Vehicle.h"
#include "Scooter.h"
#include "Car.h"
#include "Vain.h"
#include "Station.h"
#include <string>
#include "JoKerException.hpp"
#include <algorithm>


using namespace std;

ifstream in("date.in");
ofstream out("date.out");

template <typename E>
E checkTrue(string type, E base) {
	if (type.length() == 1 && (type[0] == 'Y' || type[0] == 'N'))
		return type[0];
	else if(any_of(begin(type), end(type), islower) || any_of(begin(type), end(type), isupper) || any_of(begin(type), end(type), isblank) || type.empty() || type.length() > 10)
			throw JoKerException("Mai incercati!\n");
	else if (stoi(type) == stod(type)) {
			return atoi(type.c_str());
	}
	else
		throw JoKerException("Mai incercati!\n");
}

int main()
{
	srand(time(nullptr));
	int n;
	in >> n;
	Station station(n);
	in >> station;
	int carCap, carVol;
	station.getOrders(in, cout);
	int opt = 0, checkConst = 0;
	directions d, Dconst;
	Dconst.x = Dconst.y = 0;
	char charac, chConst;
	int typeCar;
	string str;
	//out << station.getCountOrders() << " ";
	do {
		cout << "Ne bucuram ca ati sunat la firma de curierat JoKer! Cu ce va putem ajuta?\n"
			<< "--------1. Vizualizati vehiculele disponibile!-------\n"
			<< "--------2. Adaugati un vehicul-----------------------\n"
			<< "--------3. Adaugati o comanda!-----------------------\n"
			<< "--------4. Aflati numarul de comenzi din ziua de azi-\n"
			<< "--------5. Exit--------------------------------------\n";
		try {
			getline(cin,str);
			opt = checkTrue(str, opt);
			
		}
		catch (const JoKerException& e) {
			
			cout << e.what();
			//continue;
		}
		if (opt > 5)
			cout << "Nu este vina noastra ca nu stiti sa cititi ca numarul maxim este 5. O zi buna!\n";
		switch (opt)
		{
		case 1:
			cout << station;
			break;
		case 2:
			
			cout << "Introduceti tipul Vehiculelor:\n1.) Scuter\n"
				<< "2.) Duba\n"
				<< "3.) Masina\n";
			try {
				getline(cin, str);
				typeCar = checkTrue(str, checkConst);
			}
			catch (const JoKerException& e) {
				cout << e.what();
				//continue;
			}
			cout << "Introduceti capacitatea si volumul: ";
			try {
				getline(cin, str);
				carCap = checkTrue(str, checkConst);
				getline(cin, str);
				carVol = checkTrue(str, checkConst);
			}
			catch (const JoKerException& e) {
				cout << e.what();
				continue;
			}
			cout << "Introduceti pozitiile (x si apoi y): ";
			try {
				getline(cin, str);
			    d.x = checkTrue(str, checkConst);
				getline(cin, str);
				d.y = checkTrue(str, checkConst);
			}
			catch (const JoKerException& e) {
				cout << e.what();
				continue;
			}
			
			switch (typeCar)
			{
			case 1:
				station.addVehicle(20, 0, d, carCap, carVol);
				break;
			case 2:
				cout << "Contine lada frigorifica? Y/N\n";
				getline(cin, str);
				charac = checkTrue(str, charac);
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
			cout << "Se va apasa tasta 1. Se va introduce pe rand: Capacitatea, volumul, daca este frigorifica sau nu(1/0),\npozitia clientului, pozitia destinatarului, tipul de livrare(1-secunda, 2-interval, 3-notime)\n";
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
	in.close();
	out.close();
	return 0;
}

