#include<iostream>
using namespace std;

int ar[4][5];	// 4 suits and 5 kind of cards, S, H, D, C
int cnt[4];		// counts the number of cards in each suit
bool stopped[4];	// checks if suit is stooped

void checkStopped(int i){
	if(ar[i][0]==1)	stopped[i]=true;
	else if(ar[i][1]==1 && cnt[i]>1)	stopped[i]=true;
	else if(ar[i][2]==1 && cnt[i]>2)	stopped[i]=true;
	return;
}

void putvalue(int i, char a){
	cnt[i]++;
	if(a=='A')	ar[i][0]=1;
	else if(a=='K')	ar[i][1]=1;
	else if(a=='Q')	ar[i][2]=1;
	else if(a=='J')	ar[i][3]=1;
	else ar[i][4]+=1;
	checkStopped(i);
	return;
}

void value(char a, char b){
	if(b=='S')	putvalue(0,a);
	else if(b=='H')	putvalue(1,a);
	else if(b=='D')	putvalue(2,a);
	else	putvalue(3,a);
	return;
}

int point1(int i){
	int count=4, p1=0;
	for(int j=0; j<4; j++){
		p1+=count*ar[i][j];
		count--;
	}
	return p1;
}

int point2(int i){
	if(ar[i][1]==1 && cnt[i]==1)	return 1;
	else return 0;
}

int point3(int i){
	if(ar[i][2]==1 && cnt[i]<=2)	return 1;	// only Q or 1 more
	else return 0;
}

int point4(int i){
	if((ar[i][3]==1) && cnt[i]<=3)	return 1;
	else return 0;
}

int point567(int i){
	if(cnt[i]==2)	return 1;
	else if(cnt[i]<=1) 	return 2;
	else return 0;
}

int cValue(int i, bool i2){
	int p1=0;
	p1 += point1(i);
	p1 -= point2(i);
	p1 -= point3(i);
	p1 -= point4(i);
	if(i2)	return p1;
	p1 += point567(i);
	return p1;
}

int main(){	
	for(int i=0; i<4; i++){
		cnt[i]=0;
		stopped[i]=false;
		for(int j=0; j<5; j++)	ar[i][j]=0;
	}
	int ct=1, val1=0, val2=0, mx;	
	char c[2];
	while(scanf("%s",c)!=EOF){
		value(c[0],c[1]);
		if(ct%13==0){
			for(int i=0; i<4; i++){
				val1+=cValue(i,false);
				val2+=cValue(i,true);		// without point 5, 6, 7
			}
			if(val1<14)	printf("PASS\n");
			else if(val2>=16 && stopped[0] && stopped[1] && stopped[2] && stopped[3])	printf("BID NO-TRUMP\n");
			else{
				mx=-1;
				for(int i=0; i<4; i++)	if(mx<cnt[i])	mx=cnt[i];
				for(int i=0; i<4; i++){
					if(cnt[i]==mx){
						mx=i;
						break;
					}
				}
				if(mx==0)	printf("BID S\n");
				else if(mx==1)	printf("BID H\n");
				else if(mx==2)	printf("BID D\n");
				else printf("BID C\n");
			}
			for(int i=0; i<4; i++){
				cnt[i]=0;
				stopped[i]=false;		
				for(int j=0; j<5; j++)	ar[i][j]=0;
			}
			val1=0;
			val2=0;
		}
		ct++;
	}
	return 0;
}
