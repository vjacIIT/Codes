#include<stdio.h>
#include<stdlib.h>

void isFULL(int* top1, int* top2, int n)
{
	if((*top1)+1==(*top2) || (*top1)==n-1)
		printf("Stack is full\n");
	else
		printf("Stack is not full\n");
	return ;
}

void isEmpty(int *top1, int *top2, int n)
{
	if((*top1)==-1 && (*top2)==-1)
		printf("Stack is empty\n");
	else 
		printf("Stack is not empty\n");
	return ;
}

void push(int *A, int *top1, int *top2, int st_no, int n)
{
	int value;
	if((*top1)+1==(*top2) || (*top1)==n-1)
	{
		printf("Stack is full\n");
		return ;
	}
	
	printf("Enter the value to be pushed:");
	scanf("%d", &value);
	if(st_no==1)
	{
		(*top1)++;
		A[*top1] = value;
	}
	else
	{
		if((*top2)==-1)
			(*top2)=n-1;
		else
			(*top2)--;
		A[*top2]=value;
	}
	return ;
}

void pop(int *A, int *top1, int *top2, int st_no, int n)
{
	if((*top1)==-1 && (*top2)==-1)
	{
		printf("Stack is Empty\n");
		return ;
	}
	
	if(st_no==1)
	{
		if((*top1)==-1)
		{
			printf("Stack 1 is Empty\n");
			return; 
		}
		else
		{
			A[*top1]=-10000;
			(*top1)--;
			return;	
		}
	}
	else
	{
		if((*top2)==-1)
		{
			printf("Stack 2 is Empty\n");
			return;
		}
		else
		{
			A[*top2]=-10000;
			(*top2)++;
			if((*top2)==n)
				(*top2)=-1;
			return;
		}
	}
	
}

void display_element(int *A, int *top1, int *top2, int st_no, int n)
{
	if((*top1)==-1 && (*top2)==-1)
	{
		printf("Stack is Empty\n");
		return ;
	}
	
	if(st_no==1)
	{
		if((*top1)==-1)
		{
			printf("Stack 1 is empty\n");
			return;
		}
		else
		{
			for(int i=0; i<=(*top1); i++)
				printf("%d ", A[i]);
			printf("\n");
		}
	}	
	else
	{
		if((*top2)==-1)
		{
			printf("Stack 2 is empty\n");
			return ;
		}
		else
		{
			for(int i=n-1; i>=(*top2); i--)
				printf("%d ", A[i]);
			printf("\n");
		}
	}
}

void peek(int *A, int *top1, int *top2, int st_no)
{
	if((*top1)==-1 && (*top2)==-1)
	{
		printf("Stack is Empty\n");
		return ;
	}
	if(st_no==1)
	{
		if((*top1)==-1)
		{
			printf("Stack 1 is empty\n");
			return;
		}
		else
		{
			printf("Top element in stack 1 is: %d\n", A[*top1]);
			return ;
		}
	}
	else
	{
		if((*top2)==-1)
		{
			printf("Stack 2 is empty\n");
			return ;
		}
		else
		{
			printf("Top element in stack 2 is: %d\n", A[*top2]);
			return ;
		}
	}
}

int main()
{
	int n, *arr, *ptop1, *ptop2, no, top1=-1, top2=-1;
	ptop1 = &top1;
	ptop2 = &top2;
	printf("Enter the maximum size of two arrays:");
	scanf("%d", &n);
	
	arr = (int *)malloc(n*sizeof(int));
	
	while(1)
	{
		printf("\nEnter 1 for is_Full\n");
		printf("Enter 2 for is_Empty\n");
		printf("Enter 3 for push in stack 1\n");
		printf("Enter 4 for push in stack 2\n ");
		printf("Enter 5 for pop in stack 1\n");
		printf("Enter 6 for pop in stack 2\n");
		printf("Enter 7 for peek in stack 1\n");
		printf("Enter 8 for peek in stack 2\n");
		printf("Enter 9 for display elements in stack 1\n");
		printf("Enter 10 for display elements in stack 2\n");
		printf("Enter 11 for coming out of program\n");
		
		scanf("%d", &no);
		switch(no)
		{
			case 1: isFULL(ptop1, ptop2, n);
					break;
			case 2: isEmpty(ptop1, ptop2, n);
					break;
			case 3: push(arr, ptop1, ptop2, 1, n);
					break;
			case 4: push(arr, ptop1, ptop2, 2, n);
					break;
			case 5: pop(arr, ptop1, ptop2, 1, n);	
					break;
			case 6: pop(arr, ptop1, ptop2, 2, n);
					break;
			case 7: peek(arr, ptop1, ptop2, 1);
					break;
			case 8: peek(arr, ptop1, ptop2, 2);
					break;
			case 9: display_element(arr, ptop1, ptop2, 1, n);
					break;
			case 10: display_element(arr, ptop1, ptop2, 2, n);
					break;
			case 11: printf("See Ya\n");
					return 1;
		}
	}
	return 0;
}
