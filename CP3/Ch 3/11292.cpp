#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> height;
vector<int> diam;

int n,m;

int search(int st, int end, int no){					// Gives no >= the no
	int mid = (st+end)>>1;
	if(st>end)
		return st;
	if(height[mid]==no)
		return min(mid,search(st,mid-1,no));				// this is important
	else if(height[mid]>no)
		return search(st,mid-1,no);
	else
		return search(mid+1,end,no);
}

int main(){
	bool poss;
	int ind, minval;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0 && m==0)
			break;
		diam = vector<int> (n);
		height = vector<int> (m);
		for(int i=0; i<n; i++)
			scanf("%d",&diam[i]);
		for(int i=0; i<m; i++)
			scanf("%d",&height[i]);
		sort(diam.begin(),diam.end());
		sort(height.begin(),height.end());
		
		poss = true;
		minval = 0;
		ind = 0;
		for(int i=0; i<n; i++){
			ind = search(ind,m-1,diam[i]);
			if(ind>=m){
				poss=false;
				break;
			}
			minval += height[ind];
			ind++;
		}
		if(!poss)
			printf("Loowater is doomed!\n");
		else
			printf("%d\n",minval);
	}
	return 0;
}
// There is no need for binary search, we can do it in linear fashion
