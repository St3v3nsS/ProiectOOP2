#include "Vain.h"



Vain::Vain()
{
}

Vain::Vain(int x, int y, int z, bool is, int px, int py) : Vehicle(x, y, z, px, py), isCold(is){}

int Vain::getDistance(int x, int y) {
	int distA = abs(posX - x);
	int distB = abs(posY - y);
	return distA + distB;
}

Vain& Vain::operator=(const Vain& obj) {
	if (*this != obj) {
		posX = obj.posX;
		posY = obj.posY;
		speed = obj.speed;
		volum = obj.volum;
		capacitate = obj.capacitate;
		isCold = obj.isCold;
	}
	return *this;
}

bool Vain::operator!=(const Vain& obj) {
	if (posX == obj.posX || posY == obj.posY || speed == obj.speed || volum == obj.volum || capacitate == obj.capacitate || isCold == obj.isCold)
		return false;
	return true;
}

istream& operator>>(istream& in, Vain& obj) {
	in >> static_cast<Vehicle&>(obj);
	in >> obj.isCold;
	return in;
}

void Vain::afisare(ostream& out) {
	out << "Acest obiect este o Duba\n";
	out << static_cast<Vehicle&>(*this);
	if (isCold == 1) {
		out << "Este o duba frigorifica\n";
	}
	else {
		out << "Nu este o duba frigorifica\n";
	}
}

Vain::~Vain()
{
}
