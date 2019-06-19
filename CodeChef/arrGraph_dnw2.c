#include<stdio.h>
#include<stdlib.h>

int ts=0;
int k=0;
int ap[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

typedef struct node
{
	int ver;
	struct node* link;
}node;

typedef struct Graph
{
	node **head;
	int *visited;
}Graph;

int hcf(int a, int b)
{
	int bg, sm, hl;
	if(a>b)
	{
		bg=a;
		sm=b;
	}
	else 
	{
		bg=b;
		sm=a;
	}
	
	while(sm!=0)
	{
		hl=bg;
		bg=sm;
		sm=hl%sm;
	}
	return bg;
}

Graph *CrGraph(int vtc)
{
	Graph *gr;
	gr = (Graph*)malloc(sizeof(Graph));
	

	gr->head = (node**)malloc(vtc*sizeof(node*));
	for(int i=0; i<vtc; i++)
		gr->head[i]=NULL;

	gr->visited = (int*)malloc(vtc*sizeof(int));
	for(int i=0; i<vtc; i++)
		gr->visited[i]=0;	

	return gr; 
}
	
void addNode(Graph *gr, int ver1, int ver2)
{
	node *head;
	node *nd;
	head = gr->head[ver1];
	nd = (node*)malloc(sizeof(node));
	nd->ver = ver2;
	if(head==NULL)
	{	
		nd->link = NULL;
		gr->head[ver1]=nd;
		return;
	}
	nd->link = head;
	gr->head[ver1] = nd;
	return;
}	
	
void explore(Graph *gr, node *head)		// head is the pointer to the ith linked list in the graph (adjacency list)
{
	int ver;
	
	while(head!=NULL)
	{
		ver = head->ver;
		if((gr->visited)[ver]==0)
		{ 
			//printf("vertex %d is visited here\n", ver);
			ts++;
			(gr->visited)[ver]=1;
			explore(gr, (gr->head)[ver]);
		}
		else
			head = head->link;
	}
	if(head==NULL)
	{
		//printf("No path to go, backtrack\n");
		return;	
	}
	
}

int search(int *ap, int key)
{
	for(int i=0; i<15; i++)
	{
		if(ap[i]==key)
			return 1;
	}
	return -1;
}
	
int main()
{
	int tc, N, count, flag;
	Graph *gr;
	int *ar;
	scanf("%d", &tc);
	while(tc--)
	{
		ts=0;
		count=0;
		flag=0;
		k=0;
		scanf("%d", &N);
		//gr = CrGraph(N);
		ar = (int*)malloc(N*sizeof(int));
		for(int i=0; i<N; i++)
		{
			scanf("%d", ar+i);
			if(search(ap, ar[i])==1)
				k++;
		}
		for(int i=0; i<N-1; i++)
		{
			//for(int j=i+1; j<N; j++)
			//{
				if(hcf(ar[0],ar[i+1])==1)
				{
					continue;
					//addNode(gr, i, j);
					//addNode(gr, j, i);
				}
				else if(ar[0]!=29)
				{
					ts++;
					ar[i]=29;
					flag=1;
					break;
				}
			//}
		}
		for(int i=0; i<N; i++)
		{
			if(ar[i]==29)
				count++;
		}
		//explore(gr, (gr->head)[0]);
		if(count!=N)
		{
			//if(gr->visited[i]==0)
			//{
				//ar[i]=ap[k];
				///k++;
			//}
			printf("%d\n",ts);
			for(int i=0; i<N; i++)
				printf("%d ", ar[i]);
			printf("\n");
		}
		else
		{
			if(N==1)
				printf("0\n%d", ar[0]);
			else
				printf("1\n%d", ap[0]);
			for(int i=1; i<N; i++)
				printf(" %d", ar[i]);
			printf("\n");
		}
	}
	return 0; 
}
