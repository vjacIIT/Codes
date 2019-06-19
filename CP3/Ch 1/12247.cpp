#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	bool possible[53];
	for(int i=0; i<53; i++)	possible[i]=true;
	int ar[3],s,b,temp,temp2,ans;
	while(scanf("%d%d%d%d%d",&ar[0],&ar[1],&ar[2],&s,&b)){
		if(ar[0]==0)	break;
		for(int i=0; i<3; i++)	possible[ar[i]]=false;
		possible[s]=false;		possible[b]=false;
		sort(ar,ar+3);
		if(s>b){
			temp = s;
			s=b;
			b=temp;
		}
		temp=0;
		temp2=0;
		for(int i=0; i<3; i++){
			if(s>ar[i])	temp++;
			if(b>ar[i])	temp2++;
		}
		if(temp<=1){
			if(temp2==3){
				ans = ar[2]+1;
				while(ans<53 && !possible[ans])	ans++;
				if(ans==53)	printf("-1\n");
				else	printf("%d\n",ans);
			}
			else	printf("-1\n");	
		}
		else if(temp==2){
			ans = ar[1]+1;
			while(ans<53 && !possible[ans])	ans++;
			if(ans==53)	printf("-1\n");
			else	printf("%d\n",ans);
		}
		else{
			ans=1;
			while(ans<53 && !possible[ans])	ans++;
			if(ans==53)	printf("-1\n");
			else	printf("%d\n",ans);
		}
		for(int i=0; i<3; i++)	possible[ar[i]]=true;
		possible[s]=true;		possible[b]=true;
	}
	return 0;
}
