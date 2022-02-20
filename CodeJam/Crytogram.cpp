#include<bits/stdc++.h>
using namespace std;

vector<int> pr;
vector<int> mul;
set<int> ps;
map<int,char> mp;

int fprime(int n){
	int val;
	for(auto it=ps.begin(); it!=ps.end(); it++){
		val = *it;
		if(n%val==0)	return val;	
	}
}

int main(){
	int tc;
	cin>>tc;
	string str, fstr;
	bool flg;
	int n,l,fp,sp,tp,frp,p1,p2;
	for(int z=1; z<=tc; z++){
		cin>>n>>l;
		for(int i=3; i<10000;){
			flg=false;
			for(int j=3; j*j<i+2;){
				if(i%j==0){
					flg=true;
					break;
				}
				j+=2;		
			}
			if(!flg)	pr.push_back(i);
			i+=2;
		}
		for(int j=0; j<l; j++){
			cin>>n;
			mul.push_back(n);
			for(int i=0; i<1228; i++){
				if(n%pr[i]==0){
					ps.insert(n/pr[i]);
					ps.insert(pr[i]);
				}
			}
		}
		n=0;
		for(auto it=ps.begin(); it!=ps.end(); it++){
			mp[*it]=char(65+n);
			n++;
		}
		n=0;
		flg=true;
		while(mul[n]==mul[n+1])	n++;
		fp = fprime(mul[n]);
		sp = mul[n]/fp;
		tp = fprime(mul[n+1]);
		frp = mul[n+1]/tp;
		if(n%2==0){
			if(n==0)	flg=false;
			if(tp==fp || tp==sp){
				if(tp==fp)	p1=sp;
				else	p1=fp;
				p2=tp;
			}
			else{
				if(frp==fp)	p1=sp;
				else	p1=fp;
				p2=frp;
			}
		}
		else{
			if(tp==fp || tp==sp){
				if(tp==fp){
					p1=fp;
					p2=sp;
				}
				else{
					p1=sp;
					p2=fp;
				}
			}
			else{
				if(frp==fp){
					p1=fp;
					p2=sp;
				}
				else{
					p1=sp;
					p2=fp;
				}
			}
		}
		n=(n+2)/2;		// no of terms which are same
		str=char(mp[p1]);
		str+=char(mp[p2]);
		for(int i=0; i<n; i++)	fstr+=str;
		cout<<"Case #"<<z<<": "<<fstr;
		fstr.clear();
		str.clear();
		n=n*2-1;			// now i need to start from n
		for(int i=n; i<l; i++){
			sw = mul[i];
			cout<<mp[sw/p2];
			p1=p2;
			p2=sw/p2;
		}
		cout<<"\n";
		pr.clear();
		mul.clear();
		ps.clear();
		mp.clear();
	}	
	return 0;
}
