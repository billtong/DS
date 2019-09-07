#include "pch.h"
using namespace std;

Arcnode *initArcnode(int adjvex, int weight, Arcnode *nextArc)
{
	Arcnode *arcnode = (Arcnode *)malloc(sizeof(Arcnode));
	arcnode->adjvex = adjvex;
	arcnode->weight = weight;
	arcnode->nextArc = nextArc;
	return arcnode;
}

Vexnode *initVexnode(Arcnode *firstArc, char vexData)
{
	Vexnode *vexnode = (Vexnode *)malloc(sizeof(Vexnode));
	vexnode->firstArc = firstArc;
	vexnode->vexData = vexData;
	return vexnode;
}

AdjacencyGraph *initAdjacencyGraph(int length)
{
	AdjacencyGraph *adjacencyGraph = (AdjacencyGraph *)malloc(sizeof(AdjacencyGraph));
	adjacencyGraph->graph = (Vexnode *)malloc(sizeof(Vexnode)*length);
	for (int i = 0; i < length; i++) {
		adjacencyGraph->graph[i].vexData = 'a' + i;
		adjacencyGraph->graph[i].firstArc = NULL;
	}
	adjacencyGraph->length = length;
	return adjacencyGraph;
}

void createAdjacencyGraph(AdjacencyGraph *adjacencyGraph)
{
	if (adjacencyGraph->length <= 1) {
		cout << "ERROR: the length of this adjacent linked list is 0" << endl;
	}
	else {
		while (true) {
			int v1 = 0, v2 = 0, weight=0;
			Arcnode *p, *q;
			cout << "please input the vertex's arcs and weight, press '-1' to stop:" << endl;
			cin >> v1;
			if (v1 == -1 ) {
				cout << "vertiex's arcs input stopped" << endl;
				break;
			}
			cin >> v2 >> weight;
			if (v1 < 0 || v2 < 0 || v1 >= adjacencyGraph->length || v2 >= adjacencyGraph->length || v1 == v2) {
				cout << "ERROR: the index you have inputed out of bound" << endl;
				continue;
			}
			if (weight <= 0) {
				cout << "ERROR: the value of weight cannot be negative" << endl;
				continue;
			}
			Arcnode *node = initArcnode(v2, weight, NULL);
			if (adjacencyGraph->graph[v1].firstArc == NULL) {
				adjacencyGraph->graph[v1].firstArc = node;
			}
			else {
				Arcnode *ite = adjacencyGraph->graph[v1].firstArc;
				while (ite->nextArc != NULL)
				{
					ite = ite->nextArc;
				}
				ite->nextArc = node;
			}
			cout << v1 << "-" << v2 << "'s arc created, weight is "<< weight << endl;
		}
	}
}

void createAdjacencyGraphFromMatrix(AdjacencyGraph *adjacencyGraph, SquareMatrix *squareMatrix)
{
	
}

void printAdjacencyGraph(AdjacencyGraph *adjacencyGraph) 
{
	if (adjacencyGraph->length == 0) {
		cout << "this is an empty adjacency graph" << endl;
	}
	else {
		for (int i = 0; i<adjacencyGraph->length; i++) {
			cout << i << ":(" << adjacencyGraph->graph[i].vexData << ")->";
			Arcnode *ite = adjacencyGraph->graph[i].firstArc;
			while (ite != NULL) {
				cout << ite->adjvex<< "," << ite->weight << "->";
				ite = ite->nextArc;
			}
			cout << "null" << endl;
		}
	}
}

void freeAdjacencyGraph(AdjacencyGraph *adjacencyGraph) 
{
	for (int i = 0; i < adjacencyGraph->length; i++) {
		Arcnode *ite = adjacencyGraph->graph[i].firstArc;
		while (ite != NULL) {
			Arcnode *temp = ite->nextArc;
			free(ite);
			ite = temp;
		}
		cout << "done: free the the memory of the vertex #" << i << endl;
	}
	free(adjacencyGraph->graph);
	free(adjacencyGraph);
	cout << "done: free the memory of this adjacency graph";
}