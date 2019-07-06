#include<cstdio>
#include<stack>
#include<queue>
using namespace std;

int main(){
	stack<int> stk;	queue<int> q;	priority_queue<int> pq;
	bool check[3];						// stack, queue, priority queue
	int n, id, no;
	while(scanf("%d",&n)!=EOF){
		for(int i=0; i<3; i++)	check[i]=true;
		for(int i=0; i<n; i++){
			scanf("%d%d",&id,&no);
			if(id==1){	stk.push(no);	q.push(no);		pq.push(no);	}
			else{
				if(stk.size()>0){
					id=stk.top();	if(id!=no)	check[0]=false;		stk.pop();
				}
				else	check[0]=false;
				if(q.size()>0){
					id=q.front();		if(id!=no)	check[1]=false;		q.pop();
				}
				else	check[1]=false;
				if(pq.size()>0){
					id=pq.top();	if(id!=no)	check[2]=false;		pq.pop();
				}
				else	check[2]=0;
			}
		}
		no=0;
		for(int i=0; i<3; i++){	
			if(check[i]){	
				no++;
				id=i;
			}
		}
		if(no==0)	printf("impossible\n");
		else if(no>1)	printf("not sure\n");
		else{
			if(id==0)	printf("stack\n");
			else if(id==1)	printf("queue\n");
			else	printf("priority queue\n");
		}
		while(q.size()>0){	stk.pop();	q.pop();	pq.pop();	}
	}
}
