/*
Overview:
This C++ program demonstrates deep copying in classes with dynamic memory allocation. The `Box` class manages an integer pointer and float value, and provides a custom copy constructor to ensure a deep copy of dynamically allocated memory. The main function tests the deep copy by modifying one object's data and showing that the copied object's data remains unchanged.
*/
#include<bits/stdc++.h>
/*
Include the standard C++ library header for commonly used functions and objects
*/
using namespace std;

class Box{
    public:
    int a;
    int *b;
    float c;
    Box(int av,int bv ,int cv)
    {
        a=av; /* Initialize integer member */
        b=new int(bv); /* Allocate and initialize integer pointer */
        c=(cv*(2.0))/(4.5); /* Calculate and assign float member */
    }
    ~Box()
    {
        /* Destructor should release allocated memory (not implemented here) */
    }

    Box(Box &bb)
    {
        /* Deep copy: allocate new memory and copy the value */
        a=bb.a;
        b= new int(*bb.b);
        c=bb.c;
    }
    void show()
    {
        /* Print the values of all members */
        cout<<a<<" "<<*b<<" "<<c<<endl;
    }
};

int main()
{
    Box b1(100,200,1); /* Create Box object */

    b1.show(); /* Show initial values */

    Box c=b1; /* Deep copy via copy constructor */
    *(b1.b)=2000; /* Modify the original object's pointer value */

    c.show(); /* Show copied object's values (should not be affected) */
    b1.show(); /* Show original object's values (should reflect change) */
}