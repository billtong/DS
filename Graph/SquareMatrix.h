#pragma once

typedef struct _SquareMatrix
{
	int length;
	void *matrix;		//�澲̬��ά����
} SquareMatrix;

/*
�����⣿ :void ���Դ����λ��̬����������int�Ͳ���
*/
SquareMatrix *initSquareMatrix(int length, void *matrix);

void freeSquareMatrix(SquareMatrix *squareMatrix);

