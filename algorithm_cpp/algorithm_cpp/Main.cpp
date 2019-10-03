/*
	Author: Bill Tong
	Dijstra, Search
*/
#include"CDijkstra.h"
#include"CSearch.h"
#include"CSubsetSum.h"

#define DIJKSTRA_TEST 0
#define SEARCH_TEST 0
#define SUBSET_SUM 1

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
	csearch->execSearchFuncWithClock(csearch->binarySearch, a, 10, 40);
	csearch->execSearchFuncWithClock(csearch->trinarySearch, a, 10, 40);
#endif // SEARCH_TEST
#if SUBSET_SUM
	int s[8] = { 3, 5, 3, 9, 18, 4, 5, 6 };
	CSubsetSum::bfi_subset_sum(s, 8, 6);
#endif // SUBSET_SUM

}