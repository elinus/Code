#include <iostream>

using namespace std;

int main (int argc, char const *argv[])
{   
    /*
     * pointer to constant integer
     */
    const int x1 = 14;
    int const *ptr1 = &x1;
    //*ptr1 = 20; // error: read-only variable is not assignable
    const int y1 = 20;
    ptr1 = &y1;

    /*
     * constant pointer to int
     * */
    //const int x2 = 14;
    int x2 = 14; 
    int *const ptr2 = &x2; // error: invalid conversion from ‘const int*’ to ‘int*’
    *ptr2 = 20;
    //int y2 = 20;
    //ptr2 = &y2; // error: assignment of read-only variable ‘ptr2’

    /*
     * constant pointer to constant int
     * */
    const int x3 = 14;
    const int * const ptr3 = &x3;
    //*ptr3 = 20; // error: assignment of read-only location ‘*(const int*)ptr3’
    const int y3 = 20;
    //ptr3 = &y3; // error: assignment of read-only variable ‘ptr3’
    
    return 0;
}

