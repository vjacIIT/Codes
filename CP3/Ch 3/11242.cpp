#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

#define loop(i,n)	for(int i=0; i<n; i++)
#define mp	make_pair
#define pb 	push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<float> vf;
typedef pair<int,int> ii;
typedef vector<ii>	vii;

int main(){
	vi v1, v2;
	vd d;
	double ft, ans;
	char str[50];
	int f, r, l;
	while(fgets(str,20,stdin)){
		if(!strcmp(str,"0\n"))	break;
		sscanf(str,"%d %d",&f,&r);
		ans=0;
		v1=vi(f);	v2=vi(r);
		loop(i,f)	scanf("%d",&v1[i]);
		loop(i,r)	scanf("%d",&v2[i]);
		loop(i,r){
			loop(j,f){
				ft=(1.0*(double)v2[i])/v1[j];
				d.pb(ft);
			}
		}
		sort(d.begin(),d.end());		l=d.size();
		loop(i,l-1){
			ft=d[i+1]/d[i];
			if(ft>ans)	ans=ft;
		}
		printf("%0.2f\n",ans);
		v1.clear();	v2.clear();	d.clear();
		scanf("\n");
	}
	return 0;
}
