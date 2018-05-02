#include "Vehicle.h"



Vehicle::Vehicle()
{
}

Vehicle::Vehicle(int x, int y, int z, int px, int py): capacitate(x), volum(y), speed(z), posX(px), posY(py){
	capacCurr = 0;
	volCurr = 0;
}

Vehicle& Vehicle::operator=(const Vehicle& obj) {
	if (*this != obj) {
		posX = obj.posX;
		posY = obj.posY;
		speed = obj.speed;
		volum = obj.volum;
		capacitate = obj.capacitate;
	}
	return *this;
}

bool Vehicle::operator!=(const Vehicle& obj) {
	if (posX == obj.posX || posY == obj.posY || speed == obj.speed || volum == obj.volum || capacitate == obj.capacitate)
		return false;
	return true;
}

istream& operator>>(istream& in, Vehicle& obj) {
	in >> obj.capacitate >> obj.volum >> obj.speed >> obj.posX >> obj.posY;
	return in;
}

ostream& operator<<(ostream& out, const Vehicle& obj) {
	out << "Capacitate: " << obj.capacitate << "\nVolum: " << obj.volum << "\nSpeed: " << obj.speed << "\nPozitionat " << obj.posX << " " << obj.posY <<'\n';
	return out;
}

void Vehicle::update(int masa, int volum) {
	capacCurr += masa;
	volCurr += volum;

}

void Vehicle::downgrade(int masa, int volum) {
	capacCurr -= masa;
	volCurr -= volum;
}

void Vehicle::updatePosition(int x, int y) {
	posX = x;
	posY = y;
}

Vehicle::~Vehicle()
{
}
