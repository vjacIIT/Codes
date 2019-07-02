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
	int value;
	struct node *next_link;
}node;

typedef struct stack
{
	node* top;
}stack;

stack* createStackLinkedList()
{
	stack *st;
	st=(stack*)malloc(sizeof(stack));
	st->top=NULL;
	return st;
}

void push(stack *st, int key)	// top->next stores the address of the node below it , not above it , otherwise it would have saved NULL all the time  
{
	node *add;
	add=(node*)malloc(sizeof(node));
	add->value=key;
	if(st->top==NULL)
	{
		add->next_link=NULL;
		st->top=add;
		return;
	}
	
	add->next_link = st->top;
	st->top=add;
	return;
}

int pop(stack *st)
{
	node* deleter;
	int ex_val ;
	if(st->top==NULL)
		return -1;
	
	deleter = st->top;
	ex_val = (st->top)->value;
	st->top=(st->top)->next_link;
	free(deleter);
	return 	ex_val;
}

int peek(stack *st)
{
	if(st->top==NULL)
		return -1;
	return (st->top)->value;
}

void display(stack *st)
{
	node* temp;
	temp =st->top;
	while(temp!=NULL)
	{
		printf("%d ", temp->value);
		temp=temp->next_link;
	}	
	printf("\n");
	return;
}

int main (int argc, char **argv)
{
    char line[128];
    char v1[15];
    char v2[15];
    char v3[15];

    stack *st;
    st = createStackLinkedList();
    int ret;

    while (fgets(line, sizeof line, stdin) != NULL )
    {
        sscanf(line, "%s %s %s", v1, v2, v3);

        if(strcmp(v1,"PUSH") == 0)
        {
            	push(st, stoi(v2));
        }
        else if(strcmp(v1,"POP") == 0)
        {
            ret = pop(st);
                printf("%d\n", ret);
        }
        else if(strcmp(v1,"PEEK") == 0)
        {
            ret = peek(st);
            printf("%d\n", ret);
        }
        else if(strcmp(v1,"PRT") == 0)
        {
            display(st);
        }
        else
        {
            printf("INVALID\n");
        }
    }

    if(st)
        free(st);

    return 0;
}
