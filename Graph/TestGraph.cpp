#include "pch.h"
#define ADJACENCY_GRAPH 1
#define MATRIX_SIZE 5
#define INFINITY 0
using namespace std;

int main()
{
	int matrix[MATRIX_SIZE][MATRIX_SIZE] = {
		{INFINITY, 3, 4, 2, INFINITY},
		{3, INFINITY, INFINITY, 3, INFINITY},
		{4, INFINITY, INFINITY, 5, INFINITY},
		{2, 3, 5, INFINITY, 1},
		{INFINITY, INFINITY, INFINITY ,1, INFINITY}
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
	printSquareMatrix(mat);
	#if ADJACENCY_GRAPH
	AdjacencyGraph *graph = initAdjacencyGraphFromMatrix(mat);
	freeSquareMatrix(mat);
	printAdjacencyGraph(graph);
	GraphNodeArray *array = dijkstra(graph, 0);
	printGraphNodeArray(array);
	freeGraphNodeArray(array);
	freeAdjacencyGraph(graph);
	#endif // ADJACENCY_GRAPH
	system("pause");
	return 0;
}
