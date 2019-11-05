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
	����һ�����飬��offset�㵽��index�����·��
*/
void dijkstra(AdjacencyGraph *adjacencyGraph, int offset);
