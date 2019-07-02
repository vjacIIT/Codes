#include<bits/stdc++.h>
using namespace std;

vector<pair<long int,long int>> v;
long int **dp;
bool **flg;

long int big(long int a, long int b){
	if(a>b)	return a;
	return b;
}

long int fmax(long int i, long int c){
	long int tp, dntp; 
	if(i<0)	return 0;
	if(c==0)	return 0;
	if(flg[i][c])	return dp[i][c];
	if(c<v[i].first)	dp[i][c]=fmax(i-1,c);
	else{
		dntp = fmax(i-1,c);
		tp = fmax(i-1,c-v[i].first)+v[i].second;
		dp[i][c]=big(dntp,tp); 
	}

	flg[i][c]=true;
	return dp[i][c];
}

int main(){
	long int c,n,w,p;
	cin>>c>>n;
	for(int i=0; i<n; i++){
		cin>>w>>p;
		v.push_back(make_pair(w,p));
	}
	sort(v.begin(),v.end());
	
	dp = new long int*[n];
	flg = new bool*[n];
	for(int i=0; i<n; i++){
		dp[i]=new long int[c+1];
		flg[i]=new bool[c+1];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<=c; j++){
			dp[i][j]=0;
			flg[i][j]=false;
		}
	}
	p = fmax(n-1,c);
	cout<<p<<endl;
	return 0;
}
