#include<bits/stdc++.h>
using namespace std;

class B{
    public:
    virtual void fn(void)
    {
        cout<<"B::fn()"<<endl;
    }
    void gn()
    {
        cout<<"B::gn()"<<endl;
    }
};

class D:public B{
    public:
    void fn(void)
    {
        cout<<"D::fn()"<<endl;
    }
    void gn(void)
    {
        cout<<"D::gn()"<<endl;
    }
};


int main(){
    D d;
    B b;

    b.fn();
    b.gn();
    d.fn();
    d.gn();

    B &rd=d; // rd is reference , cannot be reassigned once intialized
    // rd is a reference to B, but actually refers to a D object
    rd.fn();
    rd.gn();

    B *pd=&d; // pd is a pointer, can be reassigned after initialization
    //pd is a pointer to B, but actually points to a D object
    pd->fn();
    pd->gn();
}