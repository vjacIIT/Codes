#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define pb	push_back
#define mp	make_pair
#define newline	printf("\n")

typedef vector<pair<int,int>> vpi;
typedef vector<int> vi;
typedef vector<vi> vvi;

map <int,int> fr;
vi wt, frq, help;
int t, n, cnt;

void backtrack(int sum, int idx){
	if(sum==t){
		loop(i,(int)help.size()){
			if(i)	printf("+");
			printf("%d",help[i]);
		}
		cnt++;
		newline;
		return;
	}
	if(!frq[idx])	idx++;
	if(sum>t || idx==n)	return;
	Loop(i,idx,n){
		help.pb(wt[i]);
		frq[i]--;
		backtrack(sum+wt[i],i);
		frq[i]++;
		help.pop_back();
	}
	return;
}

int main(){
	int no;
	while(scanf("%d%d",&t,&n)!=EOF){
		if(!n && !t)	break;
		loop(i,n){
			scanf("%d",&no);	fr[no]++;
		}
		n=0;	cnt=0;
		for(auto it=fr.rbegin(); it!=fr.rend(); it++){
			wt.pb(it->first);
			frq.pb(it->second);
			n++;
		}
		fr.clear();
		printf("Sums of %d:\n",t);
		backtrack(0,0);
		if(!cnt)	printf("NONE\n");
		wt.clear();	frq.clear();	help.clear();
	}
	return 0;
}
