#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* link;
}node;

typedef struct Graph
{
	node **head;
}graph;

void insertNodeBegin(node** ad_head, int value)
{
	node *nd;
	nd = (node*)malloc(sizeof(node));
	nd->data = value;
	if(*ad_head==NULL)
	{	
		nd->link = NULL;
		*ad_head = nd;
		return;  
	}
	nd->link = *ad_head;
	*ad_head = nd;
	return;
}

graph* createGraph(int vtc)
{
	graph* gr;
	int edg, ver1, ver2;
	
	gr = (graph*)malloc(sizeof(graph));
	gr->head = (node**)malloc(vtc*sizeof(node*));
	
	for(int i=0; i<vtc; i++)
		(gr->head)[i]=NULL;
	
	printf("Enter total no of edges: ");
	scanf("%d", &edg);
	
	printf("Enter the values\n");
	for(int j=0; j<edg; j++)
	{
		scanf("%d,%d", &ver1, &ver2);
		insertNodeBegin(&((gr->head)[ver1]), ver2);		// directed graph
	}
	return gr; 
}

void display(graph *gr, int vertices)
{
	node *ptr;
	for(int i=0; i<vertices; i++)
	{
		ptr = gr->head[i];
		if(ptr!=NULL)
		{
			while(ptr->link!=NULL)
			{
				printf("%d->%d ", i, ptr->data);
				ptr = ptr->link;
			}
			printf("%d->%d\n", i, ptr->data);
		}
		else
			continue;
	}
	return;
}

void frf(node *head)
{
	if(head!=NULL)
	{
		if(head->link==NULL)
		{
			free(head);
			return;
		}
		else
		{
			frf(head->link);
			free(head);
			return;
		}
	}
	return;
}

int main()
{
	graph *gr;
	int vtc;
	printf("Enter the total number of vertices: ");
	scanf("%d", &vtc);
	gr = createGraph(vtc);	
	display(gr, vtc);
	
	for(int i=0; i<vtc; i++)
		frf(gr->head[i]);
		
	free(gr);
	return 0;
}
