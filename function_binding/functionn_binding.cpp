#include<bits/stdc++.h>
using namespace std;

int sub(int x,int y,int z=1)
{
    return (x*z-y);
}
int sum(int x,int y,int z=1)
{
    return (x*z+y);
}

int main()
{
    // compile -time(static) function binding 
    cout<<sum(1,2)<<endl;
    cout<<sub(1,2)<<endl;

    int (*fp1)(int ,int,int)=&sum; // static function binding

    cout<<(*fp1)(6,2,1)<<endl;

    fp1=&sum; // static function binding

    cout<<(*fp1)(6,2,1)<<endl;


    int (*fp2)(int ,int ,int );
    int x;
    cin>>x;
    // dynamic function binding(run time function binding)
    if(!x)
    {
        fp2=&sum;
    }
    else
    {
        fp2=&sub;
    }
    /* performing dynamic binding using function pointers.
    so the matching a function call with an appropiate function definition 
    can be only done at runtime*/
    cout<<((*fp1)(6,2,(x*10)))<<endl;
}