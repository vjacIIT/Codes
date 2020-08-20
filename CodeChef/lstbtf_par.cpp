#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

// Partial soltution with no understanding of how to solve
// Applied brute force

vector<int> v;

bool nozeros(int ndigits,string n){
	for(int i=0; i<ndigits; i++){
		if(n[i]=='0')
			return false;
	}
	return true;
}

int search(int s, int e, int n){
	int  m=(s+e)>>1;
	if(s>e)
		return e;
	if(v[m]==n)
		return m;
	else if(v[m]>n)
		return search(s,m-1,n);
	else
		return search(m+1,e,n);
}

bool search2(int s, int e, int n){
	int  m=(s+e)>>1;
	if(s>e)
		return false;
	if(v[m]==n)
		return true;
	else if(v[m]>n)
		return search2(s,m-1,n);
	else
		return search2(m+1,e,n);
}

int sum(int ndigits,string n){
	int s=0;
	for(int i=0; i<ndigits; i++){
		s += (n[i]-'0')*(n[i]-'0');
	}
	return s;
}

int square(int n){
	return search(0,999,n);
}

int square2(int n){
	return search2(0,999,n);
}

void inc(int ndigits,string &s){
	int cry=1;
	int n;
	for(int i=ndigits-1; i>=0; i--){
		n=(s[i]-'0')+cry;
		s[i]=to_string(n)[0];
	//	printf("%d  %c",n,s[i]);
		if(n==10)
			cry=1;
		else
			return;
	}
	return;
}

int main(){
	vector<string> ans(1000000);
	int f, tc, sum;
	for(int i=1; i<1000; i++)
		v.push_back(i*i);
	for(int i=1; i<1000; i++){
		f = square(i);
		if(v[f]==i){
			string no1="";
			for(int j=0; j<i; j++)
				no1+='1';
			ans[i]=no1;
		}
		else{
			f++;
			string no="1";
			for(int k=1; k<i; k++)
				no+='1';
			sum=i;
			for(int j=0; j<1000; j++){
				if(nozeros(i,no) && square2(sum(i,no))){
					ans[i]=no;
					break;
				}
				inc(i,no);
			}	
		}
	}
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&f);
		printf("%s\n",ans[f].c_str());
	}
}
