
#ifndef SORTS_H


/*
从数组中选出最小的数放在第一个
再选出第二小的放在第二个
。。。
一直选到倒数第二个
10 24 5 32 1 84 19
1 24 5 32 10 84 19
1 5 24 32 10 84 19
1 5 10 32 24 84 19
1 5 10 19 24 84 32
1 5 10 19 24 84 32
1 5 10 19 24 32 84
*/
void selectionSorts(int *arr, int size);
void insertionSorts(int* arr, int size);

#endif // !SORTS_H

