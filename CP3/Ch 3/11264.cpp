#include<cstdio>
#include<vector>
using namespace std;

int main(){
	vector<long long> v;
	long long csum, lst;
	int t, n, cnt;
	scanf("%d",&t);
	while(t--){
		cnt = 1;
		csum = 0;
		scanf("%d",&n);
		v = vector<long long>(n);
		for(int i=0; i<n; i++)
			scanf("%lld", &v[i]);
		if(n<3){
			printf("%d\n",n);
			continue;
		}
		else{
			csum = v[0];
			lst = v[0];
			for(int i=1; i<n; i++){
				if(csum<v[i]){
					lst = v[i];
					csum += v[i];
					cnt++;
				}
				else{
					csum += (v[i] - lst);
					lst = v[i];					
				}
			}
			printf("%d\n",cnt);
			v.clear();
		}
	}
	return 0;
}
