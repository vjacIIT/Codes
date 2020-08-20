#include<cstdio>
#include<climits>
#include<vector>
using namespace std;

int gcd(int s, int b){
	if(s==0)	return b;
	if(b==0)	return s;
	return gcd(b%s,s);
}

bool isPrime(int n){
	if(n==2)	return true;
	for(int i=2; i*i<=n; i++){
		if(n%i==0)	return false;
	}
	return true;
}

int remove(int no, int ps1, int r1, int ps2, int r2){
	vector<int> v;
	int i=3;
	if(no%2==0){
		if(ps1%2==r1 && ps2%2==r2)	v.push_back(2);
		while(no%2==0)	no/=2;
	}
	for(; i*i<=no; i+=2){
		if(no%i==0){
			if(ps1%i==r1 && ps2%i==r2)	v.push_back(i);
			while(no%i==0)	no/=i;
		}
	}
	if(no>2)	v.push_back(no);
	i=v.size();		no=1;
	for(int j=0; j<i; j++)	no*=v[j];
	v.clear();
	return no;
}

int main(){
	vector<int> v;
	const int p = 31627;
	int tc, no1, no2, n, i, r1, r2;
	char str[10];
	scanf("%d",&tc);
	while(tc--){
		printf("1 31627\n");
		fflush(stdout);
		scanf("%d",&r1);
		no1 = 1000267129-r1;					// x^2 - x^2 % p
		printf("1 31643\n");
		fflush(stdout);
		scanf("%d",&r2);
		no2 = 1001279449-r2;
		n = gcd(no1,no2);
		n = remove(n, 1000267129, r1, 1001279449, r2);
		if(isPrime(n)){
			printf("2 %d\n",n);
			fflush(stdout);
			scanf("%s",str);
		}
		else{
			i=3;
			if(n%2==0){
				v.push_back(2);
				while(n%2==0)	n/=2;
			}
			for(; i*i<=n; i+=2){
				if(n%i==0){
					v.push_back(i);
					while(n%i==0)	n/=i;
				}
			}
			if(n>2)	v.push_back(n);
			i=v.size();
			for(int j=0; j<i; j++){
				printf("1 %d\n",v[j]);
				fflush(stdout);
				scanf("%d",&n);
				if(n==0){	
					printf("2 %d\n",v[j]);
					fflush(stdout);
					scanf("%s",str);	
					break;	
				}
			}
		}
		v.clear();
	}
	return 0; 
}

// Partial, got 2-subtasks
