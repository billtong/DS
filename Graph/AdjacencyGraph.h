#pragma once
#include "SquareMatrix.h"
// define the Arcnode(arc or node)
typedef struct _Arcnode
{
	int adjvex;
	int weight;
	struct _Arcnode *nextArc;
	//	char *info;	//optional, information about this arc or node
} Arcnode;

// define the vertex
typedef struct _Vexnode
{
	Arcnode *firstArc;
	char vexData;
} Vexnode;

//define the adjacency graph
typedef struct _AdjacencyGraph
{
	Vexnode *graph;
	int length;
} AdjacencyGraph;

Arcnode *initArcnode(int adjvex, int weight, Arcnode *nextArc);

Vexnode *initVexnode(Arcnode *firstArc, char vexData);

AdjacencyGraph *initAdjacencyGraph(int length);

AdjacencyGraph *initAdjacencyGraphFromMatrix(SquareMatrix squareMatrix);

void createNewArc(int v1, int v2, int weight, AdjacencyGraph *adjacencyGraph);

/*
	�����vertex����������������
	ÿ������v1, v2, weight���һ����, ����һ��-1��������
*/
void createAdjacencyGraph(AdjacencyGraph *adjacencyGraph);

void printAdjacencyGraph(AdjacencyGraph *adjacencyGraph);

void freeAdjacencyGraph(AdjacencyGraph *adjacencyGraph);
