#pragma once
#include<string>
#include"Flight.h"

class FlightOptions
{
public:
	Flight *header;
	int size;

	FlightOptions();
	~FlightOptions();
	void append(int, int);
	std::string toString();
};

