#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H

#define inital 1
#define waiting 2
#define visited 3

#define INIT_QUEUE_SIZE 10

typedef struct Node {
	int index;
	struct Node **next;
}graphnode;

typedef struct Graph {
	int num;
	graphnode *graphnodes;
}graph;


// first is orign index, the next is desin index

typedef struct Edge {
	int ori;
	int dest;
}edge;

graph *createGraph(edge edges[], int edgesNum, int verticesNum);

void printDirectedGraph(graph *myGraph);

//primeÀ„∑®
//https://blog.csdn.net/zwz2011303359/article/details/63254575



void BreadthFirstTraversalDirectedGraph(graph *myGraph, int startIndex);


//here is implemented a queue for graph
typedef struct VerticeQueue {
	graphnode *graphQueues;
	int count;
}graphQueue;

graphQueue *initGraphQueue();




#endif // !DIRECTEDGRAPH_H
#pragma once

