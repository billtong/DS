#pragma once

typedef struct _SquareMatrix
{
	int length;
	int **matrix;		//�澲̬��ά����
} SquareMatrix;

SquareMatrix *initSquareMatrix(int length, int **matrix);

void freeSquareMatrix(SquareMatrix *squareMatrix);
