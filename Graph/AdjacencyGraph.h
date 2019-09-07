#pragma once

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

/*
	�����vertex����������������
	ÿ������v1, v2, weight���һ����, ����һ��-1�������� 
*/
void createAdjacencyGraph(AdjacencyGraph *adjacencyGraph);

void createAdjacencyGraphFromMatrix(AdjacencyGraph *adjacencyGraph, SquareMatrix *squareMatrix);

void printAdjacencyGraph(AdjacencyGraph *adjacencyGraph);

void freeAdjacencyGraph(AdjacencyGraph *adjacencyGraph);
