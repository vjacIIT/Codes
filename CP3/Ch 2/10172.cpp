#include<cstdio>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

int main(){
	int tc, tm, ns, ss, sq, qi, id, tno, no;
	scanf("%d",&tc);
	while(tc--){
		tno=0;	tm=0;	scanf("%d%d%d",&ns,&ss,&sq);	// no stations, size of stack and queue
		vector<queue<int>>	q(ns);
		stack<int>	stk;
		for(int i=0; i<ns; i++){
			scanf("%d",&qi);	tno+=qi;
			for(int j=0; j<qi; j++){
				scanf("%d",&id);		q[i].push(id-1);
			}
		}
		no=0;
		while(tno!=0){				// total number of boxes
			while(stk.size()<ss && !q[no].empty()){					// load 
				id=q[no].front();
				stk.push(id);	q[no].pop();
				tm++;
			}														
			no++;	no%=ns;	if(tno!=0)	tm+=2;						// go next
			while(stk.size()>0){									// unload
				id = stk.top();
				if(id==no){	tno--;	tm++;	stk.pop();	}
				else if(q[no].size()<sq){	stk.pop();	q[no].push(id);	tm++;	}
				else	break;
			}
		}
		printf("%d\n",tm);
	}
	return 0;
}
