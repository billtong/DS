/*
	Author: Bill Tong
	Dijstra, Search
*/
#include"CDijkstra.h"
#include <time.h>
#include"CSearch.h"
#define DIJKSTRA_TEST 0
#define SEARCH_TEST 1

void execSearchFuncWithClock(int (*func)(int *,int, int), int *a, int size, int x) {
	double start, finish;
	start = clock();
	cout << (*func)(a, size, x) << endl;
	finish = clock();
	cout << (finish - start) << " msec to complete." << endl;
}

int main(int argc, char *argv[])
{
#if DIJKSTRA_TEST
	CSquareMatrix iSquareMatrix(DIJKSTRA_DATA_1600);
	CDijkstra iDijkstra(iSquareMatrix, 0);
	iDijkstra.printResult();
#endif // DIJKSTRA_TEST
#if SEARCH_TEST
	CSearch *csearch = new CSearch;
	int a[10] = { 1, 3, 6, 8, 10, 12, 32, 33, 34, 40 };
	execSearchFuncWithClock(csearch->binarySearch, a, 10, 32);
	execSearchFuncWithClock(csearch->trinarySearch, a, 10, 32);
#endif // SEARCH_TEST
}