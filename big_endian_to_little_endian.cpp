#include<bits/stdc++.h>

using namespace std;


int swap_endian(int val)
{
    int leftmost_byte;
    int left_middle_byte;
    int right_middle_byte;
    int rightmost_byte;
    /* we assume the number to 32 bytes 
    so 00000000 00000000 00000000 00000000  
          (b1)    (b2)    (b3)    (b4)
    what we are doing is we first extract the leftmost 8 bytes from the number , after that we extract the next 8 bytes ,then the next 8 bytes
    and then the rigtmost 8bytes.  After all the bytes are extracted , what we do is we have to arrange these bytes in the reverse order
    what it means is that:
          (b4)    (b3)    (b2)    (b1)
    this will essentially means that we are reversing the endianess
    */
    leftmost_byte=(val&0x000000FF)>>0;
    
    left_middle_byte=(val&0x0000FF00)>>8;

    right_middle_byte=(val&0x00FF0000)>>16;

    rightmost_byte=(val&0xFF000000)>>24;

    leftmost_byte<<=24;

    left_middle_byte<<=16;

    right_middle_byte<<=8;

    rightmost_byte<<=0;

    int ans=(leftmost_byte|rightmost_byte|left_middle_byte|right_middle_byte);

    return ans;
}
int main()
{
    int big_endian=0x12345678;

    int little_endian=0x78563412;

    int result1=swap_endian(big_endian); 
    int result2=swap_endian(little_endian);

    cout<<hex<<result1<<" "<<result2<<endl ;
}