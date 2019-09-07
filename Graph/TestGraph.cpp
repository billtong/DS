#include "pch.h"
#define ADJACENCY_GRAPH 1

using namespace std;

int main()
{
	#if ADJACENCY_GRAPH
	AdjacencyGraph *graph = initAdjacencyGraph(5);
	printAdjacencyGraph(graph);
	creatAdjacencyGraph(graph);
	printAdjacencyGraph(graph);
	freeAdjacencyGraph(graph);
	#endif // ADJACENCY_GRAPH

	system("pause");
	return 0;
}
