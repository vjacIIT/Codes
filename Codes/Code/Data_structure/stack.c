#include<stdio.h>
#include<stdlib.h>

void isEmpty(int *top)
{
	if((*top)==-1)
	{
		printf("Stack is empty\n");
		return ;
	}
	
	printf("Stack has %d elements\n", *top);
	return ;
}

void isFull(int *top, int n)
{
	if((*top)==n-1)
	{
		printf("Sorry stack is full\n");
		return ;
	}
	
	printf("Stack is not full, it has %d elements\n", *top);
	return ;
}

void push(int *A, int *top, int n)
{
	int value;
	if((*top)==n-1)
	{
		printf("Sorry stack is full\n");
		return ;
	}
	
	scanf("%d", &value);
	(*top)++;
	A[*top]=value;
	return ;
}

void pop(int *A, int *top)
{
	if((*top)==-1)
	{
		printf("Stack is already empty\n");
		return ;
	}
	
	A[*top]=-1000000;
	(*top)--;
	return ;
}

void peek(int *A, int *top)
{
	if(*top==-1)
		printf("Sorry no item to display, stack is empty\n");
	else
		printf("%d\n", A[*top]);
	return ;
}

void displayElement(int *A, int *top)
{
	if((*top)==-1)
	{
		printf("Stack is empty, No elements to display\n");
		return ;
	}	
	for(int i=(*top); i>=0; i--)
		printf("%d ", A[i]);
	printf("\n");	
	return;
}
	
int main()
{
	int n,no;
	int *A, *top;
	printf("Enter the size of stack:");
	scanf("%d", &n);
	A = (int *)malloc(n*sizeof(int));
	(*top) = -1;
	
	while(1)
	{
		printf("\nEnter 1 for push\n");
		printf("Enter 2 for pop\n");
		printf("Enter 3 for peek\n");
		printf("Enter 4 for isEmpty\n");
		printf("Enter 5 for isFull\n");
		printf("Enter 6 for displayElement\n");
		printf("Enter 7 for exiting the program\n");
		scanf("%d", &no);
		switch(no)
		{
			case 1 : push(A, top, n);
				 	break;
			case 2 : pop(A, top);
				 	break;
			case 3 : peek(A, top);
				 	break;
			case 4 : isEmpty(top);
					break;
			case 5 : isFull(top, n);
				 	break;
			case 6 : displayElement(A, top);
				 	break;
			case 7 : printf("See Ya\n");
				 	return 1;
		}	
	}
	return 0;
}
