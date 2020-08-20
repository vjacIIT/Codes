#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(const long int a, const long int b){
	return a>b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<long long>	lzy;		// times index comes in queries
	vector<long long>	ar;
	int n, q, l, r, idx;
	long long ans, no;
	
	cin>>n>>q;
	ar = vector<long long>(n+1);	ar[0]=0;		
	lzy=vector<long long> (n+1);	
	lzy[0]=0;	lzy[n+1]=0;	
	for(int i=1; i<=n; i++){	
		lzy[i]=0;
		cin>>ar[i];
	}
	for(int i=0; i<q; i++){
		cin>>l>>r;
		lzy[l]++;	lzy[r+1]--;
	}
	
	for(int i=1; i<n+1; i++)	lzy[i]+=lzy[i-1];
	sort(lzy.begin(),lzy.end(),compare);
	sort(ar.begin(),ar.end(),compare);
	
	idx=0;	ans=0;
	while(idx<n){
		no = ar[idx]*lzy[idx];
		ans+=no;
		idx++;
	}
	cout<<ans<<"\n";
	lzy.clear();	ar.clear();
	return 0;
}
