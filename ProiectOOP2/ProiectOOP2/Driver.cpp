#include "Driver.h"



Driver::Driver()
{
	sizeC = 0;
	client = nullptr;
	distances = nullptr;
	livrate = nullptr;
}

void Driver::aloca(int size, directions d1, directions d2) {
	sizeC = size;
	client = new P[size + 1];
	livrate = new B[size + 1];
	for (int i = 1; i <= sizeC; i++)
	{
		client[i].first = d1;
		//cout << client[i].first.x << " ";
		client[i].second = d2;
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

P* Driver::fistInfirstOut() {
	return client;
}

void Driver::computeDistance(Vehicle* masina) {
	distances = new dir[sizeC + 1];
	for (int i = 1; i <= sizeC; i++) {
		if (!livrate[i].first) {
			distances[i] = make_pair(masina->getDistance(client[i].first.x, client[i].first.y), 1);
		}
		else if (livrate[i].first && !livrate[i].second) {
			distances[i] = make_pair(masina->getDistance(client[i].first, client[i].second),2);
		}
		else
		{
			distances[i] = make_pair(INF, 1);
		}
	}
	
}

P Driver::closer() {
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
	return client[pos];
	
}

P Driver::priority() {
	return client[1];

}

Driver::~Driver()
{
	delete[] client;
	delete[] distances;
	delete[] livrate;
}
