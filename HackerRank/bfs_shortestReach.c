#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int ver;
	struct node *link;
}node;

typedef struct que
{
	int *arr;
	int rear, front;
}que;

typedef struct Graph
{
	node **head;
	int *visited;
	int *dtc;
	que *q;
}graph;

void addNode(graph* gr, int i, int ver)
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

graph *crGraph(int vtc, int edg)
{
	int ver1, ver2;
	graph *gr;
	gr = (graph*)malloc(sizeof(graph));
	
	gr->head = (node**)malloc(vtc*sizeof(node*));
	gr->q = (que*)malloc(sizeof(que));
	gr->q->arr = (int*)malloc(vtc*sizeof(int));
	gr->q->front = 0;
	gr->q->rear = -1;
	gr->visited = (int*)malloc(vtc*sizeof(int));
	gr->dtc = (int*)malloc(vtc*sizeof(int));
	for(int i=0; i<vtc; i++)
	{
		gr->head[i]=NULL;
		gr->visited[i]=0;
		gr->dtc[i] = -1;	
	}
	
	for(int i=0; i<edg; i++)
	{
		scanf("%d %d", &ver1, &ver2);
		ver1--;		ver2--;
		addNode(gr, ver1, ver2);
		addNode(gr, ver2, ver1);
	}
	return gr; 
}

void eq(que *q, int ver)
{
	q->rear = q->rear+1;
	q->arr[q->rear] = ver;
	return;
}

int dq(que *q)
{
	if(q->front>q->rear)
		return -1;
	int ver =q->arr[q->front];
	q->front = q->front+1;
	return ver;
}

int isEmpty(que *q)
{
	if(q->front>q->rear)
		return 1;
	return 0;
}

void bfs(graph *gr, int sp)
{
	int ver, u;
	gr->dtc[sp]=0;		// WE need to go to all the adjacent vetices of the sp, then next level of sp , and so on
	node *head;
	gr->visited[sp]=1;
	eq(gr->q, sp);
	while(1)
	{
		u = dq(gr->q);
		if(u==-1)
			break;
		head= gr->head[u];
		while(head!=NULL)
		{
			ver = head->ver;
			if(gr->visited[ver]==0)
			{
				gr->visited[ver]=1;
				gr->dtc[ver]=gr->dtc[u]+6;
				eq(gr->q, ver);
			}
			head = head->link;
		}
	}
}

void displayList(graph* gr, int vtc)
{
	node *head;
	for(int i=1; i<vtc; i++)
	{
		head = (gr->head)[i];
		if(head!=NULL)
		{
			printf("%d->", i);
			while(head->link!=NULL)
			{
				printf("%d->",head->ver);
				head= head->link;
			}
			printf("%d\n", head->ver);
		}
		else
			printf("%d\n",i);
		
	}
	return;
}

int main()
{
	int tc, vtc, edg, sp;
	graph *gr; 
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d %d", &vtc, &edg);
		gr = crGraph(vtc, edg);
		scanf("%d", &sp);
		//sp=sp-1;
		bfs(gr, sp-1);			
		for(int i=0; i<vtc; i++)
		{
			if(i!=sp-1)
				printf("%d ", gr->dtc[i]);	
		}
		printf("\n");
		//displayList(gr, vtc);
	}
	
	return 0; 	
}
