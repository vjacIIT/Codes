#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

void append(struct node **ad_root)			// insert_node_middle can do the work of append
{
	struct node *temp, *p;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the value to be stored at last:");
	scanf("%d", &(temp->data));
	temp->link = NULL;
	if(*ad_root==NULL)
		*ad_root=temp;
	else
	{
		p=*ad_root;
		while(p->link!=NULL)
			p = p->link;
		
		p->link=temp;
		temp->link = NULL;
	}
	
}

void node_insert_beginning(struct node **ad_root)	// insert_node_middle can't do the work of this
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the value to be stored at the beginning:");
	scanf("%d", &(temp->data));
	temp->link = *ad_root;
	*ad_root = temp;
}

int len_linked_list(struct node **ad_root)
{
	struct node *temp;
	int len=0;
	temp = *ad_root;
	while(temp!=NULL)
	{
		len++;
		temp = temp->link;
	}
	return len;
}

void display(struct node **ad_root)
{
	struct node *temp;
	temp = *ad_root;
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

void delete_node(struct node **ad_root)
{
	int ind;
	struct node *temp, *deleter;
	printf("Give the location to delete:");
	scanf("%d", &ind);
	if(ind>len_linked_list(ad_root) || ind<=0)
		printf("Inedx is out of bounds\n");
	else 
	{
		temp = *ad_root;
		if(ind==1)			// means we want to deleter node at the beginning
		{
			deleter = *ad_root;
			*ad_root=(*ad_root)->link;
			deleter->link = NULL;
			free(deleter);
		}
		else				// else we go to one node before that node which we want to delete
		{
			for(int i=1; i<ind-1; i++)
				temp = temp->link;
			deleter = temp->link;
			temp->link = deleter->link;
			deleter->link = NULL;
			free(deleter);
		}
	}
	return;
}

void insert_node_middle(struct node **ad_root)
{
	int ind;
	struct node *p, *temp;
	printf("Enter the node index to add and the value:");
	temp = (struct node*)malloc(sizeof(struct node));
	scanf("%d%d", &ind, &(temp->data));
	if(ind>len_linked_list(ad_root)+1 || ind<=1)
		printf("Invalid node index\n");
	else
	{		
		p = *ad_root;
		ind=ind-2;
		while(ind--)
			p=p->link;
		temp->link = p->link;
		p->link = temp;
	}
}

void reverseLinkedListOn2(struct node **ad_root)		
// concept is that it swaps the first and last value in the linked list, then increase the first index and decrease the last index, swaps untill they meet. Address values remains the same, data swaps.
// this works in O(n^2) time. 
{
	struct node *p, *q;
	int i=0, j=len_linked_list(ad_root)-1, k=0; 
	p = *ad_root;
	if(*ad_root==NULL)
	{
		printf("Cannot reverse the linked list, it is Empty\n");
		return ;
	}
	while(i<j)
	{
		q=*ad_root;
		k=0;
		while(k<j)
		{
			k++;
			q=q->link;
		}
		k=p->data;
		p->data = q->data;
		q->data = k;
		p=p->link;
		i++;
		j--;
	}
	return;
}

void reverseLinkedListOn(struct node **ad_root)
// concept is that it changes the input address->link of nodes , it works on three nodes at the same time. It works in O(n) time.
{
	struct node *temp, *var;
	if(*ad_root==NULL)
	{
		printf("Cannot reverse the linked list, it is Empty\n");
		return ;
	}
	temp=(*ad_root)->link;
	(*ad_root)->link=NULL;
	while(temp!=NULL)
	{
		var = temp->link;
		temp->link = *ad_root;
		*ad_root = temp;
		temp = var;
	}
	return;
}

void printElementReverse(struct node *root)		// prints the elements of the linked list in reverse order without changing the linked list.
{
	if(root->link==NULL)
	{
		printf("%d ", root->data);
		return;
	}
	if(root->link!=NULL)
	{
		printElementReverse(root->link);
		printf("%d ", root->data);
	}
	return;
}

int main()
{
	int no, len;
	struct node *root;
	root = NULL;
	
	while(1)
	{
		printf("\nEnter 1 for append the linked_list\n");
		printf("Enter 2 for node insert at the beginning\n");
		printf("Enter 3 for length of linked list\n");
		printf("Enter 4 for display the elements of linked_list\n");
		printf("Enter 5 for deleting a node\n");
		printf("Enter 6 for inseting a node at the middle\n");
		printf("Enter 7 for reversing the linked list in O(n^2) time\n");
		printf("Enter 8 for reversing the linked list in O(n) time\n");
		printf("Enter 9 for printing the linked list in reverse order\n");
		printf("Enter 10 for coming out of program\n");
		scanf("%d", &no);
		
		switch(no)
		{
			case 1 : append(&root);
					break;
			case 2 : node_insert_beginning(&root);
					break;
			case 3 : len=len_linked_list(&root);
					printf("length of linked list is: %d\n", len);
					break;
			case 4 : display(&root);
					break;
			case 5 : delete_node(&root);
					break;
			case 6 : insert_node_middle(&root);
					break;
			case 7 : reverseLinkedListOn2(&root);
					break;
			case 8 : reverseLinkedListOn(&root);
					printf("\n");
					break;
			case 9 : printElementReverse(root);
					break;
			case 10 : printf("See Ya\n");
					return 1;
		}
	}
	
	return 0;
}
