#include<cstdio>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;

int n, m, q;
vector<int> a, lazy;				// lazy[i] stores number of intervals (games) alice wins with g=i 
map<pair<int,int>,int> interval; 

int main(){
	int tc, l, r, freq, help, ans;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d%d%d",&n,&q,&m);
		a = vector<int>(n+1);
		lazy = vector<int>(1000001,0);
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		for(int i=0; i<q; i++){
			scanf("%d%d",&l,&r);
			if(a[l]>m)							// alice cannot win this game for any g
				continue;
			else if(a[l]<=m && a[r]>m){			// m in [a[l], a[r]), hence a[l] to m values are put in lazy
				lazy[a[l]]++;
				lazy[m+1]--;
			}
			else if(a[r]<=m){							// m>=a[r] hence many values above a[r] can cause alice to win
				lazy[a[l]]++;
				lazy[m+1]--;
				interval[make_pair(a[l],a[r])]++;
				// to match that pattern, we have inserted it into a map
			}
		}
		// take example interval = [2,5]  and m = 10
		for(auto it=interval.begin(); it!=interval.end(); it++){
			l=(*it).first.first;				// left
			r=(*it).first.second;				// right
			freq=(*it).second;					// number of times this came into queries
			help=l+r;
			lazy[help]-=freq;
			lazy[help+l]+=freq;
			help+=l;
			while(help+r<=m){
				help+=r;
				lazy[help]-=freq;
				lazy[help+l]+=freq;
				help+=l;
			}
		}
		ans=0;
		for(int i=1; i<=m; i++)
			lazy[i]+=lazy[i-1];
		for(int i=1; i<=m; i++)
			ans=max(ans,lazy[i]);
		printf("%d\n",ans);
		interval.clear();
	}
	return 0;
}
