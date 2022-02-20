#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int n, q, m;
vector<int> v;

struct data{
	int l, r;
};

vector<data> query;

int noIntervals(int g){								// given g from how many intervals it belongs
	int ans=0, l, r, h;
	for(int i=0; i<q; i++){
		l = query[i].l-1;
		r = query[i].r-1;
		h = g%(v[r]+v[l]);
		if(h<v[l])
			continue;
		else
			ans++;
	}
	//printf("%d %d\n",g,ans);
	return ans;
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int ans=0;
		scanf("%d%d%d",&n,&q,&m);
		v = vector<int>(n);
		query = vector<data>(q); 
		for(int i=0; i<n; i++)
			scanf("%d",&v[i]);
		for(int i=0; i<q; i++)
			scanf("%d%d",&query[i].l,&query[i].r);
		for(int i=1; i<=m; i++)
			ans=max(ans,noIntervals(i));
		printf("%d\n",ans);
	}
	return 0;
}
