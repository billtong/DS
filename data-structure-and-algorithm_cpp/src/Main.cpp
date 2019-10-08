/*
	Author: Bill Tong
*/
#include <random>
#include"../include/CDijkstra.h"
#include "../include/CSort.h"
#include "../include/CSearch.h"
#include "../include/CSubsetSum.h"

#define DIJKSTRA_TEST 0
#define SEARCH_TEST 0
#define SORT_TEST 0
#define SUBSET_SUM 1

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
    srand((unsigned)clock());
	int arr[100];
	int n = 40;
	for(int i=0; i<n; i++)
    {
	    arr[i] = rand() % 100;
    }
	int k = rand() % 100;
	vector<int> v(arr, arr+n);
    CSubsetSum::hs_subset_sum(v, k);
	CSubsetSum::bfi_subset_sum(v, k);
#endif // SUBSET_SUM
}