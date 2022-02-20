#include<cstdio>
#include<vector>
using namespace std;

vector<int> primes;

int search(int st, int end, int n){
	if(st>end)
		return end;
	int m = (st+end)>>1;
	if(primes[m]==n)
		return m;
	else if(primes[m]>n)
		return search(st,m-1,n);
	else
		return search(m+1,end,n);
}

int main(){
	vector<bool> p = vector<bool>(1e6+100,true);
	p[0]=false;
	p[1]=false;
	for(int i=2; i*i<=1e6+100; i++)
		for(int j=2; i*j<1e6+100; j++)	
			p[i*j]=false;
	
	for(int i=0; i<1e6+100; i++)
		if(p[i])	
			primes.push_back(i);
	p.clear();
	int tc, x, y, idx, n;
	scanf("%d",&tc);
	n = primes.size();
	while(tc--){
		scanf("%d%d",&x,&y);
		idx = search(0,n,x)+1;
		if(y>=idx)
			printf("Chef\n");
		else
			printf("Divyam\n");
	}
	return 0;
}
