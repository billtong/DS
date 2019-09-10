#include "pch.h"
#define DIJKSTRA 1
#define MATRIX_SIZE 5

using namespace std;

int main()
{
	ifstream file;
	file.open("./samples/Dijkstra_Data_1600.txt");
	if (!file)
	{
		cout << "ERROR: cannot open file" << endl;
		exit(1);
	}
	int length;
	file >> length;
	int **matrixPtr = (int **)malloc(sizeof(int *) * length);
	for (int i = 0; i < length; i++)
	{
		matrixPtr[i] = (int *)malloc(sizeof(int) * length);
		for (int j = 0; j < length; j++) {
			file >> matrixPtr[i][j];
		}
	}
	SquareMatrix *mat = initSquareMatrix(length, matrixPtr);
	//printSquareMatrix(mat);

	#if DIJKSTRA
	GraphNodeArray *array = dijkstra(mat, 0);
	freeSquareMatrix(mat);
	printGraphNodeArray(array);
	freeGraphNodeArray(array);
	#endif // ADJACENCY_GRAPH

	system("pause");
	return 0;
}

/*
int matrix[MATRIX_SIZE][MATRIX_SIZE] = {
		{0, 3, 4, 2, 0},
		{3, 0, 0, 3, 0},
		{4, 0, 0, 5, 0},
		{2, 3, 5, 0, 1},
		{0, 0, 0 ,1, 0}
	};
	int **matrixPtr = (int **)malloc(sizeof(int *) * MATRIX_SIZE);
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		matrixPtr[i] = (int *)malloc(sizeof(int) * MATRIX_SIZE);
		for (int j = 0; j < MATRIX_SIZE; j++) {
			matrixPtr[i][j] = matrix[i][j];
		}
	}
*/