#include<cstdio>
#include<iostream>
using namespace std;

int ar[18100];

int main(){
	bool flg;
	for(int i=0; i<18100; i++)	ar[i]=0;
	int no,nolights=0,tyme,hour,minute,second,mintyme=100000;
	while(scanf("%d",&no)!=EOF){
		if(no==0){
			flg=false;
			for(int i=1; i<18100; i++)	ar[i]=ar[i-1]+ar[i];
			for(int i=mintyme; i<18001; i++){
				if(ar[i]>=nolights){
					hour = i/3600;
					minute = (i/60)%60;
					second = i%60;
					printf("0%d:",hour);
					if(minute<10)	printf("0");
					printf("%d:",minute);
					if(second<10)	printf("0");
					printf("%d\n",second);
					flg=true;
					break;
				}
			}
			if(!flg)	printf("Signals fail to synchronise in 5 hours\n");
			for(int i=0; i<18100; i++)	ar[i]=0;
			nolights=0;
			mintyme=100000;
			scanf("%d",&no);
			if(no==0)	break;
			else{
				tyme=no-5;
				ar[0]++;	ar[tyme]--;
				no+=tyme+5;
				if(mintyme>no)	mintyme=no;
				while(no<18001){
					ar[no]++;	ar[no+tyme]--;
					no+=2*(tyme+5);
				}
				nolights++;
			}
		}
		else{
			tyme=no-5;
			ar[0]++;	ar[tyme]--;				// lazy propagation, 1 step ahead of required index
			no+=tyme+5;
			if(mintyme>no)	mintyme=no;
			while(no<18001){
				ar[no]++;	ar[no+tyme]--;		// we do not traverse to the whole array
				no+=2*(tyme+5);
			}
			nolights++;
		}
	}
	return 0;
}

// Improved via lazy propagation
