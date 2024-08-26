#include<bits/stdc++.h>

using namespace std;

class B{
    public:
    int b1;
    virtual void fv1(void)
    {
        cout<<"B::fv1()"<<endl;
    }
    virtual void fv2(void)
    {
        cout<<"B::fv2()"<<endl;
    }
    void f1(void)
    {
        cout<<"B::f1()"<<endl;
    }
};

class D : public B{
    public:
    void fv1(void) // overriding fv1 in the base class
    {
        cout<<"D::fv1()"<<endl;
    }
    void f1(void )
    {
        cout<<"D::f2()"<<endl;
    }
};

int main()
{
    B * b= new B();

    b->fv1(); // dynamic binding
    b->fv2(); // dynamic binding
    b->f1(); // static binding

    b=new D();

    b->fv1(); // dynamic binding
    b->fv2(); // dynamic binding
    b->f1(); // static binding
}