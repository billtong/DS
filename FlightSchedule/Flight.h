#pragma once

typedef struct _Flight
{
	int depatureTime;
	int arrivalTime;
	_Flight *next;
} Flight;

Flight *initFlight(int, int);
void printFlight(Flight *);
void freeFlight(Flight *);