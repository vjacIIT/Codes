#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	
	vector<int> v(n,0);
	vector<int> f(n,0);
	set<int> s;
	
	for(int i=0; i<n; i++)	cin>>v[i];
	s.insert(v[n-1]);
	f[n-1]=1;
	for(int i=n-2; i>=0; i--){
		if(s.find(v[i])==s.end()){
			f[i]=f[i+1]+1;
			s.insert(v[i]);
		}
		else	f[i]=f[i+1];
	}
	
	for(int i=0; i<m; i++){
		cin>>n;
		n--;
		cout<<f[n]<<endl;
	}
	return 0;
}
