#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
using namespace std;

vector<int> v;

int search(int s, int e, int n){
	int m = (s+e)>>1;
	if(s>e)
		return -1;
	if(v[m]==n)
		return m;
	else if(v[m]>n)
		return search(s,m-1,n);
	else
		return search(m+1,e,n);
}

int main(){
	int n, ind, a1, a2, s, curr;
	while(scanf("%d",&n)!=EOF){
		v.clear();
		curr = INT_MAX;
		v = vector<int>(n);
		for(int i=0; i<n; i++)
			scanf("%d",&v[i]);
		sort(v.begin(),v.end());
		scanf("%d",&s);
		for(int i=0; i<n; i++){
			ind=search(0,n-1,s-v[i]);
			if(ind!=-1 && ind!=i){
				if(abs(v[ind]-v[i])<curr){
					a1=v[ind];
					a2=v[i];
					curr = abs(a1-a2);
				}
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",min(a1,a2),max(a1,a2));
	}	
	return 0;
}
