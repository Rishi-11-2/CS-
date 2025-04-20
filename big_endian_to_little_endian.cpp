/*
Overview:
This C++ program demonstrates how to convert a 32-bit integer between big-endian and little-endian byte orders. The program defines a function `swap_endian` that extracts each byte from the input integer, rearranges them in reverse order, and returns the result. The main function tests this conversion with example values and prints the results in hexadecimal format.
*/
#include<bits/stdc++.h>
/*
Include the standard C++ library header for commonly used functions and objects
*/

using namespace std;

int swap_endian(int val)
{
    int leftmost_byte;
    int left_middle_byte;
    int right_middle_byte;
    int rightmost_byte;
    /*
    We assume the number to be 32 bits:
    00000000 00000000 00000000 00000000  
      (b1)    (b2)    (b3)    (b4)
    What we are doing is:
    - First extract the leftmost 8 bits from the number.
    - Then extract the next 8 bits, then the next 8 bits, and finally the rightmost 8 bits.
    After all the bytes are extracted, we arrange these bytes in the reverse order:
      (b4)    (b3)    (b2)    (b1)
    This essentially means that we are reversing the endianness.
    */
    leftmost_byte=(val&0x000000FF)>>0; 
    /*
    Extract least significant byte
    */
    
    left_middle_byte=(val&0x0000FF00)>>8; 
    /*
    Extract the next byte
    */

    right_middle_byte=(val&0x00FF0000)>>16; 
    /*
    Extract the third byte
    */

    rightmost_byte=(val&0xFF000000)>>24; 
    /*
    Extract the most significant byte
    */

    leftmost_byte<<=24; 
    /*
    Move to most significant position
    */

    left_middle_byte<<=16; 
    /*
    Move to second most significant position
    */

    right_middle_byte<<=8; 
    /*
    Move to third most significant position
    */

    rightmost_byte<<=0; 
    /*
    Remain in least significant position
    */

    int ans=(leftmost_byte|rightmost_byte|left_middle_byte|right_middle_byte); 
    /*
    Combine all bytes to form the swapped integer
    */

    return ans;
}
int main()
{
    int big_endian=0x12345678; 
    /*
    Example value in big-endian
    */

    int little_endian=0x78563412; 
    /*
    Example value in little-endian
    */

    int result1=swap_endian(big_endian); 
    /*
    Convert big-endian to little-endian
    */
    int result2=swap_endian(little_endian); 
    /*
    Convert little-endian to big-endian
    */

    cout<<hex<<result1<<" "<<result2<<endl ; 
    /*
    Output results in hexadecimal
    */
}