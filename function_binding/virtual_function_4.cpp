/*
Overview:
This C++ program demonstrates the use of virtual functions for achieving dynamic binding and the importance of virtual destructors in inheritance. The base class `B` declares a virtual function `fn` and a non-virtual function `gn`. The derived class `D` overrides both. The program shows how function calls are resolved at runtime when using virtual functions, and highlights the difference in destructor invocation when deleting objects via base class pointers.
*/

// Include the standard C++ library header for commonly used functions and objects
#include<bits/stdc++.h>
using namespace std;

// Define the base class B with a virtual function fn and a non-virtual function gn
class B{
    public:
    // Declare a virtual function fn to enable dynamic binding
    virtual void fn(void)
    {
        // Print a message indicating that B::fn is called
        cout<<"B::fn()"<<endl;
    }
    // Declare a non-virtual function gn
    void gn()
    {
        // Print a message indicating that B::gn is called
        cout<<"B::gn()"<<endl;
    }
};

// Define the derived class D that inherits from B
class D:public B{
    public:
    // Override the virtual function fn from the base class B
    void fn(void)
    {
        // Print a message indicating that D::fn is called
        cout<<"D::fn()"<<endl;
    }
    // Override the non-virtual function gn from the base class B
    void gn(void)
    {
        // Print a message indicating that D::gn is called
        cout<<"D::gn()"<<endl;
    }
};

// Define the main function
int main(){
    // Create an object d of class D
    D d;
    // Create an object b of class B
    B b;

    // Call the virtual function fn on object b (static binding)
    b.fn(); 
    // Call the non-virtual function gn on object b
    b.gn(); 
    // Call the virtual function fn on object d (overridden, dynamic binding)
    d.fn(); 
    // Call the non-virtual function gn on object d
    d.gn(); 

    // Create a reference rd to object d, which is of type B
    B &rd=d; 
    // Note that rd is a reference to B, but actually refers to a D object
    // Call the virtual function fn on reference rd (dynamic binding)
    rd.fn(); 
    // Call the non-virtual function gn on reference rd (not virtual)
    rd.gn(); 

    // Create a pointer pd to object d, which is of type B
    B *pd=&d; 
    // Note that pd is a pointer to B, but actually points to a D object
    // Call the virtual function fn on pointer pd (dynamic binding)
    pd->fn(); 
    // Call the non-virtual function gn on pointer pd (not virtual)
    pd->gn(); 
}