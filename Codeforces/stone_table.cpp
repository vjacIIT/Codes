#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, cnt=0;
	char *c, ch;
	scanf("%d", &n);
	c = new char[n];
	scanf("%s", c);
	ch = c[0];
	for(int i=1; i<n; i++){
		if(ch==c[i])	cnt++;
		else		ch=c[i];
	}
	printf("%d\n", cnt);
	return 0;
}
