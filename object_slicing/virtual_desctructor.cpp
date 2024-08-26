#include<bits/stdc++.h>
using namespace std;

class B{
    int b1;
    public:
    B(int x):b1(x)
    {
        cout<<"B()"<<endl;
    }
    virtual ~B() // declaring base destructor virtual
    {
        cout<<"~B()"<<endl;
    }

    virtual void display()
    {
        cout<<"B()"<<endl;
    }
};
/* defining the base destructor as private transform it into a polymorphic type
ensuring the invocation of the destructor corresponding to the suitable class type 
that the base pointer points to*/
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

int main()
{
    B *b=new D(2,4);
    b->display();

    delete b; // calls the destructor of B and not D as the destructor is not virtual
}
