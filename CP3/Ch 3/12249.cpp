#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define pb	push_back
#define mp	make_pair
#define scan(a)		scanf("%d",&a)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,string> is;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<is> vis;

int main(){
	string str, s2;
	char s[20];
	vis v;
	int tc, n, Mlen, len, slen, cnt, ans;
	scan(tc);
	loop(cse,tc){
		ans=INT_MAX;
		scan(n);
		loop(i,n){
			scanf("%s",s);	str=s;
			v.pb(mp(i,str));
		}
		do{
			str="";	str+=v[0].second;
			Loop(i,1,n){
				Mlen=0;		s2=v[i].second;
				len=s2.length();	slen=str.length();	len=min(len,slen);
				loop(l,len){
					cnt=0;
					loop(j,l+1){
						if(str[slen-1-l+j]==s2[j])	cnt++;
						else	break;
					}
					if(cnt==l+1)	Mlen=cnt;
				}
				cnt=s2.length();
				while(Mlen<cnt)	str+=s2[Mlen++];
				s2.clear();
			}
			ans=min(ans,(int)str.length());
			str.clear();
		}while(next_permutation(v.begin(),v.end()));
		printf("Case %d: %d\n",cse+1,ans);
		v.clear();
	}
	return 0;
}
