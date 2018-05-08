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
		if (!arr[i]->checkPossibility(isC) || soferi[i].getCurrState()) {
			arr[i]->downgrade(masa, volum);
			soferi[i].setrejected(1);
		}
		else {
			if (isC) {
				p = dynamic_cast<Vain*>(arr[i]);
				if (p) {
					if (p->getCold()) {
						distClient[i] = p->getDistance(client.x, client.y), soferi[i].setrejected(0), index = i;
					}
					else {
						soferi[i].setrejected(1);
					}
				}
				else {
					soferi[i].setrejected(1);
				}
			}
			else {
				soferi[i].setrejected(0);
				distClient[i] = arr[i]->getDistance(client.x, client.y);
				distDest[i] = arr[i]->getDistance(client, dest);
			}
			
		}
	}
	int timeType, intervala, intervalb, secunda, notime;
	
	int cnt = 0;
	for (int i = 1; i <= sizeN; i++) {
		//for (int j = 1; j <= countOrders; j++)
		soferi[i].aloca(1, client, dest);
	
		if (soferi[i].get_rejected());
			//soferi[i].setrejected(1);
		else {
			cnt++;
		}
		//cout << soferi[i].get_rejected() << " ";
	}
	cout << '\n';
	if (cnt == 0) {
		in >> timeType;
		//cout << timeType << "\n";
		switch (timeType) {
		case 1:
			in >> secunda;
			break;
		case 2:
			in >> intervala >> intervalb;
			break;
		case 3:
			notime = INF;
			break;
		}
		cout << "Nicio masina nu poate prelua comanda!\n";
	}
	else{
		int position, number;
		in >> timeType;
		switch (timeType) {
		case 1:
			in >> secunda;
			position = getNumber(distClient);
			if (onTime(secunda, position) && checkRejection(position))
				cout << "Nu avem masina, ne cerem scuze!\n";
			else
				cout << "Exista o masinaa!! Ea este: " << position << '\n';
			break;
		case 2:
			in >> intervala >> intervalb;
			position = getNumber(distClient);
			if (onInterval(intervala, intervalb, position) && checkRejection(position))
				cout << "Nu avem masina, ne cerem scuze!\n";
			else
				cout << "Exista o masinaa!! Ea este: " << position << '\n';
			break;
		case 3:
			notime = INF;
			position = getNumber(distClient);
			if (kindaFast(notime, position) && checkRejection(position))
				cout << "Nu avem masina, ne cerem scuze!\n";
			else
				cout << "Exista o masinaa!! Ea este: " << position << '\n';
			break;
		}
		soferi[position].setCurrStatus(1);
		time += soferi[position].getTime(1);
		for (int i = 1; i <= sizeN; i++)
			if (soferi[i].getTime(1) >= time) {
				arr[i]->downgrade(masa, volum);
				//act.pos curr
				soferi[i].setCurrStatus(0);
			}

	}
	cout << time << " ";
	
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

int Station::onTime(int secunda, int pos) {
	
	if (soferi[pos].getTime(1) > secunda) {
		soferi[pos].setrejected(1);
		return 0;
	}
	return 1;
}

int Station::onInterval(int a, int b, int pos) {
	
	if (soferi[pos].getTime(1) < a || soferi[pos].getTime(1) > b)
	{
		soferi[pos].setrejected(1);
		return 0;
	}
	return 1;
}

int Station::kindaFast(int notime, int posi) {
	int min = INF, pos = 0;
	for (int i = 1; i <= sizeN; i++) {
		soferi[i].computeDistance(arr[i]);
		soferi[i].computeTime(arr[i]);
		if (soferi[i].getTime(1) < min && soferi[i].getTime(1) != -1 && !soferi[i].get_rejected()) {
			min = soferi[i].getTime(1);
			pos = i;
		}
	}
	//cout << pos << " ";
	return pos;
}

bool Station::checkRejection(int pos) {
	if (soferi[pos].get_rejected())
		return true;
	return false;
}

int Station::getNumber(int *dire) {
	int number = rand() % 3 + 1;
	switch (number) {
	case 1:
		return mostCloser(dire);
	case 2:
		return lessWeight();
	case 3:
		return rand() % sizeN + 1;
	}
}

Station::~Station()
{
	delete[] arr;
	delete[] soferi;
	//cout << "destructor called\n";
}
