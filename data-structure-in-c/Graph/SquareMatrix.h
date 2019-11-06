#pragma once

typedef struct _SquareMatrix
{
	int length;
	int** matrix;		//´æ¾²Ì¬¶þÎ¬Êý×é
} SquareMatrix;

SquareMatrix* initSquareMatrix(int length, int value);

SquareMatrix* initSquareMatrix(int length, int** matrix);

void printSquareMatrix(SquareMatrix* squareMatrix);

void freeSquareMatrix(SquareMatrix* squareMatrix);
