/*
	Author: Bill Tong
*/
#include"../include/CDijkstra.h"
#include"../include/CSearch.h"
#include"../include/CSubsetSum.h"
#include "../include/CSort.h"

#define DIJKSTRA_TEST 0
#define SEARCH_TEST 0
#define SORT_TEST 1
#define SUBSET_SUM 0

int main(int argc, char *argv[])
{
#if DIJKSTRA_TEST
	CSquareMatrix iSquareMatrix(DIJKSTRA_DATA_1600);
	CDijkstra iDijkstra(iSquareMatrix, 0);
	iDijkstra.printResult();
#endif // DIJKSTRA_TEST
#if SEARCH_TEST
	CSearch * search = new CSearch;
	int a[10] = { 1, 3, 6, 8, 10, 12, 32, 33, 34, 40 };
	search->execSearchFuncWithClock(search->binarySearch, a, 10, 40);
	search->execSearchFuncWithClock(search->trinarySearch, a, 10, 40);
#endif // SEARCH_TEST
#if SORT_TEST
    vector<int> v;
    srand((unsigned)time(0));
    for(int i=0; i<30; i++)
        v.push_back(rand() % 100);
    CSort<int>::MergeSort(v);
    for(int i : v)
        cout << i << "\t";
    cout << endl;
#endif // SORT_TEST
#if SUBSET_SUM
	int s[8] = { 3, 5, 3, 9, 18, 4, 5, 6 };
	CSubsetSum::bfi_subset_sum(s, 8, 6);
#endif // SUBSET_SUM
}