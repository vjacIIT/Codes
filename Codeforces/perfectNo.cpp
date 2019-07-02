#include<iostream>
#include<vector>
using namespace std;

int sumDigits(int a){
	int sum=0;
	while(a!=0){
		sum+=a%10;
		a=a/10;
	}
	return sum;
}

int main(){
	int cnt=1, i=9, k;
	vector<int> v(10000,0);
	v[0]=19;
	while(cnt<10000){
		if(sumDigits(v[cnt-1]+i)!=10)	i+=9;
		else{
			v[cnt]=v[cnt-1]+i;
			cnt++;
			i=9;
		}
	}
	cin>>k;
	cout<<v[k-1]<<endl;
	return 0;
}
