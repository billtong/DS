#include<iostream>
#include<algorithm>
#include "FlightMatrix.h"

#define UNKNOWN -1
#define BIG_INT 999999

using std::cout;
using std::endl;
using std::to_string;

FlightMatrix::FlightMatrix(int length, int value)
{
	void *matrixPtr = operator new(length * sizeof(FlightOptions));
	matrix = reinterpret_cast<FlightOptions **>(matrixPtr);
	for (int i = 0; i < length; i++) {
		void *listPtr = operator new(length * sizeof(FlightOptions));
		FlightOptions *list = reinterpret_cast<FlightOptions *>(listPtr);
		for (int j = 0; j < length; j++) {
			new (&list[j]) FlightOptions;
		}
		matrix[i] = list;
	}
	FlightMatrix::length = length;
}

FlightMatrix::~FlightMatrix()
{
	for (int i = 0; i < FlightMatrix::length; i++)
	{
		for (int j = 0; j < FlightMatrix::length; j++) {
			matrix[i][j].~FlightOptions();
		}
		operator delete(matrix[i]);
	}
	operator delete(matrix);
}

void FlightMatrix::dijkstra(int start, int end)
{
	vector<FlightGraphVertex> s(0);
	vector<FlightGraphVertex> u(length);
	for (int i = 0; i < length; i++) {
		if (i == start)
			u[i] = *new FlightGraphVertex(i, i, 0, 0, 0);
		else
			u[i] = *new FlightGraphVertex(UNKNOWN, i, 0, 0, BIG_INT);
	}
	while (u.size() > 0)
	{	
		FlightGraphVertex minVex(&u[0]);
		int removeIndex = 0, i = 0;
		for (i = 0; i < u.size(); i++) {
			if (u[i].source!=UNKNOWN && minVex.duration > u[i].duration) {
				minVex.setAll(u[i]);
				removeIndex = i;
			}
		}
		if (minVex.duration == BIG_INT)
		{
			cout << "ERROR: there is no valid road!" << endl;
			break;
		}
		s.push_back(minVex);
		u.erase(u.begin() + removeIndex);
		if (minVex.destination == end)
			break;
		for (int j = 0; j < u.size(); j++) {
			u[j].source = minVex.destination;
			FlightOptions list = matrix[u[j].source][u[j].destination];
			if (list.size > 0) {
				Flight *iter = list.header;
				while (iter != nullptr) {
					if (iter->depatureTime > minVex.arrivalTime && iter->arrivalTime - minVex.arrivalTime + minVex.duration < u[j].duration ) {
						u[j].departureTime = iter->depatureTime;
						u[j].arrivalTime = iter->arrivalTime;
						u[j].duration = iter->arrivalTime - minVex.arrivalTime + minVex.duration;
					}
					iter = iter->next;
				}
			}
			else {
				u[j].departureTime = 0;
				u[j].arrivalTime = 0;
				u[j].duration = BIG_INT;
			}
		}
	}
	printOptimalRoute(s);
	u.clear();
	s.clear();
}

void FlightMatrix::print()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++) {
			cout << "(" << i << ", " << j << ")" << endl;
			cout << matrix[i][j].toString() << endl;
		}
	}
}

FlightGraphVertex::FlightGraphVertex()
{
}

FlightGraphVertex::FlightGraphVertex(FlightGraphVertex* fgv)
{
	departureTime = fgv->departureTime;
	arrivalTime = fgv->arrivalTime;
	duration = fgv->duration;
	source = fgv->source;
	destination = fgv->destination;
}

FlightGraphVertex::FlightGraphVertex(int source, int destination, int departureTime, int arrivalTime, int duration)
{
	FlightGraphVertex::source = source;
	FlightGraphVertex::destination = destination;
	FlightGraphVertex::duration = duration;
	FlightGraphVertex::departureTime = departureTime;
	FlightGraphVertex::arrivalTime = arrivalTime;
}

void FlightGraphVertex::setAll(FlightGraphVertex fgv)
{
	departureTime = fgv.departureTime;
	arrivalTime = fgv.arrivalTime;
	duration = fgv.duration;
	source = fgv.source;
	destination = fgv.destination;
}

void FlightGraphVertex::setAll(int source, int destination, int departureTime, int arrivalTime, int duration)
{
	FlightGraphVertex::source = source;
	FlightGraphVertex::destination = destination;
	FlightGraphVertex::duration = duration;
	FlightGraphVertex::departureTime = departureTime;
	FlightGraphVertex::arrivalTime = arrivalTime;
}

std::string FlightGraphVertex::toString()
{
	return "fly " + to_string(source) + " to " + to_string(destination) + ", " + to_string(departureTime) + "-" + to_string(arrivalTime);
}

void printOptimalRoute(vector<FlightGraphVertex> v)
{
	cout << "Optimal route from " << v[0].destination << " to " << v[v.size()-1].destination << endl;
	for (int i = 1; i < v.size(); i++) {
		cout << v[i].toString() << endl;
	}
	cout << "arrive at " << v[v.size()-1].destination << " at time " << v[v.size()-1].arrivalTime << endl;
}
