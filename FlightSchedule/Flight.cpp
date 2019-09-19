#include<iostream>
#include<string>
#include "Flight.h"

using std::cout;
using std::endl;
using std::to_string;

Flight *initFlight(int depatureTime, int arrivalTime)
{
	Flight *flight = (Flight *)malloc(sizeof(Flight));
	flight->depatureTime = depatureTime;
	flight->arrivalTime = arrivalTime;
	flight->duration = arrivalTime - depatureTime;
	flight->next = nullptr;
	return flight;
}
void printFlight(Flight *flight)
{
	cout << "leave:" << flight->depatureTime << ",arrive:" << flight->arrivalTime << ",duration:" << flight->duration << endl;
}

std::string getStringOf(Flight *flight)
{
	return "leave:" + to_string(flight->depatureTime) + ",arrive:" + to_string(flight->arrivalTime) + ",duration:" + to_string(flight->duration) + "\n";
}

void freeFlight(Flight * flight)
{
	free(flight);
	flight = nullptr;
	//cout << "delete the flight" << endl;
}

