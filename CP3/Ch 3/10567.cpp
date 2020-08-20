#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAX 1000000000

vector<vector<int>> v(200);

int search(int vn, int s, int e, int f){
	int m = (s+e)>>1;
	if(s>e)
		return MAX;
	if(v[vn][m]==f)
		return f;
	else if(v[vn][m]<f)
		return search(vn,m+1,e,f);
	else
		return min(v[vn][m],search(vn,s,m-1,f));
}

int main(){
	int q, a1, a2, f, len;
	char str[1000005];
	bool flg;
	scanf("%s",str);
	len = strlen(str);
	for(int i=0; i<len; i++)
		   v[str[i]-'A'].push_back(i);
	scanf("%d",&q);
	for(int j=0; j<q; j++){
		scanf("%s",str);
		len = strlen(str);
		flg=true;
		f=0;
		for(int i=0; i<len; i++){
			f = search(str[i]-'A',0,v[str[i]-'A'].size()-1,f);
			if(f!=MAX)
				f++;
			else{
				flg=false;
				break;
			}
			if(!i)
				a1=f-1;
		}
		if(!flg)
			printf("Not matched\n");
		else
			printf("Matched %d %d\n",a1,f-1);
	}
	return 0;
}
