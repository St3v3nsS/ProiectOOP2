#include "Car.h"



Car::Car()
{
}

Car::Car(int x, int y, int z, int px, int py): Vehicle(x, y, z, px, py){}

int Car::getDistance(int x, int y) {
	int distA = abs(posX - x);
	int distB = abs(posY - y);
	return distA + distB;
}

Car& Car::operator=(const Car& obj) {
	if (*this != obj) {
		posX = obj.posX;
		posY = obj.posY;
		speed = obj.speed;
		volum = obj.volum;
		capacitate = obj.capacitate;
	}
	return *this;
}

bool Car::operator!=(const Car& obj) {
	if (posX == obj.posX || posY == obj.posY || speed == obj.speed || volum == obj.volum || capacitate == obj.capacitate)
		return false;
	return true;
}

istream& operator>>(istream& in, Car& obj) {
	in >> static_cast<Vehicle&>(obj);
	return in;
}

void Car::afisare(ostream& out) {
	out << "Acest obiect este o Masina\n";
	out << static_cast<Vehicle&>(*this);
}

Car::~Car()
{
}
