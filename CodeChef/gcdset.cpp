#include<iostream>
using namespace std;

int main(){
	int tc;
	long long int l,r,g, nr, nl, ans;
	scanf("%d",&tc);
	while(tc--){
		ans=0;
		scanf("%lld%lld%lld",&l,&r,&g);
		if(g<=r){
			nr = r/g;
			nl = l/g;
			if(l%g==0)	ans++;
			ans+=nr-nl;
			if(ans==1 && g<l)	printf("0\n");		// then g, 2g.... are also multiples
			else	printf("%lld\n",ans);
		}
		else	printf("0\n");
	}
	return 0;
}
