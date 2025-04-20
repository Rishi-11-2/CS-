/*
Overview:
This C++ program demonstrates the diamond problem and the use of virtual inheritance to resolve ambiguity in multiple inheritance. The class hierarchy includes a base class `A`, two derived classes `B1` and `B2` (both virtually inheriting from `A`), and a most-derived class `C` inheriting from both `B1` and `B2`. The constructors and destructors illustrate the order of construction/destruction, and the program shows how the most-derived class is responsible for initializing the virtual base class.
*/
#include<bits/stdc++.h>
/*
Include the standard C++ library header for commonly used functions and objects
*/
using namespace std;

/* Base class A with a single integer member 'a' */
class A{
    public:
    int a;
    /* Constructor for A, initializes 'a' with a default value of 5 */
    A(int  x=5):a(x){
        cout<<"A()"<<endl; /* Constructor for A */
    }
    /* Destructor for A */
    ~A()
    {
        cout<<"~A()"<<endl; /* Destructor for A */
    }
};
/* Derived class B1, virtually inheriting from A */
class B1: virtual  public A{
    public:
    int b1;
    /* Constructor for B1, initializes 'b1' and calls A's constructor */
    B1(int x=11,int y=5):A(x),b1(y){
        cout<<"B1()"<<endl; /* Constructor for B1 */
    }
    /* Destructor for B1 */
    ~B1()
    {
        cout<<"~B1()"<<endl; /* Destructor for B1 */
    }
};
/* Derived class B2, virtually inheriting from A */
class B2: virtual public A{
    public:
    int b2;
    /* Constructor for B2, initializes 'b2' and calls A's constructor */
    B2(int x=10,int z=5):A(x),b2(z){
        cout<<"B2()"<<endl; /* Constructor for B2 */
    }
    /* Destructor for B2 */
    ~B2()
    {
        cout<<"~B2()"<<endl; /* Destructor for B2 */
    }
};
/* Most-derived class C, inheriting from both B1 and B2 */
class C:public B1,B2{
    public:
    int c;
    /* Constructor for C, initializes 'c' and calls B1 and B2 constructors */
    C(int x1=12,int x2=14,int b1=21,int b2=22,int d=11):B1(x1,b1),B2(x2,b2),c(d)
    {
        cout<<"C()"<<endl; /* Constructor for C */
    }
    /* Destructor for C */
    ~C()
    {
        cout<<"~C()"<<endl; /* Destructor for C */
    }
    /*
    Important note: When using virtual base classes, the most-derived constructor (in this case, C) 
    is responsible for initializing the attributes of the virtual base class.
    */
    /* Member function to display all members */
    void display()
    {
        /* Display all members */
        cout<<a<<" "<<b1<<" "<<b2<<" "<<c<<endl;
    }
};

/* Main function */
int main()
{
    /* Create object of most-derived class */
    C c; 
    /* Display member values */
    c.display(); 
}