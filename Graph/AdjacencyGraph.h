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

AdjacencyGraph *initAdjacencyGraphFromMatrix(SquareMatrix *squareMatrix);

void createNewArc(int v1, int v2, int weight, AdjacencyGraph *adjacencyGraph);

/*
	传入的vertex数组至少两个才行
	每次输入v1, v2, weight组成一个弧, 输入一个-1结束输入
*/
void createAdjacencyGraph(AdjacencyGraph *adjacencyGraph);

/* 
sample
0:(a)->1,3->2,4->3,2->null
1:(b)->0,3->3,3->null
2:(c)->0,4->3,5->null
3:(d)->0,2->1,3->2,5->4,1->null
4:(e)->3,1->null
*/
void printAdjacencyGraph(AdjacencyGraph *adjacencyGraph);

SquareMatrix *generateGraphMatrix(AdjacencyGraph *adjacencyGraph, SquareMatrix *squareMatrix);

void freeAdjacencyGraph(AdjacencyGraph *adjacencyGraph);

typedef struct _GraphNode
{
	int vexIndex;
	int weight;

} GraphNode;

typedef struct _GraphNodeArray
{
	GraphNode *array;
	int used;
	int length;
} GraphNodeArray;

GraphNode *initGraphNode(int vexIndex, int weight);
GraphNodeArray *initGraphNodeArray(int length);
GraphNodeArray *initGraphNodeArray(int length, int weight, int offset);

void append(GraphNodeArray *array, int vexIndex, int weight);
void removeFirstByVexIndex(GraphNodeArray *array, int vexIndex);

void freeGraphNodeArray(GraphNodeArray *array);
void printGraphNodeArray(GraphNodeArray *array);

/*
	返回一个数组，是offset点到该index的最短路径
*/
GraphNodeArray *dijkstra(SquareMatrix *squareMatrix, int offset);
