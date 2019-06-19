#include<stdio.h>
#include<stdlib.h>

long int flag=0;		// stores the number of elements one vertex can reach
long int h =0;	// helper for the actual size of the array

typedef struct node
{
	long int ver;
	struct node *link;
}node;

typedef struct Graph
{
	node **head;
	long int *visited;
	long int *arr;		// to store total no elements which belong to same tree
}graph;

void addNode(graph* gr, long int i, long int ver)
{
	node *head;
	node *nd;
	nd = (node*)malloc(sizeof(node));
	nd->ver = ver;
	head = gr->head[i];
	if(head==NULL)
	{
		gr->head[i]=nd;
		nd->link = NULL;
		return;
	}
	nd->link = head;
	gr->head[i]=nd;
	return; 
}

graph *crGraph(long int vtc, long int edg)
{
	long int ver1, ver2;
	graph *gr;
	gr = (graph*)malloc(sizeof(graph));
	
	gr->head = (node**)malloc(vtc*sizeof(node*));
	gr->visited = (long int*)malloc(vtc*sizeof(long int));
	gr->arr = (long int*)malloc(vtc*sizeof(long int));
	for(long int i=0; i<vtc; i++)
	{
		gr->head[i]=NULL;
		gr->visited[i]=0;
		gr->arr[i] = -1;	
	}
	
	for(long int i=0; i<edg; i++)
	{
		scanf("%ld %ld", &ver1, &ver2);
		addNode(gr, ver1, ver2);
		addNode(gr, ver2, ver1);
	}
	return gr; 
}

void explore(graph* gr, long int i)
{
	long int ver;
	node *head;
	head = gr->head[i];
	
	if(head==NULL)
	{
		//flag++;
		return;
	}
	
	while(head!=NULL)
	{
		ver = head->ver;
		if(gr->visited[ver]==0)
		{
			flag++;
			gr->visited[ver]=1;
			explore(gr, ver);
		}
		head = head->link;
	}
	return;
}

void dfs(graph* gr, long int vtc)
{
	for(int i=0; i<vtc; i++)
	{
		flag=0;
		if(gr->visited[i]==0)
		{
			flag++;
			gr->visited[i]=1;
			explore(gr, i);
			gr->arr[h]=flag;
			h++;			
		}
	}
	flag=0;
	return;
}


int main()
{
	long int vtc, edg;
	graph *gr;
	scanf("%ld %ld", &vtc, &edg);
	gr = crGraph(vtc, edg);
	dfs(gr, vtc);
	//printf("h %ld\n", flag);		//This is fine
	for(long int i=0; i<h; i++)
	{
		vtc = vtc-gr->arr[i];
		flag+=vtc*gr->arr[i];
		//printf("arr[%d]: %d\n", i, gr->arr[i]);
	}
	printf("%ld\n", flag);		
	return 0;
}


