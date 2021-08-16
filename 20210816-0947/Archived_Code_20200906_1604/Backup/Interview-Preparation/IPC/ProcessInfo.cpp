#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main (int argc, char *argv[]) {
    int pid, ppid;
    pid = getpid();
    ppid = getppid();
    
    cout << "pid = " << pid << ", ppid = " << ppid << "\n";
    
    system("ps -ef");
    return 0;
}

