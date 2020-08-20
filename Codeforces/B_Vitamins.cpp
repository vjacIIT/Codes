#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<climits>
#include<iostream>
#include<map>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define newline		printf("\n");
#define scan(n)		scanf("%d",&n)
#define mp	make_pair
#define pb	push_back
#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<bool> vb;
typedef vector<vb>	vvb;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;

map<string,int> V_int;

int main(){
	V_int["A"]=1;	V_int["B"]=2;	V_int["C"]=4;	V_int["AB"]=3;	V_int["BC"]=6;	V_int["AC"]=5;	V_int["ABC"]=7;
	vi val;
	string s;
	bool has[3];
	char vit[5];
	int n, no, cnt, ans=INT_MAX, value;
	scan(n);
	val = vi(8,INT_MAX);
	loop(i,n){
		scanf("%d %s",&no,vit);
		s=vit;
		sort(s.begin(),s.end());
		val[V_int[s]]=min(no,val[V_int[s]]);
	}
	loop(i,1<<8){
		loop(j,3)	has[j]=false;	value=0;
		Loop(j,1,8){
			if(i&(1<<j)){
				if(val[j]!=INT_MAX)	value+=val[j];
				else{	value=-1;	break;	}
				no=j;	cnt=0;
				while(no){
					if(no%2)	has[cnt]=true;
					cnt++;	no/=2;
				}
			}
		}
		if(value>0 && has[0] && has[1] && has[2])	ans=min(ans,value);
	}
	if(ans!=INT_MAX)	printf("%d\n",ans);
	else	printf("-1\n");
	return 0;
}
