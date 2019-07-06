#include<cstdio>
#include<queue>
using namespace std;

int main(){
	priority_queue<long int,vector<long int>,greater<long int>> q;
	int n;
	long int cost, no, no2;
	while(scanf("%d",&n)!=EOF){
		if(n==0)	break;
		cost=0;
		for(int i=0; i<n; i++){	scanf("%ld",&no);	q.push(no);	}
		while(q.size()>1){
			no=q.top();	q.pop();	no2=q.top();	q.pop();
			cost+=no+no2;	q.push(no+no2);
		}
		printf("%ld\n",cost);
		q.pop();
	}
	return 0;
}
