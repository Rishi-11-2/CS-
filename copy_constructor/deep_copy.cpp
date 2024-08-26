#include<bits/stdc++.h>
using namespace std;

class Box{
    public:
    int a;
    int *b;
    float c;
    Box(int av,int bv ,int cv)
    {
        a=av;
        b=new int(bv);
        c=(cv*(2.0))/(4.5);
    }
    ~Box()
    {
    }

    Box(Box &bb)
    {
        a=bb.a;
        b= new int(*bb.b);
        c=bb.c;
    }
    void show()
    {
        cout<<a<<" "<<*b<<" "<<c<<endl;
    }
};

int main()
{
    Box b1(100,200,1);

    b1.show();

    Box c=b1;
    *(b1.b)=2000;

    c.show();
    b1.show();
}