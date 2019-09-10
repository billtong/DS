#include "pch.h"
#define CANNOT_ACCESS_NUM 0
#define INFINITY_VALUE  100000

GraphNode *initGraphNode(int vexIndex, int weight) {
	GraphNode *node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vexIndex = vexIndex;
	node->weight = weight;
	return node;
}

GraphNodeArray *initGraphNodeArray(int length) {
	GraphNodeArray *graphArray = (GraphNodeArray *)malloc(sizeof(GraphNodeArray));
	graphArray->array = (GraphNode *)malloc(sizeof(GraphNode) * length);
	graphArray->length = length;
	graphArray->used = 0;
	for (int i = 0; i < graphArray->length; i++) {
		graphArray->array[i] = *initGraphNode(-1, -1);
	}
	return graphArray;
}

GraphNodeArray *initGraphNodeArray(int length, int weight, int offset) {
	GraphNodeArray *graphArray = initGraphNodeArray(length);
	for (int i = 0; i < length; i++) {
		if (i == offset)
			append(graphArray, i, 0);
		else 
			append(graphArray, i, weight);
	}
	return graphArray;
}

void append(GraphNodeArray *graphArray, int vexIndex, int weight) {
	GraphNode *node = initGraphNode(vexIndex, weight);
	graphArray->array[graphArray->used] = *node;
	graphArray->used++;
}

void removeFirstByVexIndex(GraphNodeArray *array, int vexIndex) {
	for (int i = 0; i < array->used; i++) {
		if (vexIndex == array->array[i].vexIndex)
		{
			for (; i < array->used; i++) {
				array->array[i] = array->array[i + 1];
			}
			array->used--;
			array->array[array->used] = *initGraphNode(-1, -1);
			break;
		}
	}
}

void freeGraphNodeArray(GraphNodeArray *graphArray) {
	free(graphArray->array);
	free(graphArray);
}

void printGraphNodeArray(GraphNodeArray *graphArray) {
	for (int i = 0; i < graphArray->length; i++)
		cout << graphArray->array[i].vexIndex << "(" << graphArray->array[i].weight << ") ";
	cout << endl;
}

GraphNodeArray *dijkstra(SquareMatrix *squareMatrix, int offset) {
	GraphNodeArray *s = initGraphNodeArray(squareMatrix->length);				//s是已经计算出的最短路径的集合
	GraphNodeArray *u = initGraphNodeArray(squareMatrix->length, INFINITY_VALUE, offset);	//u是未计算出的最短路径的集合
	while (u->used > 0) {
		int minWeight = u->array[0].weight;
		int v1 = u->array[0].vexIndex;
		for (int i = 0; i < u->used; i++) {
			if (minWeight > u->array[i].weight)
			{
				minWeight = u->array[i].weight;
				v1 = u->array[i].vexIndex;
			}
		}
		append(s, v1, minWeight);
		removeFirstByVexIndex(u, v1);
		for (int j = 0; j < u->used; j++) {
			int v2 = u->array[j].vexIndex;
			int currWeight = squareMatrix->matrix[v1][v2] + minWeight;
			if (squareMatrix->matrix[v1][v2] != CANNOT_ACCESS_NUM && squareMatrix->matrix[v1][v2] + minWeight < u->array[j].weight)
			{
				u->array[j].weight = squareMatrix->matrix[v1][v2] + minWeight;
			}
		}
		printGraphNodeArray(s);
		printGraphNodeArray(u);
	}
	freeGraphNodeArray(u);
	return s;
}