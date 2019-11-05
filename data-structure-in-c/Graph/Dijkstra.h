#pragma once

#include "AdjacencyGraph.h"

typedef struct _GraphNode
{
	int vexIndex;
	int weight;
} GraphNode;

typedef struct _GraphNodeArray
{
	GraphNode *head;
	int length;
} GraphNodeArray;

/*
	返回一个数组，是offset点到该index的最短路径
*/
void dijkstra(AdjacencyGraph *adjacencyGraph, int offset);
