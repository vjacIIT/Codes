#include<bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	bool flg;
	string n, n1, n2;
	cin>>tc;
	for(int i=1; i<=tc; i++){
		flg=false;
		cin>>n;
		for(int i=0; i<n.length(); i++){
			if(n[i]=='4'){
				n1+='3';
				n2+='1';
				flg=true;							
			}
			else{
				n1+=n[i];
				if(flg)	n2+='0';
			}
		}
		printf("Case #%d: ",i);
		cout<<n1<<" "<<n2<<endl;
		n1.clear();
		n2.clear();
		n.clear();
	}

	return 0;
}
