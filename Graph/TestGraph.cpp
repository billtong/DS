#include "pch.h"
#define ADJACENCY_GRAPH 1
#define MATRIX_SIZE 5
using namespace std;

int main()
{
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
	SquareMatrix *mat = initSquareMatrix(MATRIX_SIZE, matrixPtr);

	#if ADJACENCY_GRAPH
	//AdjacencyGraph *graph = initAdjacencyGraph(5);
	//printAdjacencyGraph(graph);
	//createAdjacencyGraph(graph);

	AdjacencyGraph *graph = initAdjacencyGraphFromMatrix(*mat);
	printAdjacencyGraph(graph);
	freeAdjacencyGraph(graph);
	#endif // ADJACENCY_GRAPH

	system("pause");
	return 0;
}
