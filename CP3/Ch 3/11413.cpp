#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

vector<int> v;
int n, m;

bool possible(int x){
	int mm, ccap;
	mm = m-1;
	ccap = x;
	for(int i=0; i<n; i++){
		ccap-=v[i];
		if(ccap<0){
			ccap=x-v[i];
			mm--;
		}
		if(mm<0 || x<v[i])
			return false;
	}
	return true;
}

int main(){
	int mmax, mmin, x;
	while(scanf("%d%d",&n,&m)!=EOF){
		v = vector<int>(n);
		mmax = -1;
		for(int i=0; i<n; i++){
			scanf("%d",&v[i]);
			mmax = max(mmax,v[i]);
		}
		if(m>=n)
			printf("%d\n",mmax);
		else{
			mmin = mmax;
			mmax = 0;
			for(int i=0; i<n; i++)
				mmax+=v[i];
			
			for(int i=0; i<50; i++){
				x = (mmax+mmin)/2;
				if(possible(x))
					mmax = x;
				else
					mmin = x;
			}
			printf("%d\n",mmax);
		}
		v.clear();
	}
	return 0;
}
