#include<cstdio>
#include<vector>
using namespace std;

int main(){
	vector<vector<int>> v(1000005);			// stores index
	vector<int>	h;					// stores the numbers which appeared
	int n, q, k, no;
	while(scanf("%d%d",&n,&q)!=EOF){
		h = vector<int>(n);
		for(int i=0; i<n; i++){
			scanf("%d",&h[i]);
			v[h[i]].push_back(i+1);	
		}
		for(int i=0; i<q; i++){
			scanf("%d%d",&k,&no);
			if(k>v[no].size())	printf("0\n");
			else	printf("%d\n",v[no][k-1]);
		}
		for(int i=0; i<n; i++)	v[h[i]].clear();			// so that I do not need to clear whole v
		h.clear();
	}
	return 0;
}
