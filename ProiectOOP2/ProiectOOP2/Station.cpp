#include "Station.h"



Station::Station()
{
	arr = nullptr;
	sizeN = 0;
//	cout << "Constructor called\n";
}

Station::Station(int size) {
	sizeN = size;
	arr = new Vehicle*[sizeN + 1];
	soferi = new Driver[sizeN + 1];
	for (int i = 1; i <= sizeN; i++) {
		arr[i] = nullptr;
		soferi[i].setSizeC(0);
	}
}

istream& operator>>(istream& in, Station& St) {
	int  p, sp, vol, cap, posX, posY;
	bool isC;
	for (int i = 1; i <= St.sizeN; i++) {
		in >> p;
		switch (p)
		{
		case 1:

			in >> cap >> vol >> posX >> posY;
			sp = 20;
			St.arr[i] = new Scooter(cap, vol, sp, posX, posY);
			break;
		case 2:
			in >> cap >> vol >> posX >> posY;
			sp = 10;
			St.arr[i] = new Car(cap, vol, sp, posX, posY);
			break;
		case 3:
			in >> cap >> vol >> isC >> posX >> posY;
			sp = 5;
			St.arr[i] = new Vain(cap, vol, sp, isC, posX, posY);
			break;
		default:
			break;
		}
	}
	return in;
}

int Station::countOrders = 0;
int Station::time = 0;

ostream& operator<<(ostream& out, const Station& obj) {
	for (int i = 1; i <= obj.sizeN; i++)
		obj.arr[i]->afisare(out);
	return out;
}

void Station::getOrders(istream& in) {
	int masa, volum, isC;
	countOrders++;
	bool rejected = false;
	int *distClient = new int[sizeN], *distDest = new int[sizeN];
	for (int i = 1; i <= sizeN; i++) {
		distClient[i] = distDest[i] = INF;
	}
	directions client, dest;
	int index = 0;
	in >> masa >> volum >> isC >> client.x >> client.y >> dest.x >> dest.y;
	Vain *p;
	for (int i = 1; i <= sizeN; i++) {
		arr[i]->update(masa, volum);
		if (!arr[i]->checkPossibility(isC)) {
			arr[i]->downgrade(masa, volum);
		}
		else {
			if (isC) {
				p = dynamic_cast<Vain*>(arr[i]);
				if (p) {
					if (p->getCold())
						distClient[i] = p->getDistance(client.x, client.y), index = i;
					else {
						rejected = true;
					}
				}
				else {
					rejected = true;
				}
			}
			else {
				index = i;
				distClient[i] = arr[i]->getDistance(client.x, client.y);
				distDest[i] = arr[i]->getDistance(client, dest);
			}
		}
	}
	for (int i = 1; i <= sizeN; i++) {
		//for (int j = 1; j <= countOrders; j++)
		soferi[i].aloca(1, client, dest);
	}
	index = mostCloser(distClient);
	soferi[index].computeDistance(arr[index]);
	cout << "Cel mai aproape de colet-----distanta pana la comanda: " << soferi[index].outDist() << "\tmasina aleasa: " << index << "\n" ;
	index = lessWeight();
	soferi[index].computeDistance(arr[index]);
	cout << "Cea mai putin incarcata masina-----distanta pana la comanda: " << soferi[index].outDist() << "\tmasina aleasa: " << index << "\n\n";

}

int Station::mostCloser(int *direc) {
	int min = INF, pos = 0;
	for (int i = 1; i <= sizeN; i++) {
		if (direc[i] < min) {
			min = direc[i];
			pos = i;
		}
	}
	return pos;
}

int Station::lessWeight() {
	int min = INF, pos = 0;
	for (int i = 1; i <= sizeN; i++) {
		if (arr[i]->getCapacity() < min) {
			min = arr[i]->getCapacity();
			pos = i;
			//cout << min << " " << pos << '\n';
		}
	}
	return pos;
}

int Station::onTime() {
	return 1;

}
Station::~Station()
{
	delete[] arr;
	delete[] soferi;
	//cout << "destructor called\n";
}
