/*
Overview:
This C++ program checks the endianness (byte order) of the host machine and demonstrates how to interpret memory addresses and values. It uses a 16-bit integer to determine whether the system is big-endian or little-endian by inspecting the first byte in memory. The program also reads a hexadecimal memory address from user input, casts it to a pointer, and prints the value at that address.
*/
#include<bits/stdc++.h>
/*
Include the standard C++ library header for commonly used functions and objects
*/
using namespace std;

int main()
{
    uint16_t word=1; /* Initialize a 16-bit integer with value 1 */

    uint16_t *first_byte=(uint16_t*)(&word); /* Get the address of the first byte of 'word' */

    bool flag= !(*first_byte); /* If the first byte is zero, system is big-endian; else little-endian */
    cout<<first_byte<<endl; /* Print the address of the first byte */
    if(flag)
    {
        cout<<"Big Endian"<<endl; /* Output if system is big-endian */
    }
    else
    {
        cout<<"Little endian"<<endl; /* Output if system is little-endian */
    }

    uintptr_t address; /* Variable to hold a memory address */
    cin>>hex>>address; /* Read address from user in hexadecimal */
    cout<<hex<<address<<endl; /* Print the entered address */
    uint32_t* s=(uint32_t*)(address); /* Cast address to pointer to 32-bit integer */
    cout<<*s<<endl; /* Print the value at the given address */

}