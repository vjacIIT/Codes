#include<iostream>
#include<vector>
using namespace std;

int main(){
	long int fac=1,mod=1000000007; 
	vector<long int> fn(1000001);
	fn[0]=0;
	for(long int i=1; i<1000001; i++){
		fn[i]=((fac*i)%mod+(fn[i-1])%mod)%mod;
		fac = (fac*(i+1))%mod;
	}
	int tc,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		printf("%ld\n",fn[n]);
	}
	return 0;
}
