#include<bits/stdc++.h>
using namespace std;

string st;
vector <string> str;
bool ar[500];
int nc, tc;

bool sur(char a, char b){
	if(b=='R'){
		if(a=='S')	return true;
		else if(a=='R')	return true;
		else 	return false;
	}
	else if(b=='P'){
		if(a=='R')	return true;
		else if(a=='P')	return true;
		else return false;
	}
	else{
		if(a=='P')	return true;
		else if(a=='S')	return true;
		else 	return false;
	}
}

bool awin(char a, char b){
	if(b=='R'){
		if(a=='S')	return true;
	}
	else if(b=='P'){
		if(a=='R')	return true;
	}
	else{
		if(a=='P')	return true;
	}
	return false;
}

bool survive(char a, int ind){
	int cind;
	for(int i=0; i<nc; i++){
		if(!ar[i]){
			cind = (int)ind%str[i].length();
			if(!sur(str[i][cind],a))	return false;
		}	
	}
	return true;
}

bool inc(int i,char c){
	for(int j=0; j<nc; j++){
		if(awin(str[j][i%str[j].length()],c) && !ar[j]){
			return true;
		}
	}
	return false;
}

int main(){
	int mxl,cnt;
	bool flg, flg1, flg2, flg3;
	scanf("%d",&tc);
	for(int z=1; z<=tc; z++){
		flg=false;	mxl=-1;	cnt=0;
		for(int i=0; i<500; i++)	ar[i]=false;
		scanf("%d",&nc);
		for(int i=0; i<nc; i++){
			cin>>st;
			str.push_back(st);
			if(mxl<(int)st.size()){
				mxl=st.size();
			}
		}
		st.clear();
		int i=0;
		while(i<3*mxl){
			flg1=false; flg2=false; flg3=false;
			if(survive('R',i) && inc(i,'R')){
				st+='R';
				flg1=true;
				for(int j=0; j<nc; j++){
					if(awin(str[j][i%str[j].length()],'R') && !ar[j]){
						ar[j]=true;
						cnt++;
					}
				}
				i++;
			}
			if(survive('P',i) && inc(i,'P')){
				st+='P';
				flg2=true;
				for(int j=0; j<nc; j++){
					if(awin(str[j][i%str[j].length()],'P') && !ar[j]){
						ar[j]=true;
						cnt++;	
					}
				}
				i++;
			}
			if(survive('S',i) && inc(i,'S')){
				st+='S';
				flg3=true;
				for(int j=0; j<nc; j++){
					if(awin(str[j][i%str[j].length()],'S') && !ar[j]){
						ar[j]=true;
						cnt++;
					}
				}
				i++;
			}
			if(!flg1 && survive('R',i)){
				st+='R';
				i++;
			}
			else if(!flg2 && survive('P',i)){
				st+='P';
				i++;
			}
			else if(!flg3 && survive('S',i)){
				st+='S';
				i++;
			}
			else if(cnt<nc){
				flg=true;
				break;
			}
			if(cnt>=nc)	break;
		}
		//cout<<st<<endl;
		printf("Case #%d: ",z);
		for(int i=0; i<nc; i++){
			if(!ar[i])	flg=true;
		}
		if(flg)	printf("IMPOSSIBLE\n");
		else cout<<st<<endl;
		st.clear();
		str.clear();
	}
	return 0;
}
