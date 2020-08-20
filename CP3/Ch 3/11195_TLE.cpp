#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
vi row;
vvb pcd;

int n,cnt;

bool check(int r, int c){
	int i,j,d1,d2;
	bool srow;
	for(i=0; i<c; i++){
		if(row[i]==r)	return false;
		d1=abs(c-i);	d2=abs(row[i]-r);
		if(d1==d2)	return false;
	}
	return true;
}

void dfs(int c){
	int i;
	if(c==n){	cnt++;	return;	}
	for(i=0; i<n; i++){
		if(!pcd[i][c] && check(i,c)){
			row[c]=i;
			dfs(c+1);
			row[c]=-1;
		}
	}
	return;
}

int main(){
	char str[30],c;
	int i,j,cse=1;
	while(scanf("%d",&n)!=EOF){
		if(n==0)	break;
		scanf("\n");
		cnt=0;
		row=vi(n,-1);	pcd=vvb(n,vb(n,false));
		for(i=0; i<n; i++){
			j=0;
			fgets(str,20,stdin);	c=str[0];
			while(c!='\n'){
				c=='*'	? pcd[i][j]=true:pcd[i][j]=false;
				j++;	c=str[j];
			}
		}
		dfs(0);
		printf("Case %d: %d\n",cse,cnt);
		for(i=0; i<n; i++)	pcd[i].clear();
		row.clear();	cse++;
	}
	return 0;
}

// This solution got TLE because time is 15! which is large for 5s
