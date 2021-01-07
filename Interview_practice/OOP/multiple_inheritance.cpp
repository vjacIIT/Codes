#include<cstdio>
#include<iostream>
using namespace std;

class Person{
	public:
		Person(){
			cout<<"Person called\n";
		}
};

class Student: virtual public Person{
	public:
		Student():Person(){
			cout<<"Student called\n";
		}
};

class Faculty: virtual public Person{
	public:
		Faculty():Person(){
			cout<<"Faculty called\n";
		}
};

class TA: public Student, public Faculty{
	public:
		TA():Student(), Faculty(){
			cout<<"TA called\n";
		}
};

int main(){
	TA t;
	return 0;
}
