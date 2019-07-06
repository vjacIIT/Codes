#include<cstdio>
#include<iostream>
using namespace std;

int *tr;
string s;

int lt(int ti){
	return (ti<<1)+1;
}

int rt(int ti){
	return (ti<<1)+2;
}

int btr(int ti, int l, int r){
	int mid = (l+r)/2;
	if(l==r)	return s[l]-'0';
	tr[lt(ti)]=btr(lt(ti),l,mid);
	tr[rt(ti)]=btr(rt(ti),mid+1,r);
	return tr[lt(ti)]+tr[rt(ti)];
}

int inv(int i){
	return i==1 ? 0:1;
}

int update(char c, int i, int j, int l, int r, int ti){
	int mid=(l+r)/2;
	if(i>r || j<l)	return tr[ti];
	if(l==r){	
		if(c=='F')	tr[ti]=1;
		if(c=='E')	tr[ti]=0;
		if(c=='I')	tr[ti]=inv(tr[ti]);
		return tr[ti];
	}
	tr[lt(ti)]=update(c,i,j,l,mid,lt(ti));
	tr[rt(ti)]=update(c,i,j,mid+1,r,rt(ti));
	return tr[lt(ti)]+tr[rt(ti)];
}

int query(int i, int j, int l, int r, int ti){
	int mid=(l+r)/2, lsum, rsum;
	if(i>r || j<l)	return 0;
	if(l>=i && j>=r)	return tr[ti];
	lsum = query(i,j,l,mid,lt(ti));
	rsum = query(i,j,mid+1,r,rt(ti));
	return lsum+rsum;
}

int main(){
	char str[100], qt;
	int tc,l,t,q,st,end,ques;
	scanf("%d",&tc);
	for(int cse=1; cse<=tc; cse++){
		s.clear();	printf("Case %d:\n",cse);	ques=1;
		scanf("%d",&l);
		while(l--){
			scanf("%d\n%s\n",&t,str);
			while(t--)	s+=str;
		}
		l = s.length();
		tr = new int[4*l];
		tr[0]=btr(0,0,l-1);
		scanf("%d\n",&q);
		while(q--){	
			scanf("%c %d %d\n",&qt,&st,&end);
			if(qt!='S')	tr[0]=update(qt,st,end,0,l-1,0);
			else{	printf("Q%d: %d\n",ques,query(st,end,0,l-1,0));	ques++;	}
		}
		delete []tr;
	}

	return 0;
}

// TLE because we have not used lazy propagation
