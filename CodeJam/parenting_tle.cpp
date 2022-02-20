#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<pair<int,int>,int>> v;			// '0' means 'C' and '1' means 'J'
vector<pair<int,int>> cv;
vector<pair<int,int>> jv;

bool check(){
	if(cv.size()>1)
		for(int i=0; i<cv.size()-1; i++){
			if(cv[i+1].first<cv[i].second)
				return false;
		}
	if(jv.size()>1)
		for(int i=0; i<jv.size()-1; i++){
			if(jv[i+1].first<jv[i].second)
				return false;
		}
	return true;
}

int main(){
	vector<char> ans;
	bool poss;
	int tc, n;
	scanf("%d",&tc);
	for(int t=1; t<=tc; t++){
		poss = false;
		scanf("%d",&n);
		v = vector<pair<pair<int,int>,int>> (n);
		for(int i=0; i<n; i++){
			scanf("%d%d",&v[i].first.first, &v[i].first.second);
			v[i].second = i;
		}	
		sort(v.begin(),v.end());
		for(int i=0; i<(1<<n); i++){
			ans = vector<char> (n);
			for(int b=0; b<n; b++){
				if(i&(1<<b)){
					jv.push_back(make_pair(v[b].first.first,v[b].first.second));
					ans[v[b].second] = 'J';
				}
				else{
					cv.push_back(make_pair(v[b].first.first,v[b].first.second));
					ans[v[b].second] = 'C';
				}
			}
			
			if(check()){
				poss = true;
				printf("Case #%d: ",t);
				for(int b=0; b<n; b++)
					printf("%c",ans[b]);
				printf("\n");
				break;
			}
			cv.clear();
			jv.clear();
			ans.clear();
		}
		if(!poss)
			printf("Case #%d: IMPOSSIBLE\n",t);
		cv.clear();
		jv.clear();
		v.clear();
	}
	return 0;
}

// O(n*2^n solution), higly bad
