#include<iostream>
using namespace std;

int main(){
	bool f; 
	string c, s;
	int t, l;
	cin>>t;
	cin.ignore();
	while(t--){
		f=false;
		getline(cin, c);
		c = ' '+c;
		//cout<<c<<endl;
		for(int i=0; i<c.size();){
			if(c[i]==' '){
				i++;
				while(i<c.size() && c[i]!=' '){
					s+=c[i];
					i++;
				}
				//cout<<s<<endl;
				if(s=="not"){
					f=true;
					cout<<"Real Fancy\n";
					break;
				}
				else	s.erase();
			}
			else i++;
		}
		if(!f)	cout<<"regularly fancy\n";
		c.erase();
	}
		
	return 0;
}
