#include "pch.h"

SquareMatrix *initSquareMatrix(int length, int value)
{
	SquareMatrix *squareMatrix = (SquareMatrix *)malloc(sizeof(SquareMatrix));
	squareMatrix->length = length;
	int **matrix = (int **)malloc(sizeof(int) * length);
	cout << "new square matrix ptr" << matrix << endl;
	for (int i = 0; i < length; i++) {
		matrix[i] = (int *)malloc(sizeof(int) *length);
		cout << "new square matrix #"<< i <<" ptr" << matrix[i] << endl;
		memset(matrix[i], value, sizeof(int)*length);
	}
	squareMatrix->matrix = matrix;
	return squareMatrix;
}

SquareMatrix *initSquareMatrix(int length, int **matrix)
{
	SquareMatrix *squareMatrix = (SquareMatrix *)malloc(sizeof(SquareMatrix));
	squareMatrix->length = length;
	squareMatrix->matrix = matrix;
	return squareMatrix;
}

void printSquareMatrix(SquareMatrix *squareMatrix)
{
	for (int i = 0; i < squareMatrix->length; i++)
	{
		for (int j = 0; j < squareMatrix->length; j++) 
		{
			cout << squareMatrix->matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void freeSquareMatrix(SquareMatrix *squareMatrix)
{
	for (int i = 0; i < squareMatrix->length; i++) {
		cout << "free" << squareMatrix->matrix[i] << endl;
		free((int *)squareMatrix->matrix[i]);
	}
	cout << "free" << squareMatrix->matrix << endl;
	free((int *)squareMatrix->matrix);
	free(squareMatrix);
	cout << "free the memory of square matrix" << endl;
}
