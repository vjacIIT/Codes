#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define mp	make_pair
#define pb	push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
typedef vector<ll> vll;
typedef vector<string> vs;

int main(){
	vs name;
	vii price;
	char str[100], s[30];
	string sr;
	int tc, i, d, l, r, q, j, cnt;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d\n",&d);
		loop(i,d){	
			fgets(str,100,stdin);
			sscanf(str,"%s %d %d",s,&l,&r);		
			sr=s;	name.pb(s);	price.pb(mp(l,r));		
		}
		scanf("%d",&q);
		loop(i,q){	
			cnt=0;
			scanf("%d",&r);
			loop(j,d){
				if(price[j].first<=r && price[j].second>=r){
					cnt++;
					sr=name[j];
				}
			}
			if(cnt!=1)	printf("UNDETERMINED\n");
			else	printf("%s\n",sr.c_str());
		}
		price.clear();	name.clear();
		if(tc)	printf("\n");
	}
	return 0;
}

// For each query time is O(d), this is bad, but it still works for this Complete Search problem
