#include<bits/stdc++.h>
using namespace std;

long int mod(long int m){
	m = (m<0) ? -m : m;
	return m;
}

int main(){
	vector<long int> cp;
	vector<long int> cn;
	int tc, np;
	long int xi, yi, min;
	double ans=0.0000000000;
	scanf("%d",&tc);
	while(tc--){
		min = INT_MAX;
		scanf("%d",&np);
		for(int i=0; i<np; i++){
			scanf("%ld%ld",&xi,&yi);
			cp.push_back(yi-xi);
			cn.push_back(yi+xi);
		}
		sort(cp.begin(),cp.end());
		sort(cn.begin(),cn.end());
		for(int i=1; i<np; i++){
			if(min>mod(cp[i]-cp[i-1]))	min=mod(cp[i]-cp[i-1]);
			if(min>mod(cn[i]-cn[i-1]))	min=mod(cn[i]-cn[i-1]);
		}
		ans = (1.0*(double)min)/2;
		cout<<setprecision(20)<<ans<<endl;
		cp.clear();
		cn.clear();
	}
}
