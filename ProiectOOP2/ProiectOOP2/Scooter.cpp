#include "Scooter.h"



Scooter::Scooter(){}

Scooter::Scooter(int x, int y, int z, int px, int py) : Vehicle(x, y, z, px, py){}

int Scooter::getDistance(int x, int y) {
	int distA = posX - x;
	distA *= distA;
	int distB = posY - y;
	distB *= distB;
	return (int)sqrt(distA + distB);
}

Scooter& Scooter::operator=(const Scooter& obj) {
	if (*this != obj) {
		posX = obj.posX;
		posY = obj.posY;
		speed = obj.speed;
		volum = obj.volum;
		capacitate = obj.capacitate;
	}
	return *this;
}

bool Scooter::operator!=(const Scooter& obj) {
	if (posX == obj.posX || posY == obj.posY || speed == obj.speed || volum == obj.volum || capacitate == obj.capacitate)
		return false;
	return true;
}

istream& operator>>(istream& in, Scooter& obj) {
	in >> static_cast<Vehicle&>(obj);
	return in;
}

void Scooter::afisare(ostream& out) {
	out << "Acest obiect este un Scuter\n";
	out << static_cast<Vehicle&>(*this) << '\n';

}

bool Scooter::checkPossibility(bool is) {
	if (capacCurr > capacitate)
		return false;
	else if (volum < volCurr)
		return false;
	return true;
}

int Scooter::getDistance(directions d1, directions d2) {
	int distA = d1.x - d2.x;
	distA *= distA;
	int distB = d1.y - d2.y;
	distB *= distB;
	return (int)sqrt(distA + distB);
}

Scooter::~Scooter()
{
}
