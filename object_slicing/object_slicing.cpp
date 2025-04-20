/*
Overview:
This C++ program demonstrates the concept of object slicing and the importance of virtual destructors in polymorphic class hierarchies. The base class `B` and derived class `D` are used to show what happens when a base class pointer points to a derived class object and the object is deleted. The program highlights that if the base class destructor is not virtual, only the base part is destroyed, leading to resource leaks (object slicing).
*/

// Include the standard C++ library header for commonly used functions and objects
#include<bits/stdc++.h>
using namespace std;

// Base class B with a private member variable b1 and public constructor, destructor, and display function
class B{
    int b1;
    public:
    // Constructor to initialize b1 with value x
    B(int x):b1(x)
    {
        cout<<"B()"<<endl;
    }
    // Destructor to clean up resources (not virtual in this example)
    ~B()
    {
        cout<<"~B()"<<endl;
    }

    // Virtual display function to demonstrate polymorphism
    virtual void display()
    {
        cout<<"B()"<<endl;
    }
};

// Derived class D inheriting from base class B with an additional private member variable p
class D:public B{
    int *p;
    // inherited b1 from its parent class B
    public:
    // Constructor to initialize b1 with value x and p with value y
    D(int x,int y ):B(x), p(new int(y))
    {
        cout<<"D()"<<endl;
    }
    // Destructor to clean up resources (not called in this example due to object slicing)
    ~D()
    {
        cout<<"~D()"<<endl;
    }
    // Overridden display function to demonstrate polymorphism
    void display()
    {
        cout<<"D()"<<endl;
    }
};

// Main function to demonstrate object slicing
int main()
{
    // Base pointer b points to a derived object D
    B *b=new D(2,4); 
    // Calls D::display due to virtual function
    b->display(); 

    // Only B's destructor is called, D's destructor is not (object slicing)
    delete b; 
}
