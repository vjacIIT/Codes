#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<climits>
#include<iostream>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define Loop(i,a,n)	for(int i=a; i<n; i++)
#define newline		printf("\n")
#define scan(n)		scanf("%d",&n)
#define print(n)	printf("%d",n)
#define mp	make_pair
#define pb	push_back
const int Mod = 1e9+7;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int ns, dist;
vi stone, type, scp;

int search(int st, int end, int n, bool flg){			// jumping maximum it can is looking fine
	int m = (st+end)>>1;
	if(st>end)
		return end;
	if(flg){
		if(stone[m]==n)
			return m;
		else if(stone[m]<n)
			return search(m+1,end,n,flg);
		else
			return search(st,m-1,n,flg);
	}
	else{
		if(scp[m]==n)
			return m;
		else if(scp[m]<n)
			return search(m+1,end,n,flg);
		else
			return search(st,m-1,n,flg);
	}
}

bool forward(int d){
	loop(i,ns+2)
		scp[i]=stone[i];
		
	int ind = 0, temp;
	while(ind<ns+1){
		temp = search(ind+1,ns+1,stone[ind]+d,true);
		if(temp==ind)
			return false;
		if(type[ind]==0)					// small stone
			scp[ind]=-1;
		ind = temp;							// reached the temp stone
	}
	return true;
}

bool backward(int d){
	int ind=0, temp;
	sort(scp.begin(),scp.end());
	while(scp[ind]==-1){
		scp[ind]=0;
		ind++;
	}
	loop(i,ns+2)
		scp[i]=dist-scp[i];
	reverse(scp.begin(),scp.end());
	ind=0;
	while(scp[ind]!=dist){
		temp = search(ind+1,ns+1,scp[ind]+d,false);
		if(temp==ind)
			return false;
		ind = temp;
	}
	return true;
}

bool canReach(int d){
	bool f=false, b=false;
	f = forward(d);
	if(!f)
		return false;
	
	b = backward(d);
	if(b)
		return true;
	else
		return false;
}

int main(){
	int tc,d,st,end;
	char ty,ch;
	scan(tc);
	loop(t,tc){	
		cin>>ns>>dist;
		//scanf("%d%d",&ns,&dist);
		type = vi(ns+2);
		stone = vi(ns+2);
		scp = vi(ns+2);
		type[0]=1;								// Big stone
		stone[0]=0;								// 0th stone at 0 distance from left
		type[ns+1]=1;							// Last stone is also Big
		stone[ns+1]=dist;						// last stone at dist distance
		loop(i,ns){
			//if(i)
				//scanf(" ");
			cin>>ty>>ch>>d;
			//scanf("%c%c%d",&ty,&ch,&d);
			type[i+1]= (ty == 'B' ? 1 : 0);
			stone[i+1]=d;
		}
		//scanf("\n");	
		st = 0;
		end = dist;
		loop(i,30){
			d = (st+end)>>1;
			if(canReach(d))
				end = d-1;
			else
				st=d+1;
		}
		printf("Case %d: %d\n",t+1,end+1);
	}
	return 0;
}
// See how I needed to change input format
// So my solution is not greedy, this problem can be done using greedy strategy
// Idea is to take the maximum distance between 2 consecutive stones, problem becomes minimax b/w 2 big stones
// Also see that small stones will be used at max once, hence frog will jump alternate small stones
