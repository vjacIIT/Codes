#include<stdio.h>
#include<stdlib.h>

typedef struct Graph
{
	int Ver, Edg;
	int **Adj;
}Graph;

Graph* createGraph(int V, int E)
{
	Graph *gr;
	gr = (Graph*)malloc(sizeof(Graph));
	gr->Ver = V;
	gr->Edg = E;
	gr->Adj = (int**)malloc(V*sizeof(int*));
	
	for(int i=0; i<V; i++)
		(gr->Adj)[i]=(int*)malloc(V*sizeof(int));
	
	for(int i=0; i<V; i++)
		for(int j=0; j<V; j++)
			(gr->Adj)[i][j]=0;
	
	return gr; 
}

int main()
{
	int E, V, val1, val2;
	Graph *graph;
	printf("Enter no of Vertices and Edges in the graph: ");
	scanf("%d%d", &V, &E);
	graph = createGraph(V, E);
	printf("Enter the edges: ");
	for(int i=0; i<E; i++)
	{	
		scanf("%d,%d", &val1, &val2);			// assuming numbering starts from 1
		(graph->Adj)[val1-1][val2-1]=1;			// for unidirectional
		(graph->Adj)[val2-1][val1-1]=1;		 	// for bidirectional 
	}
	
	for(int i=0; i<V; i++)
	{
		for(int j=0; j<V; j++)
			printf("%d", (graph->Adj)[i][j]);
		printf("\n");
	}	
	
	for(int i=0; i<V; i++)					// this is to free up the allocated memory.
		free((graph->Adj)[i]);
	free(graph->Adj);
	free(graph);
	
	return 0; 
}
