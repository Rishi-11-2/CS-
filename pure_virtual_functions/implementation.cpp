/*
Overview:
This C++ program demonstrates the concept of pure virtual functions and abstract classes using an employee management scenario. The code defines an abstract base class `Emp` with a pure virtual function `dispLeave()`, and then derives further abstract and concrete classes (`Permanent`, `Temporary`, and `Staff`). The program illustrates how pure virtual functions enforce implementation in derived classes and how abstract classes cannot be instantiated. The main function tests the leave functionality for different types of employees.
*/
#include<bits/stdc++.h>
// Include the standard C++ library header for commonly used functions and objects
using namespace std;

class Emp{ // abstract base class
    public:
    // Pure virtual function: enforces derived classes to implement dispLeave()
    virtual void dispLeave()=0; 
};

class Permanent:public Emp{ // abstract base class
    public:
    // Pure virtual function: Permanent is still abstract because dispLeave is not implemented here
    virtual void dispLeave()=0; 

    // Method specific to Permanent and its derived classes
    void permanent()
    {
        // Prints a message about permanent employees and company considerations
        cout<<"They are permanent , hence they are costly to company , we need ways to lay them off legally!!"<<endl;
    }
};

class Temporary: public Emp{
    public:
     // Implements the leave functionality for temporary employees
     void dispLeave()
    {
        cout<<"Temporary Employee going on a leave!!"<<endl;
    }
};

class Staff:public Permanent{
    public:
     // Implements the leave functionality for staff (a type of permanent employee)
     void dispLeave()
    {
        cout<<"Staff going on a leave!!!"<<endl;
    }
};

int main()
{
    // Attempting to declare an object of an abstract class will result in a compilation error
    // Permanent P;  

    // Create objects of concrete classes
    Temporary t;
    Staff s;

    // Test the leave functionality for different types of employees
    t.dispLeave(); // Calls dispLeave for Temporary employee
    s.dispLeave(); // Calls dispLeave for Staff (Permanent employee)

    // The permanent() method is not accessible for Temporary, as only Permanent and its derived classes have this method
    // t.permanent(); 

    // Call the permanent() method for Staff (inherited from Permanent)
    s.permanent(); 
}