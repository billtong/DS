#include<iostream>
#include "FlightOptions.h"

using std::cout;
using std::endl;
using std::to_string;

FlightOptions::FlightOptions()
{
	header = nullptr;
	FlightOptions::size = 0;
}

FlightOptions::~FlightOptions()
{
	Flight *ite =header, *temp = header;
	while (ite != nullptr)
	{
		ite = ite->next;
		freeFlight(temp);
		temp = ite;
	}
	size = 0;
}

void FlightOptions::append(int dt, int at)
{
	if (size == 0)
	{
		header = initFlight(dt, at);
	}
	else {
		Flight *ite = header;
		while (ite->next != nullptr)
		{
			ite = ite->next;
		}
		ite->next = initFlight(dt, at);
	}
	size++;
}

std::string FlightOptions::toString()
{
	Flight *ite = header;
	std::string str = "";
	while (ite != nullptr)
	{
		str = str + getStringOf(ite);
		ite = ite->next;
	}
	return str;
}
