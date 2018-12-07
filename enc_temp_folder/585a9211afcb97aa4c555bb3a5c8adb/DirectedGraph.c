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

	graphQueue *gq = initGraphQueue();
	enqueueGraph(gq, myGraph->graphnodes[startIndex]);
	state[startIndex] = waiting;
	
	//vertice出栈
	//这里有一个奇怪的问题：currentIndex必须紧挨着currV获取，不然就失效了
	//因为return里用&会返回特殊值，不最好不要用
	//vertice的next全部进展
	while (gq->count > 0) {

		graphnode *currV = dequeueGraph(gq);

		state[currV->index] = visited;
		printf("%d->", currV->index);

		int currIndex = currV->index;
		
		for (int i = 0, isEmpty = 1; i < myGraph->num - 1 && isEmpty == 1; i++) {
			if (myGraph->graphnodes[currIndex].next[i] == NULL) {
				isEmpty = 0;
			}
			else {
				int index = myGraph->graphnodes[currIndex].next[i]->index;
				if (state[index] == inital) {
					graphnode input = *(myGraph->graphnodes[currIndex].next[i]);
					enqueueGraph(gq, input);
					state[input.index] = waiting;
				}
			}
			
		}
	}

	printf("\n");
}

void DepthFirstTraversalDirectedGraph(graph * myGraph, int startIndex)
{
	int *state = (int *)malloc(sizeof(int)*myGraph->num);
	for (int i = 0; i < myGraph->num; i++)
	{
		state[i] = inital;
	}

	printf("dft:\n");
	dft(myGraph, startIndex, state);
	printf("\n");
}


void dft(graph * myGraph, int currIndex, int *state)
{
	printf("%d->", currIndex);
	state[currIndex] = visited;

	for (int i = 0; i < myGraph->num - 1; i++) {
		if (myGraph->graphnodes[currIndex].next[i] == NULL) {
			break;
		}
		graphnode *nextNode = myGraph->graphnodes[currIndex].next[i];
		if (state[nextNode->index] != visited) {
			dft(myGraph, nextNode->index, state);
		}

	}
	
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

	gq->head = (struct QueueNode *)malloc(sizeof(struct QueueNode));
	gq->head->next = NULL;
	gq->count = 0;
	return gq;
}

void enqueueGraph(graphQueue * gq, graphnode value)
{
	if (gq == NULL) {
		printf("the enqueuegraph is empty\n");
		return;
	}

	//if it is the first time
	if (gq->count == 0) {
		gq->head = (struct QueueNode *)malloc(sizeof(struct QueueNode));
		gq->head->value = value;
		gq->head->next = NULL;
		gq->count++;
		return;
	}

	struct QueueNode* oriHead = gq->head;
	gq->head = (struct QueueNode *)malloc(sizeof(struct QueueNode));
	gq->head->value = value;
	gq->head->next = oriHead;

	gq->count++;

	
}

graphnode *dequeueGraph(graphQueue * gq)
{
	if (gq == NULL || gq->head == NULL) {
		printf("the enqueuegraph is already empty\n");
		return NULL;
	}
	struct QueueNode* ptr = gq->head, *prevPtr = NULL;

	if (gq->count == 1) {
		gq->head = NULL;
		gq->count = 0;
		return  &(ptr->value);
	}

	
	while (ptr->next != NULL)
	{
		prevPtr = ptr;
		ptr = ptr->next;
	}

	graphnode *rslt = &(ptr->value);
	prevPtr->next = ptr->next;
	gq->count--;

	return rslt;
}
