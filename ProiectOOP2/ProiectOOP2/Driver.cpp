#include "Driver.h"



Driver::Driver()
{
	sizeC = 0;
	CurrState = false;
	rejected = 0;
	client = nullptr;
	distances = nullptr;
	livrate = nullptr;
	timp = nullptr;
}

void Driver::aloca(int size, directions d1, directions d2) {
	sizeC = size;
	timp = new int[size + 1];
	client = new P[size + 1];
	livrate = new B[size + 1];
	for (int i = 1; i <= sizeC; i++)
	{
		client[i].first = d1;
		//cout << client[i].first.x << " ";
		client[i].second = d2;
		timp[i] = -1;
		//cout << client[i].second.y << " ";
		//distances[i].first = INF;
		//distances[i].second = INF;
		livrate[i].first = 0;
		livrate[i].second = 0;
		//cout << client[i].first.x << " ";
	}
}

Driver::Driver(int size, directions d1, directions d2) {
	sizeC = size;
	client = new P[size + 1];
	livrate = new B[size + 1];
	for (int i = 1; i <= sizeC; i++)
	{
		client[i].first = d1;
		client[i].second = d2;
		//distances[i].first = INF;
		//distances[i].second = INF;
		livrate[i].first = 0;
		livrate[i].second = 0;
	}
}

P& Driver::operator[](int pos) {
	return client[pos];
}

void Driver::fistInfirstOut(Vehicle *car) {
	if (!rejected)
	{
		car->updatePosition(client[1].first.y, client[1].second.y);
		CurrState = 0;
	}
}

void Driver::computeDistance(Vehicle* masina) {
	distances = new dir[sizeC + 1];
	for (int i = 1; i <= sizeC; i++) {
		if (!livrate[i].first) {
			distances[i] = make_pair(masina->getDistance(client[i].first.x, client[i].first.y), 1);
		}
		else if (livrate[i].first && !livrate[i].second) {
			distances[i] = make_pair(masina->getDistance(client[i].first, client[i].second), 2);
		}
		else
		{
			distances[i] = make_pair(INF, 1);
			//cout << "INF\n";
		}
	}
	
	
}

void Driver::computeTime(Vehicle* masina) {
	for (int i = 1; i <= sizeC; i++) {
		if (distances[i].first != INF) {
			//cout <<  masina->getSpeed() << " ";
			timp[i] = distances[i].first / masina->getSpeed();
		
		}
		if(distances[i].second != INF)
			timp[i] += distances[i].second / masina->getSpeed();
		//cout << timp[i] << " ";
	}
	//cout << '\n';
}

void Driver::closer(Vehicle *car) {
	int min = INF, pos = 0;
	for (int i = 1; i <= sizeC; i++)
		if (distances[i].first < min) {
			min = distances[i].first;
			pos = i;
		}
	if (distances[pos].second == 1)
		livrate[pos].first = 1;
	else {
	
		livrate[pos].second = 1;
	}
	//cout << pos << " ";
	if (!rejected) {
		car->updatePosition(client[pos].second.x, client[pos].second.y);
		CurrState = 0;
	}
	
}

void Driver::priority(Vehicle* car) {
	int min = INF, pos = 0;
	for (int i = 1; i <= sizeC; i++)
	{
		if (timp[i] < min && timp[i] != -1) {
			min = timp[i];
			pos = i;
		}
	}
	//cout << pos << " " ;
	if (!rejected) {
		car->updatePosition(client[pos].second.x, client[pos].second.y);
		CurrState = 0;
	}
}

void Driver::getRandomNumber(Vehicle* car) {
	int number = rand() % 3 + 1;
	switch (number)
	{
	case 1:
		fistInfirstOut(car);
		break;	
	case 2:
		closer(car);
		break;
	case 3:
		priority(car);
		break;
	}
}

Driver::~Driver()
{
	delete[] client;
	delete[] distances;
	delete[] livrate;
	delete[] timp;
}
