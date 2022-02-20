#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Book{
    protected:
        string title;
        string author;
    public:
        Book(string t,string a){
            title=t;
            author=a;
        }
        virtual void display()=0;

};
// Note: We have a pure virtual function in Book class, which is inherited by the MyBook

class MyBook:public Book{				// public keyword is required
    int price;
    public:
        MyBook(string t, string a, int prc): Book(t,a) {
            price = prc;
        }
        void display(){                     // inherited from Book
            cout<<"Title: "<<title<<"\n";
            cout<<"Author: "<<author<<"\n";
            cout<<"Price: "<<price<<"\n";
            return;
        }
};

int main() {
    string title,author;
    int price;
    getline(cin,title);
    getline(cin,author);
    cin>>price;
    MyBook novel(title,author,price);
    novel.display();
    return 0;
}

