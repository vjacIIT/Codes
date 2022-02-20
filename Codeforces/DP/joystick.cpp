#include<iostream>
using namespace std;

int les(int a, int b){
	if(a<b)	return a;
	return b;
}

int big(int a, int b){
	if(a>b)	return a;
	return b;
}

int main(){
	int c1, c2, l, b, cnt=0;	// c1 takes the lesser value c2 takes the bigger value
	cin>>c1>>c2;
	while(true){
		if(c1==0 || c2==0)	break;
		else if(c1==1 && c2==1)	break;
		else{
			l = les(c1,c2);
			b = big(c1,c2);
			l+=1;
			b-=2;
			c1=l;
			c2=b;
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
