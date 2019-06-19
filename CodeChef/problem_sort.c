#include<stdio.h>
#include<stdlib.h>

struct sc_st
{
		int scr, std;
};

struct value_index
{
		int val, ind;
};

int com1(const void *x, const void *y)
{
		return (((struct sc_st *)x)->scr)-(((struct sc_st *)y)->scr);
}

int comp2(const void *x, const void *y)
{
		return (((struct value_index *)x)->val)-(((struct value_index *)y)->val);
}

int main()
{
	int pbs, stk, n, index, min;
	struct value_index *val_ind;
	struct sc_st *scr_std;
	
	scanf("%d %d", &pbs, &stk);
	
	val_ind = (struct value_index *)malloc(pbs*sizeof(struct value_index));
	scr_std = (struct sc_st *)malloc(stk*sizeof(struct sc_st));
	
	for(int i=0; i<pbs; i++)
	{
			n=0;
			
			for(int j=0; j<stk; j++)		
					scanf("%d", &((scr_std+j)->scr));
			for(int j=0; j<stk; j++)
					scanf("%d", &((scr_std+j)->std));
			qsort(scr_std, stk, sizeof(struct sc_st), com1);
			
			for(int j=0; j<stk-1; j++)
					if(((scr_std+j)->std)>((scr_std+j+1)->std))
							n++;
			//printf("\n%d\n", n);
			(val_ind + i)->val = n;
			(val_ind + i)->ind = i;
	}
	qsort(val_ind, pbs, sizeof(struct value_index), comp2);
	
	for(int i=0; i<pbs; i++)
			printf("%d\n", ((val_ind +i)->ind)+1);
			
	return 0;
}
