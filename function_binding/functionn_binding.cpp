/*
Overview:
This C++ program demonstrates static (compile-time) and dynamic (run-time) function binding using function pointers. It defines two functions, `sum` and `sub`, and shows how to assign them to function pointers for both static and dynamic binding. The program illustrates how function pointers can be used to select functions at runtime based on user input.

The program consists of two main sections:
1. Static function binding: This section demonstrates how to bind functions to function pointers at compile-time.
2. Dynamic function binding: This section shows how to bind functions to function pointers at runtime based on user input.
*/
#include<bits/stdc++.h>
/*
Include the standard C++ library header for commonly used functions and objects
*/
using namespace std;

/*
Define a function to calculate the subtraction of two numbers with an optional multiplier
*/
int sub(int x, int y, int z = 1)
{
    /*
    Return the result of the subtraction operation
    */
    return (x * z - y);
}

/*
Define a function to calculate the sum of two numbers with an optional multiplier
*/
int sum(int x, int y, int z = 1)
{
    /*
    Return the result of the sum operation
    */
    return (x * z + y);
}

int main()
{
    /*
    Compile-time (static) function binding
    */
    /*
    Call the sum function with default multiplier (1) and print the result
    */
    cout << sum(1, 2) << endl;
    /*
    Call the sub function with default multiplier (1) and print the result
    */
    cout << sub(1, 2) << endl;

    /*
    Declare a function pointer to point to a function with the same signature as sum and sub
    */
    int (*fp1)(int, int, int) = &sum; /*
    Static function binding
    */

    /*
    Call the function pointed to by fp1 with arguments 6, 2, and 1, and print the result
    */
    cout << (*fp1)(6, 2, 1) << endl;

    /*
    Reassign fp1 to point to the sum function again (static function binding)
    */
    fp1 = &sum;

    /*
    Call the function pointed to by fp1 with arguments 6, 2, and 1, and print the result
    */
    cout << (*fp1)(6, 2, 1) << endl;

    /*
    Declare another function pointer to point to a function with the same signature as sum and sub
    */
    int (*fp2)(int, int, int);

    /*
    Declare an integer variable to store user input
    */
    int x;

    /*
    Read user input and store it in x
    */
    cin >> x;

    /*
    Dynamic function binding (run-time function binding)
    */
    /*
    Based on the user input, assign fp2 to point to either the sum or sub function
    */
    if (!x)
    {
        fp2 = &sum;
    }
    else
    {
        fp2 = &sub;
    }

    /*
    Perform dynamic binding using function pointers
    */
    /*
    The matching of a function call with an appropriate function definition can only be done at runtime
    */
    cout << ((*fp1)(6, 2, (x * 10))) << endl;
}