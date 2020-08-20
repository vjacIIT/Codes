#include<cstdio>
#include<vector>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define mp	make_pair

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll; 

vll coef;

ll func(ll cnt){
	ll acnt=1, ans=0;
	int l=coef.size(),i=0;
	loop(i,l){ ans+=coef[i]*acnt;	acnt*=cnt;	}
	return ans;
}

int main(){
	ll v,cnt;
	int tc, i, n, d, k, j, ad;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);	n++;
		coef=vll(n);
		loop(i,n)	scanf("%lld",&coef[i]);
		scanf("%d%d",&ad,&k);
		i=0;	d=ad;	cnt=1;
		while(true){
			loop(j,d){	
				v=func(cnt);	i++;	
				if(i==k){	printf("%lld\n",v);	break;	}	
			}
			if(i==k)	break;
			cnt++;		d+=ad;
		}	
	}
	return 0;
}

// We can make it faster using concept of AP
