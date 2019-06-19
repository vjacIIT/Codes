#include<cstdio>
#include<iostream>
using namespace std;

void resemble(string s1, string s2){
	int l = s1.length(), i;
	for(i=0; i<l; i++)	printf("%c",s1[i]);
	printf("-");	i=0;
	while(s1[i]==s2[i])	i++;
	for(; i<l; i++)	printf("%c",s2[i]);
	printf("\n");
	return;
}

int main(){
	string str1, str2;
	int n, *ph, no1, no2, cnt, cno=1;
	while(scanf("%d",&n)){
		if(n==0)	break;
		printf("Case %d:\n",cno);	cno++;
		ph = new int[n];	for(int i=0; i<n; i++)	scanf("%d",ph+i);
		cnt=0;
		while(cnt<n){
			no1=ph[cnt];	no2=-1;
			while(cnt<n-1 && ph[cnt]+1==ph[cnt+1]){	no2=ph[cnt+1];	cnt++;	}
			if(no2==-1)	printf("0%d\n",no1);
			else{
				printf("0");	str1=to_string(no1);	str2=to_string(no2);
				resemble(str1,str2);
				str1.clear();	str2.clear();
			}
			cnt++;
		}
		printf("\n");
		delete []ph;
	}
	return 0;
}
