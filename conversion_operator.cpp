#include<bits/stdc++.h>

using namespace std;

class Fraction{
    public:
    int den;
    int num;
    Fraction(int n,int d)
    {
        num=n;
        den=d;
    }
    // conversion operator
    operator float() const{
        return float((num)/(den*1.0));
    }

    operator int() const{
        return num;
    }
};

int main()
{
    Fraction f(20,30);
    float ff=f;
    int fff=f;
    cout<<ff<<" "<<fff<<endl;
}