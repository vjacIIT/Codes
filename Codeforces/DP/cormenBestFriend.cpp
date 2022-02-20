#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,k,n1,n2,cnt=0;
	cin>>n>>k;
	vector<int> v(n,0);
	cin>>n1;
	v[0]=n1;
	for(int i=1; i<n; i++){
		cin>>n2;
		if(n1+n2<k){
			cnt+=k-n1-n2;
			n2=k-n1;
		}
		v[i]=n2;
		n1=n2;
	}
	cout<<cnt<<endl;
	for(int i=0; i<n; i++)	cout<<v[i]<<" ";
	cout<<endl;
	return 0;
}
