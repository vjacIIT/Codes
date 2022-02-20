#include<cstdio>
#include<vector>
#include<set>
#include<iostream>
using namespace std;

int main(){
	int n, tc, no;
	scanf("%d",&tc);
	while(tc--){
		int ans=0;
		set<int> s;
		scanf("%d",&n);
		for(int i=0; i<n; i++){
			scanf("%d",&no);
			if(s.find(no)!=s.end())
				continue;
			s.insert(no);
			ans++;
		}
		printf("%d\n",ans);
		s.clear();
	}
}
