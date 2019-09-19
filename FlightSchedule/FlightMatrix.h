#pragma once

#include"FlightOptions.h"

class FlightMatrix
{
public:
	FlightOptions **matrix;
	int length;

	//1st param length, 2st param initial value
	FlightMatrix(int, int);
	~FlightMatrix();
	void print();
};

