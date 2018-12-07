#include "ZHeader.h"

graph * createGraph(edge myEdges[],int edgesNum, int verticesNum)
{
	graph *myGraph = (graph *)malloc(sizeof(graph));

	myGraph->graphnodes = (graphnode *)malloc(sizeof(graphnode)*verticesNum);
	myGraph->num = verticesNum;

	for (int i = 0; i < verticesNum; i++) {
		myGraph->graphnodes[i].index = i;
		myGraph->graphnodes[i].next = (graphnode **)malloc(sizeof(graphnode *)*(verticesNum - 1));
		for (int j = 0; j < verticesNum - 1; j++) {
			myGraph->graphnodes[i].next[j] = NULL;
		}
	}

	for (int i = 0; i < edgesNum; i++) {
		int ori = myEdges[i].ori;
		int dest = myEdges[i].dest;

		//find the empty place to add the next vertices
		for (int j = 0; j < verticesNum - 1; j++) {
			if (myGraph->graphnodes[ori].next[j] == NULL) {
				myGraph->graphnodes[ori].next[j] = &(myGraph->graphnodes[dest]);
				break;
			}
		}
	}

	return myGraph;
}



void BreadthFirstTraversalDirectedGraph(graph * myGraph, int startIndex)
{

	int *state = (int *)malloc(sizeof(int)*myGraph->num);
	for (int i = 0; i < myGraph->num; i++)
	{
		state[i] = inital;
	}

	linkedqueue *lq = initLinkedQueue();
	//?need to add specific queue for graphs

}

void printDirectedGraph(graph * myGraph)
{
	if (myGraph == NULL || myGraph->graphnodes== NULL || myGraph->num == 0) {
		printf("empty graph\n");
		return;
	}

	for (int i = 0; i < myGraph->num; i++) {
		printf("vertice :%d ", myGraph->graphnodes[i].index);
		for (int j = 0; j < myGraph->num - 1; j++) {
			if (myGraph->graphnodes[i].next[j] == NULL) {
				break;
			}
			printf("--> %d ", myGraph->graphnodes[i].next[j]->index);
		}
		printf("\n");
	}

}





graphQueue *initGraphQueue()
{
	graphQueue *gq = (graphQueue *)malloc(sizeof(graphQueue));

	gq->graphQueues = (graphnode *)malloc(sizeof(graphnode) * INIT_QUEUE_SIZE);

	//init memory
	for (int i = 0; i < INIT_QUEUE_SIZE; i++) {
		gq->graphQueues[i].index = 0;
		gq->graphQueues[i].next = NULL;
	}

	gq->count = 0;
	return gq;
}
