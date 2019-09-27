/*
	Author: Bill Tong
*/
#include"CSquareMatrix.h"
#include"CDijkstra.h"

using CDIJKSTRA::CDijkstra;

int main(int argc, char *argv[])
{
	CSquareMatrix iSquareMatrix(DIJKSTRA_DATA_1600);
	CDijkstra iDijkstra(iSquareMatrix, 0);
	iDijkstra.printResult();
	system("pause");
	return 0;
}