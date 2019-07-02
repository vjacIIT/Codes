#include<iostream>
#include<limits.h>
using namespace std;

int n, **d, **dp;
int allVis;

int tsp(int ind, int mask){
	if(mask==allVis)	return d[ind][0];
	if(dp[ind][mask]!=-1)	return dp[ind][mask];
	int min = INT_MAX, min2;
	for(int i=0; i<n; i++){
		if((mask&(1<<i))==0){			// i'th bit is zero means it is not visited
			min2=d[ind][i]+tsp(i,mask|(1<<i));
			min = (min2<min) ? min2:min;
		}
	}
	dp[ind][mask]=min;
	return min;
}

int main(){
	int tc,min;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		n++;
		allVis=(1<<n)-1;
		d = new int*[n];
		dp = new int*[n];
		for(int i=0; i<n; i++){
			d[i]=new int[n];
			dp[i]=new int[1<<n];
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<(1<<n); j++)	dp[i][j]=-1;
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(i!=j)	scanf("%d",&d[i][j]);
				else	d[i][j]=0;
			}
		}
		min = tsp(0,1);
		printf("%d\n",min);
		for(int i=0; i<n; i++)	delete []d[i];
		delete []d;
	}
	return 0;
}

// This program uses bitmask to store the visited cities
// Time complexity is O(n^2.2^n)
