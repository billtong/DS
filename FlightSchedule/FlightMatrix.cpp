#include<iostream>
#include "FlightMatrix.h"

using std::cout;
using std::endl;

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
