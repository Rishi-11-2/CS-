/*
Overview:
This C++ program demonstrates function overriding and the effects of object slicing and static binding in inheritance. The base class `B` and derived class `D` both define `fn` and `gn` methods. The program shows how function calls are resolved based on the type of reference or pointer, and illustrates that without virtual functions, base class references or pointers call base class methods, even when referring to derived objects.
*/

// Include the standard C++ library header for commonly used functions and objects
#include<bits/stdc++.h>

// Use the standard namespace to avoid prefixing standard library elements
using namespace std;

// Define the base class B with public member functions fn and gn
class B{
    public:
    // Define the fn function to print "B::fn()"
    void fn(void)
    {
        cout<<"B::fn()"<<endl;
    }
    // Define the gn function to print "B::gn()"
    void gn()
    {
        cout<<"B::gn()"<<endl;
    }
};

// Define the derived class D, inheriting from base class B
class D:public B{
    public:
    // Override the fn function to print "D::fn()"
    void fn(void)
    {
        cout<<"D::fn()"<<endl;
    }
    // Override the gn function to print "D::gn()"
    void gn(void)
    {
        cout<<"D::gn()"<<endl;
    }
};

// Define the main function as the program entry point
int main(){
    // Create an object d of type D
    D d;
    // Create an object b of type B
    B b;

    // Call the fn and gn functions on object b
    b.fn(); // Calls B::fn
    b.gn(); // Calls B::gn
    // Call the fn and gn functions on object d
    d.fn(); // Calls D::fn
    d.gn(); // Calls D::gn

    // Create a reference rd to object d, typed as B
    B &rd=d; // rd is reference , cannot be reassigned once intialized
    // Call the fn and gn functions on reference rd
    rd.fn(); // Calls B::fn due to static binding
    rd.gn(); // Calls B::gn due to static binding

    // Create a pointer pd to object d, typed as B
    B *pd=&d; // pd is a pointer, can be reassigned after initialization
    // Call the fn and gn functions on pointer pd
    pd->fn(); // Calls B::fn due to static binding
    pd->gn(); // Calls B::gn due to static binding
}