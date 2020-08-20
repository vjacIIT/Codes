#include<cstdio>
#include<vector>
using namespace std;

typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
typedef long long ll;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define mp	make_pair
#define pb	push_back
#define newline	printf("\n")

vpi dom, place;
int n,m;
bool ans;

void backtrack(int idx, int mask){
	if(ans)	return;
	if(idx==n+1){
		if(place[n].second==place[n+1].first)	ans=true;
		return;
	}
	Loop(i,1,m+1){
		if(!(mask&(1<<i))){
			if(place[idx-1].second==dom[i].first){
				place[idx].first=dom[i].first;
				place[idx].second=dom[i].second;
				backtrack(idx+1,mask|(1<<i));
			}
			else if(place[idx-1].second==dom[i].second){
				place[idx].first=dom[i].second;
				place[idx].second=dom[i].first;
				backtrack(idx+1,mask|(1<<i));
			}
		}
	}
	return;
}

int main(){
	while(scanf("%d",&n)!=EOF){
		if(!n)	break;
		scanf("%d",&m);
		ans=false;
		dom = vpi(m+2);		place=vpi(n+2);
		scanf("%d%d",&dom[0].first,&dom[0].second);
		scanf("%d%d",&dom[m+1].first,&dom[m+1].second);
		Loop(i,1,m+1)	scanf("%d%d",&dom[i].first,&dom[i].second);
		place[0]=mp(dom[0].first,dom[0].second);
		place[n+1]=mp(dom[m+1].first,dom[m+1].second);
		backtrack(1,(1<<(m+1))+1);
		if(ans)	printf("YES\n");
		else	printf("NO\n");
		dom.clear();	place.clear();
	}
	return 0;
}	
