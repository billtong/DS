#pragma once
#include<string>
#include"Flight.h"

using std::string;

class FlightOptions
{
public:
	Flight *header;
	int size;

	FlightOptions();
	~FlightOptions();
	void append(int, int);
	string toString();
};

