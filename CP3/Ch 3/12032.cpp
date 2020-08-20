#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int n;
vector<int> v;

bool possible(int s){
	for(int i=1; i<=n; i++){
		if(v[i]-v[i-1]>s)
			return false;
		else if(v[i]-v[i-1]==s)
			s--;
	}
	return true;
}

int main(){
	int t, m, low, high;
	bool k;
	scanf("%d",&t);
	for(int cse=1; cse<=t; cse++){
		scanf("%d",&n);
		v = vector<int>(n+1);
		v[0] = 0;
		for(int i=1; i<=n; i++)
			scanf("%d",&v[i]);
		
		low = v[1];
		high = v[n];
		for(int i=0; i<30; i++){
			m = (low+high)/2;
			k = possible(m);
			if(k)
				high = m;
			else
				low = m;
		}
		printf("Case %d: %d\n",cse,high);
		v.clear();
	}
	return 0;
}
