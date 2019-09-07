#pragma once

typedef struct _SquareMatrix
{
	int length;
	void *matrix;		//存静态二维数组
} SquareMatrix;

/*
？问题？ :void 可以传入二位静态常量，但是int就不行
*/
SquareMatrix *initSquareMatrix(int length, void *matrix);

void freeSquareMatrix(SquareMatrix *squareMatrix);

