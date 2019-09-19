#pragma once

typedef struct _Flight
{
	int depatureTime;
	int arrivalTime;
	int duration;
	_Flight *next;
} Flight;

Flight *initFlight(int, int);
void printFlight(Flight *);
std::string getStringOf(Flight *flight);
void freeFlight(Flight *);
