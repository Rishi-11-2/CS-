/*
Overview:
This C++ program demonstrates the use of user-defined type conversion operators in a class. The `Fraction` class represents a mathematical fraction and defines conversion operators to convert a `Fraction` object to `float` and `int`. The main function shows how these conversions work by assigning a `Fraction` object to variables of type `float` and `int` and printing the results.
*/
#include<bits/stdc++.h>
/*
Include the standard C++ library header for commonly used functions and objects
*/

using namespace std;

class Fraction{
    public:
    int den;
    int num;
    Fraction(int n,int d)
    {
        num=n; /* Numerator initialization */
        den=d; /* Denominator initialization */
    }
    /* conversion operator */
    operator float() const{
        /* Converts the Fraction to a float by dividing numerator by denominator */
        return float((num)/(den*1.0));
    }

    operator int() const{
        /* Converts the Fraction to an int by returning only the numerator */
        return num;
    }
};

int main()
{
    Fraction f(20,30); /* Create a Fraction object with numerator=20, denominator=30 */
    float ff=f; /* Implicitly convert Fraction to float */
    int fff=f;  /* Implicitly convert Fraction to int */
    cout<<ff<<" "<<fff<<endl; /* Print the converted values */
}