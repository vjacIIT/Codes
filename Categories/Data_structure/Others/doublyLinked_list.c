#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stoi(char *str)
{
    int x;
    sscanf(str, "%d", &x);
    return x;
}

typedef struct node
{
	struct node *prev;
	int value;
	struct node *next;
}node;


void append(node **ad_root, int key)
{
	node *nd;
	node *temp;
	if(*ad_root==NULL)
	{
		nd=(node*)malloc(sizeof(node));
		nd->value = key;
		nd->prev = *ad_root;
		(*ad_root) = nd;
		nd->next = NULL;
		return;
	}
	
	temp =*ad_root;
	while(temp->next!=NULL)
		temp = temp->next;
	nd = (node*)malloc(sizeof(node));
	nd->value = key;
	nd->prev = temp;
	nd->next = NULL;
	temp->next = nd;
	return;
}

void nodeInsertBeginning(node **ad_root, int key)
{
	node *nd;
	nd = (node*)malloc(sizeof(node));
	nd->value=key;
	nd->prev=NULL;
	nd->next = *ad_root; 
	*ad_root = nd;
	return;
}

int len_dLinkedList(node** ad_root)
{
	node *temp;
	int len=0;
	temp = *ad_root;
	while(temp!=NULL)
	{
		len++;
		temp = temp->next;
	}
	return len;
}

void display(node **ad_root)
{
	node *temp;
	temp = *ad_root;
	while(temp!=NULL)
	{
		printf("%d ", temp->value);
		temp= temp->next;
	}
	printf("\n");
	return;
}

void search(node **ad_root, int key)
{
	node *temp;
	int ind=1;
	temp = *ad_root;
	while(temp!=NULL)
	{
		if(temp->value==key)
		{
			printf("Key found at index: %d\n", ind);
			return;
		}
		temp=temp->next;
		ind++;
	}
	
	printf("Entered key is not in the doubly linded list\n");
	return;
}

void deleteNode(node **ad_root, int ind)
{
	node *temp, *deleter;
	int len = len_dLinkedList(ad_root);
	if(ind>len || ind<=0)
	{
		printf("Invalid index\n");
		return;
	}
	else
	{
		temp = *ad_root;
		if(ind==1)
		{
			deleter = *ad_root;
			*ad_root=deleter->next; 
			(deleter->next)->prev = NULL;
			deleter->next=NULL;
			deleter->prev = NULL;
			free(deleter);
			return;
		}
		else
		{
			ind=ind-2;
			while(ind--)
				temp=temp->next;
			deleter = temp->next;
			temp->next = deleter->next;
			(deleter->next)->prev=temp;
			deleter->next = NULL;
			deleter->prev = NULL;
			free(deleter);
			return;	
		}
	}
}

void insertNodeMiddle(node **ad_root, int ind, int key)
{
	node *temp ;
	node *nd;
	int len=len_dLinkedList(ad_root);
	temp = *ad_root;
	if(ind>len+1 || ind<=1)
	{
		printf("Invalid index\n");
		return;
	}
	
	nd = (node*)malloc(sizeof(node));
	nd->value = key;
	ind=ind-2;
	while(ind--)
		temp=temp->next;
	nd->prev = temp;
	nd->next = temp->next;
	(temp->next)->prev=nd;
	temp->next = nd;
	return;
}

	
int main (int argc, char **argv)
{

	int no, len;
	node* root;
	root =NULL;
	char line[128];
	char v1[15];
	char v2[15];
	char v3[15];

	while (fgets(line, sizeof line, stdin) != NULL )
	{
		sscanf(line, "%s %s %s", v1, v2, v3);

		if(strcmp(v1,"APP") == 0)
			append(&root, stoi(v2));
		
		else if(strcmp(v1,"INSBG") == 0)
			nodeInsertBeginning(&root, stoi(v2));
		    	
		else if(strcmp(v1,"SZE") == 0)
			len_dLinkedList(&root);
		    
		else if(strcmp(v1,"PRT") == 0)
			display(&root);
			
		else if(strcmp(v1,"DEL")==0)
			deleteNode(&root, stoi(v2));
			
		else if(strcmp(v1,"INSMD") == 0)
			insertNodeMiddle(&root, stoi(v2), stoi(v3));
		    
		else if(strcmp(v1,"SCH")==0)
			search(&root, stoi(v2));
			
		else
			printf("INVALID\n");
		
	}

	return 0;
}
