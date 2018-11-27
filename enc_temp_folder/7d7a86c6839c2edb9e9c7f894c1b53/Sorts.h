
#ifndef SORTS_H


/*
从数组中选出最小的数放在第一个
再选出第二小的放在第二个
。。。
一直选到倒数第二个
例子：每次从整个数组中选择（）内的正确元素
start：10 24 5 32 1 84 19
#1：(1) 24 5 32 10 84 19
#2：1 (5) 24 32 10 84 19
#3：1 5 (10) 32 24 84 19
#4：1 5 10 (19) 24 84 32
#5：1 5 10 19 (24) 84 32
end：1 5 10 19 24 (32) 84
*/
void selectionSorts(int *arr, int size);

/*
从第二个数开始将他正确的插在前面区间内的位置中
位置的寻找使用线性搜索，一个个的来O（n）
例子：每次将（）左边的那个数字正确的insert到（）里面去
start：10 24 5 32 1 84 19
#1：(10) 24 5 32 1 84 19
#2：(5 10) 24 32 1 84 19
#3：(5 10 24) 32 1 84 19
#4：(1 5 10 24 32) 84 19
#5：(1 5 10 24 32 84) 19
end：(1 5 10 19 24 32 84
*/
void linearInsertionSorts(int* arr, int size);

/*
原理和Linear的基本相同
只是在选择位置时不再用线性搜索，而是binary search，O(ln（n）)
*/
void binaryInsertionSorts(int *arr, int size);


/*冒泡排序
通过从第一项开始和下一项比较，保证更大的那个能够往后移动一位
最后最大的哪一项就会浮出水面，成为正确的位置
*/
void bubbleSorts(int *arr, int size);

/*
[0]200<->[12]1
1 50 212 23 43 7 1200 50 60 2 5 3 200
[10]1200<->[12]200
1 50 3 23 43 7 5 50 60 2 200 212 1200
[1]50<->[9]2
1 2 3 23 43 7 5 50 60 50 200 212 1200
[8]60<->[9]50
1 2 3 23 43 7 5 50 50 60 200 212 1200
[7]50<->[7]50
1 2 3 23 43 7 5 50 50 60 200 212 1200
[3]23<->[6]5
1 2 3 5 43 7 23 50 50 60 200 212 1200
[5]43<->[6]23
1 2 3 5 7 23 43 50 50 60 200 212 1200
1 2 3 5 7 23 43 50 50 60 200 212 1200
*/
void quickSorts(int *arr, int left, int right);


/*
该函式使用了merge的递归函数，用于简化使用，穿的参数少一点//被main里使用
*/
void mergeSort(int *arr, int n);

/*merge递归
获得middle
然后将函数分为两部分分别进行排序，
最后再整合到一起
*/
void mergeSortRec(int *a, int start, int end, int* b);
/*这个merge时排序的核心
	定义连个变量j和k
	第一步
	j从start开始遍历，k从middle加1开始遍历
	那个小一点就先赋给b数组，并且那个小一些的index往前移动一格
	等j或k中的一个走完全部所在区间
	第二步
	a中（middle的左边区间或者右边区间）剩下的元素还没有遍历的
	统统给按照顺序给赋值到b中
	第三步
	将排序好的b赋值给a
*/
void merge(int *a, int start, int middle, int end, int *b);



void bucketSort(int *a, int size, int bucketSize);

//(0, 10^p)
void radixSort(int *a, int size, int p);

#endif // !SORTS_H

