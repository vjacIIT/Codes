#include<cstdio>
#include<iostream>
using namespace std;

int value(string s){
	return s=="front" ? 0:2;
}

string reverse(string s){
	return s=="front" ? "back":"front";
}

string printing(int a){
	if(a==0)	return "Blank";
	else	return to_string(a);
}

int main(){
	string s;
	int no,npages,**page,pno;
	while(scanf("%d",&no)!=EOF){
		if(no==0)	break;
		printf("Printing order for %d pages:\n",no);
		npages=no/4;
		if(no%4!=0)	npages=(no+4-no%4)/4;
		page = new int*[npages];
		for(int i=0; i<npages; i++) page[i]=new int[4];
		for(int i=0; i<npages; i++){
			for(int j=0; j<4; j++)	page[i][j]=0;
		}
		s="front";
		pno=0;
		for(int i=0; i<no; i++){
			if(i%2==0){			// second
				page[pno][value(s)+1]=i+1;
				s=reverse(s);
			}
			else{				// first
				page[pno][value(s)]=i+1;
				s=reverse(s);
				if(i+1<=2*npages)	pno++;
				else	pno--;
			}
			if(pno>=npages){
				s=reverse(s);
				pno--;
			}
		}
		if(no==1)	printf("Sheet 1, front: Blank, 1\n");
		else{
			for(int i=0; i<npages; i++){
				printf("Sheet %d, front: %s, %s\nSheet %d, back : %s, %s\n",i+1,printing(page[i][0]).c_str(),printing(page[i][1]).c_str(),i+1,printing(page[i][2]).c_str(),printing(page[i][3]).c_str());
			}
		}
		for(int i=0; i<npages; i++)	delete []page[i];
		delete []page;
	}
	return 0;
}
