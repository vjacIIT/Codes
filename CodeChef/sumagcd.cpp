// Given an array of elements split it into two (nonempty) parts such that sum of their GCD is maximum

#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int *ar,mx;
vector<int> vec;

int fGCD(int sm, int big){
	if(sm==0)	return big;
	return fGCD(big%sm,sm);
}

int big(int a, int b){
	int large;
	large = a>b ? a:b;
	return large;
}

int main(){
	int tc, gcd, ans, cnt, result1, result2, n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		ar = new int[n];
		for(int i=0; i<n; i++)	scanf("%d",ar+i);
		sort(ar,ar+n);
		cnt=1;		vec.push_back(ar[0]);
		for(int i=0; i<n-1; i++){
			if(ar[i]!=ar[i+1]){
				cnt++;							// no of ditinct elements
				vec.push_back(ar[i+1]);
			}
		}
		gcd=ar[0];
		for(int i=1; i<n-1; i++)	gcd=fGCD(gcd,ar[i]);		// gcd of first n-1 elments
		ans = gcd+ar[n-1];
		
		if(cnt==1)	printf("%d\n",ans);
		else if(cnt==2)	printf("%d\n",vec[0]+vec[1]);
		else{
			gcd=vec[0];
			for(int i=1; i<cnt-2; i++)	gcd=fGCD(gcd,vec[i]);			// gcd of first cnt-2 elements
			result1 = fGCD(gcd,vec[cnt-2]) + vec[cnt-1];			// last element as singleton
			result2 = vec[cnt-2]+fGCD(gcd,vec[cnt-1]);				// second last element as singleton
			ans = big(result1, result2);			
			printf("%d\n",ans);
		}
		delete []ar;
		vec.clear();
	}
	return 0;
}

// So the concept is that for maximum GCD, we always form set1 with only 1 element and rest in other
// Choice1 is take the maximum element as singleton and rest in other
// Choice2 is take the second maximum element as singleton and rest in other
// Also it can be proved that both maximum and the second maximum cannot come in same set
