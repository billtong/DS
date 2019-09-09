#include "pch.h"
#define INFINITY 0
#define BIG_NUMBER  999999

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

GraphNodeArray *initGraphNodeArray(int length, int weight) {
	GraphNodeArray *graphArray = initGraphNodeArray(length);
	for (int i = 0; i < length; i++) {
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

GraphNodeArray *dijkstra(AdjacencyGraph *adjacencyGraph, int offset) {
	GraphNodeArray *s = initGraphNodeArray(adjacencyGraph->length);									//s是已经计算出的最短路径的集合
	GraphNodeArray *u = initGraphNodeArray(adjacencyGraph->length, INFINITY);	//u是未计算出的最短路径的集合
	SquareMatrix *squareMatrix = generateGraphMatrix(adjacencyGraph);

	append(s, offset, 0);
	removeFirstByVexIndex(u, offset);
	while (u->used > 0) {
		int vexIndex, minWeight = BIG_NUMBER;
		for (int i = 0; i < s->used; i++) {
			int v1 = s->array[i].vexIndex;
			int weight = s->array[i].weight;
			for (int j = 0; j < u->used; j++) {
				int v2 = u->array[j].vexIndex;
				if (squareMatrix->matrix[v1][v2] != INFINITY) {
					int path = squareMatrix->matrix[v1][v2] + weight;
					if (minWeight > path) {
						minWeight = path;
						vexIndex = v2;
					}
				}
				//cout << v1 << "-" << v2 << "-" << "vexIndex: " << vexIndex << ",minWeight: " << minWeight << endl;
			}
		
		}
		append(s, vexIndex, minWeight);
		minWeight = BIG_NUMBER;
		removeFirstByVexIndex(u, vexIndex);
		//printGraphNodeArray(s);
		//printGraphNodeArray(u);
	}
	//freeSquareMatrix(squareMatrix);
	freeGraphNodeArray(u);
	return s;
}