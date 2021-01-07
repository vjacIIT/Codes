#include<cstdio>
#include<iostream>
using namespace std;

class base{
	public:
		virtual void print(){
			cout<<"Base class print\n";
		}
		void show(){
			cout<<"Base class show\n";
		}
};

class derived: public base{
	public:
		void print(){
			cout<<"Derived class print\n";
		}
		void show(){
			"derived class show\n";
		}
};

int main(){
	base *b;
	derived d;
	b = &d;
	b->print();
	b->show();
	return 0;
}
