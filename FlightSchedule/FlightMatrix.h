#pragma once

#include<vector>
#include"FlightOptions.h"

using std::vector;

class FlightGraphVertex
{
public:	
	int source;
	int destination;
	int departureTime;
	int arrivalTime;
	int duration;
	FlightGraphVertex();
	FlightGraphVertex(FlightGraphVertex *);
	FlightGraphVertex(int, int, int, int, int);
	void setAll(FlightGraphVertex);
	void setAll(int, int, int, int, int);
	std::string toString();
};

class FlightMatrix
{
public:
	FlightOptions **matrix;
	int length;

	//1st param length, 2st param initial value
	FlightMatrix(int, int);
	~FlightMatrix();
	void dijkstra(int start, int end);
	void print();
};

void printOptimalRoute(vector<FlightGraphVertex> v);