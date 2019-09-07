#include "pch.h"
using namespace std;

SquareMatrix *initSquareMatrix(int length, void *matrix)
{
	SquareMatrix *squareMatrix = (SquareMatrix *)malloc(sizeof(SquareMatrix));
	squareMatrix->length = length;
	squareMatrix->matrix = matrix;
}

void freeSquareMatrix(SquareMatrix *squareMatrix)
{
	free(squareMatrix->matrix);
	free(squareMatrix);
	cout << "free the memory of square matrix" << endl;
}

/*
SquareMatrix *getSampleSquareMatrix()
{
	const int length = 5;
	int arrays[length][length] = {
		{0, 3, 4, 2, 0}, 
		{3, 0, 0, 3, 0}, 
		{4, 0, 0, 5, 0}, 
		{2, 3, 5, 0, 1}, 
		{0, 0, 0 ,1, 0} 
	};
	return initSquareMatrix(length, arrays);
}
*/