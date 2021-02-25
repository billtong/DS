#include "SelectionSort.h"
#include "Tools.h"

/*
Selection Sort
find the smallest element and put it at the 1st place
find the second smallest element and put it at the 2nd place
continue the procedure until the second last one
Example, element inside the brace is the "smallest element" each turn
start：10 24 5 32 1 84 19
#1: (1) 24 5 32 10 84 19
#2: 1 (5) 24 32 10 84 19
#3: 1 5 (10) 32 24 84 19
#4: 1 5 10 (19) 24 84 32
#5: 1 5 10 19 (24) 84 32
end: 1 5 10 19 24 (32) 84
*/
void SelectionSort::exec(int *arr, const int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int selectIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[selectIndex] > arr[j])
				selectIndex = j;
		}
		Tools::swap(arr[i], arr[selectIndex]);
	}
}
