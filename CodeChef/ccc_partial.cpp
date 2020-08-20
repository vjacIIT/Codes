#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

vector<int> v1;
vector<pair<int,int>> v2;

int find(int l){
	int f=0, ans=INT_MAX;
	for(int i=l-1; i>=0; i--){
		ans = min(ans,(f+1)*v2[i].first);
		f+=v2[i].second;
	}
	return ans;
}

int main(){
	int tc, ans, n, z, cnt;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d%d",&n,&z);
		v1 = vector<int>(n+1);
		for(int i=0; i<n; i++)	scanf("%d",&v1[i]);
		v1[n]=INT_MAX;
		sort(v1.begin(),v1.end());
		for(int i=0; i<n; i++){
			cnt=1;
			while(v1[i]==v1[i+1]){	cnt++;	i++;	}
			v2.push_back(make_pair(v1[i],cnt));
		}
		ans = find(v2.size());
		printf("%d\n",ans);
		v1.clear();	v2.clear();			
	}
	return 0;
}

// Only works for Z=1
