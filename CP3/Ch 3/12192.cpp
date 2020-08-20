#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int r, c;
vector<vector<int>> v;
vector<vector<int>> va;

int search(int i,bool flg, int s, int e, int n){
	int m=(s+e)>>1;
	if(s>e){
		if(flg)								// greater than equal to
			return s;
		else
			return e;
	}
	if(va[i][m]==n){
		if(flg)
			return min(m,search(i,flg,s,m-1,n));
		else
			return max(m,search(i,flg,m+1,e,n)); 
	}
	else if(va[i][m]>n)
		return search(i,flg,s,m-1,n);
	else
		return search(i,flg,m+1,e,n);
}

int main(){
	int cnt, x1, y1, x2, y2, r1, c1, q, s, e, sz;
	while(scanf("%d%d",&r,&c)!=EOF){
		if(!r && !c)
			break;
		v = vector<vector<int>>(r,vector<int>(c));
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
				scanf("%d",&v[i][j]);
		
		cnt = r+c-1;
		va = vector<vector<int>>(cnt);
		x1 = r-1;		x2=x1;
		y1 = 0;			y2=y1;
		
		for(int i=0; i<cnt; i++){
			r1=0;	c1=0;
			while(x1+r1<=x2 && y1+c1<=y2){
				va[i].push_back(v[x1+r1][y1+c1]);
				r1++;
				c1++;
			}
			x1!=0 ? x1--:y1++;
			y2!=c-1 ? y2++:x2--;
		}
		
		scanf("%d",&q);
		for(int i=0; i<q; i++){
			sz=0;
			scanf("%d%d",&s,&e);
			for(int j=0; j<cnt; j++){
				r1=search(j,0,0,va[j].size()-1,e);
				c1=search(j,1,0,va[j].size()-1,s);
				sz = max(sz,r1-c1+1);
				//printf("%d %d\n",r1,c1);
			}
			printf("%d\n",sz);
		}
		printf("-\n");
	}
	return 0;
}
