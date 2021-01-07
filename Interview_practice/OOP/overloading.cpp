#include<cstdio>
using namespace std;

int f(int a, int b){
	return a+b;
}

int f(int a){
	return a+3;
}

int main(){
	printf("%d %d\n",f(1),f(10,12));
	return 0;
}
