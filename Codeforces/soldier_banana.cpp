#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, w, k, m;
	scanf("%d%d%d", &k, &n, &w);
	m = (k*w*(w+1))/2 - n;
	if(m>0)	printf("%d\n", m);
	else 		printf("0\n");
	return 0;
}
