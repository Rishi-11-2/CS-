#include<bits/stdc++.h>
using namespace std;

class Emp{ // abstract base class
    public:
    virtual void dispLeave()=0; // pure virtual function
};

class Permanent:public Emp{ // abstract base class
    public:
    virtual void dispLeave()=0; // pure virtual function 

    void permanent()
    {
        cout<<"They are permanent , hence they are costly to company , we need ways to lay them off legally!!"<<endl;
    }
};

class Temporary: public Emp{
    public:
     void dispLeave()
    {
        cout<<"Temporary Employee going on a leave!!"<<endl;
    }
};

class Staff:public Permanent{
    public:
     void dispLeave()
    {
        cout<<"Staff going on a leave!!!"<<endl;
    }
};

int main()
{
    // Permanent P;  // cannot declare object of abstract classes
    Temporary t;
    Staff s;
    t.dispLeave();
    s.dispLeave();
    // t.permanent();
    s.permanent();
}