/*
	Author: Bill Tong
*/

#include"../include/CDijkstra.h"
#include "../include/CSearch.h"
#include "../include/CSort.hpp"
#include"../include/CSubsetSum.h"
#define DIJKSTRA_TEST 0
#define SEARCH_TEST 0
#define SORT_TEST 0
#define SUBSET_SUM_PART_1 0
#define SUBSET_SUM_PART_2 1

int main(int argc, char *argv[]) {
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
#if SUBSET_SUM_PART_1
    // part one implement and test.
    int a[8] = {3, 5, 3, 9, 18, 4, 5, 6};
    vector<int> arr(a, a + 8);
    int k = 28;
    CSubsetSum::bfi_subset_sum(arr, k);
    CSubsetSum::hs_subset_sum(arr, k);
    /* console output
     * start bfi subset sum function
     * sum:28
     * elements:3   3   18  4
     * stop bfi subset sum function
     * start hs subset sum function
     * sum:28
     * elements:18  4   6
     * stop bfi subset sum function
     */
#endif
#if SUBSET_SUM_PART_2
    srand((unsigned)clock());
    for (int n = 4; n <= 15; n++)   // set sizes
    {
        int totalCountSizeLevel_bfi = 0, totalCountSizeLevel_hs = 0;
        for(int i = 1; i <= 20; i++)    // number of tests
        {
            vector<int> test(n);
            int j=0;
            while(j<n)
            {
                test.push_back(rand() % 50);
                j++;
            }
            int totalCount_bfi = 0, totalCount_hs = 0, tempCount_hs, tempCount_bfi, k;
            for(j=0; j<10; j++)
            {
                k = rand() % 100;
                CSubsetSum::bfi_subset_sum_opt(test, k, tempCount_bfi);
                CSubsetSum::hs_subset_sum_opt(test, k, tempCount_hs);
                totalCount_bfi += tempCount_bfi;
                totalCount_hs += tempCount_hs;
            }
            totalCountSizeLevel_bfi += totalCount_bfi;
            totalCountSizeLevel_hs += totalCount_hs;
            //cout << "average value for test #" << i << "size@" << n << ": " << totalCount / 10 << endl;
        }
        cout << "average value for size @" << n << ": " << totalCountSizeLevel_bfi / (200) << endl;
        cout << "average value for size @" << n << ": " << totalCountSizeLevel_hs / (200) << endl;
    }
/*
    srand((unsigned)clock());
	int arr[100];
	int n = 20;
	for(int i=0; i<n; i++)
    {
	    arr[i] = rand() % 100;
    }
	int k = rand() % 1000;
	vector<int> v(arr, arr+n);
    CSubsetSum::hs_subset_sum(v, k);
	CSubsetSum::bfi_subset_sum(v, k);
*/
#endif
}