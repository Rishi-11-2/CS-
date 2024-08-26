#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    int a;
    A(int  x=5):a(x){
        cout<<"A()"<<endl;
    }
    ~A()
    {
        cout<<"~A()"<<endl;
    }
};
class B1: virtual  public A{
    public:
    int b1;
    B1(int x=11,int y=5):A(x),b1(y){
        cout<<"B1()"<<endl;
    }
    ~B1()
    {
        cout<<"~B1()"<<endl;
    }
};

class B2: virtual public A{
    public:
    int b2;
    B2(int x=10,int z=5):A(x),b2(z){
        cout<<"B2()"<<endl;
    }
    ~B2()
    {
        cout<<"~B2()"<<endl;
    }
};

class C:public B1,B2{
    public:
    int c;
    C(int x1=12,int x2=14,int b1=21,int b2=22,int d=11):B1(x1,b1),B2(x2,b2),c(d)
    {
        cout<<"C()"<<endl;
    }
    ~C()
    {
        cout<<"~C()"<<endl;
    }
    /* when you are using  a virtual base class, the most derived constructor(in this case that is D)
    is responsible for initializing the attributes of the virtual base class*/

    void display()
    {
        cout<<a<<" "<<b1<<" "<<b2<<" "<<c<<endl;
    }
};

int main()
{
    C c;
    c.display();
}