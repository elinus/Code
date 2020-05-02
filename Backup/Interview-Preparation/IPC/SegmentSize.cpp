#include <iostream>
using namespace std;
int global_uninitialized;
int global_initialized = 20;
int main (int argc, char *argv[]) {
    static int static_uninitialized;
    static int static_initialized = 14;
    cout << "Hello World!" << endl;
    return 0;
}
/*
IPC$ size a*.out
   text	   data	    bss	    dec	    hex	filename
   2053	    640	    280	   2973	    b9d	a1.out
   2053	    640	    288	   2981	    ba5	a2.out
   2053	    644	    288	   2985	    ba9	a3.out
   2053	    644	    288	   2985	    ba9	a4.out
   2053	    648	    288	   2989	    bad	a5.out
*/
