/*
Overview:
This C++ program demonstrates the use of virtual destructors in polymorphic class hierarchies to ensure proper resource cleanup. The base class `B` declares its destructor as virtual, allowing the derived class `D`'s destructor to be called when deleting an object through a base class pointer. This prevents resource leaks and ensures correct destruction order. The program highlights the difference from the object slicing scenario when destructors are not virtual.
*/

#include<bits/stdc++.h>
// Include the standard C++ library header for commonly used functions and objects

using namespace std;

// Base class B with a virtual destructor to enable polymorphism
class B{
    int b1; // Member variable b1
    public:
    // Constructor B with an integer parameter x
    B(int x):b1(x)
    {
        // Output constructor call for debugging
        cout<<"B()"<<endl;
    }
    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~B() 
    {
        // Output destructor call for debugging
        cout<<"~B()"<<endl;
    }

    // Virtual function display to demonstrate polymorphism
    virtual void display()
    {
        // Output class name for debugging
        cout<<"B()"<<endl;
    }
};

// Derived class D inheriting from base class B
class D:public B{
    int *p; // Pointer to an integer for dynamic memory allocation
    // inherited b1 from its parent class B
    public:
    // Constructor D with two integer parameters x and y
    D(int x,int y ):B(x), p(new int(y))
    {
        // Output constructor call for debugging
        cout<<"D()"<<endl;
    }
    // Destructor D to release dynamically allocated memory
    ~D()
    {
        // Output destructor call for debugging
        cout<<"~D()"<<endl;
    }
    // Overridden function display to demonstrate polymorphism
    void display()
    {
        // Output class name for debugging
        cout<<"D()"<<endl;
    }
};

int main()
{
    // Create a base pointer b pointing to a derived object D
    B *b=new D(2,4); 
    // Call the display function through the base pointer, invoking D's display
    b->display(); 

    // Delete the derived object through the base pointer, calling both D's and B's destructors
    delete b; 
}
