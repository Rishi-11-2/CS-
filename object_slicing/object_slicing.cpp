#include<bits/stdc++.h>
using namespace std;

class B{
    int b1;
    public:
    B(int x):b1(x)
    {
        cout<<"B()"<<endl;
    }
    ~B()
    {
        cout<<"~B()"<<endl;
    }

    virtual void display()
    {
        cout<<"B()"<<endl;
    }
};

class D:public B{
    int *p;
    // inherited b1 from its parent class B
    public:
    D(int x,int y ):B(x), p(new int(y))
    {
        cout<<"D()"<<endl;
    }
    ~D()
    {
        cout<<"~D()"<<endl;
    }
    void display()
    {
        cout<<"D()"<<endl;
    }
};
// if the base pointer b points to a derived object , when the base pointer is
//deleted , only the  base attribute of the pointer is deleted , the non-base attribute
// of the derived object is not deleted. this is known as object slicing
int main()
{
    B *b=new D(2,4);
    b->display();

    delete b; // calls the destructor of B and not D as the destructor is not virtual
}
