#pragma once

typedef struct _SquareMatrix
{
	int length;
	int **matrix;		//´æ¾²Ì¬¶þÎ¬Êý×é
} SquareMatrix;

SquareMatrix *initSquareMatrix(int length, int **matrix);

void freeSquareMatrix(SquareMatrix *squareMatrix);
