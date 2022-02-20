#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> v(1000000,0); 		// size, value
	int n,ind,q;
	cin>>n;	
	for(int i=0; i<n; i++){
		cin>>ind;
		v[ind]++;
	}
	for(int i=1; i<1000000; i++)	v[i]+=v[i-1];
	cin>>q;
	for(int i=0; i<q; i++){
		cin>>ind;
		if(ind<1000000)	cout<<v[ind]<<endl;
		else	cout<<n<<endl;
	}
	return 0;
}
