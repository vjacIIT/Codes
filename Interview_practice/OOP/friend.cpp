#include<cstdio>
using namespace std;

class A{
	int a;			// a is private
	public:
		A(int _a = 0): a(_a){}
		friend class B;
};

class B{
	int b;
	public:
		B(int _b=0): b(_b){}
		void show(A& x){
			printf("%d\n",x.a);			// accessing private data member
		}
};

class C{
	int c;
	public:
		C(int _c =0): c(_c){}
		friend int externalFun(C& mc);				// external function is friend
};

int externalFun(C& mc){					// can access private data members of C
	return mc.c;
}

int main(){
	C c;
	printf("%d\n",externalFun(c));
	return 0;
}
