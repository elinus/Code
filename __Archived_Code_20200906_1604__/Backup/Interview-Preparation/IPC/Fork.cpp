#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main (int argc, char *argv[]) {
    int pid = getpid();
    cout << "pid before fork = " << pid << "\n";
    pid = fork();
    if (pid < 0) {
        cout << "fork() failed!\n";
    }
    if (pid == 0) {
        cout << "Child process details:\n";
        auto cpid = getpid();
        auto cppid = getppid();
        cout << "[child] pid = " << cpid << ", ppid = " << cppid << "\n";
    } else {
        cout << "Parent process details:\n";
        auto ppid = getpid();
        auto pppid = getppid();
        cout << "[parent] pid = " << ppid << ", ppid = " << pppid << "\n";
    }
    return 0;
}

