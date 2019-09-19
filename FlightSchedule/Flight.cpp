#include<iostream>
#include "Flight.h"

using std::cout;
using std::endl;

Flight *initFlight(int depatureTime, int arrivalTime)
{
	Flight *flight = (Flight *)malloc(sizeof(Flight));
	flight->depatureTime = depatureTime;
	flight->arrivalTime = arrivalTime;
	flight->next = nullptr;
	return flight;
}
void printFlight(Flight *flight)
{
	cout << "leave:" << flight->depatureTime << "arrive:" << flight->arrivalTime << endl;
}

void freeFlight(Flight * flight)
{
	free(flight);
	flight = nullptr;
	cout << "delete the flight" << endl;
}

