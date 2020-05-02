#include <iostream>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char *argv[]) {
    int pipe_fds1[2], pipe_fds2[2];
    char messages[2][20] = {"Hi", "Hello"};
    char read_buffer[20];

    int status1 = pipe(pipe_fds1);
    int status2 = pipe(pipe_fds2);
    if (status1 == -1 || status2 == -1) {
        std::cout << "Not able to create file!\n";
        return 1;
    }

    int pid = fork();

    if (pid == 0) {
        read(pipe_fds1[0], read_buffer, sizeof(read_buffer));
        std::cout << "(c)pid = " << getpid() << ", read buffer = " << read_buffer << "\n";
        std::cout << "(p)pid = " << getpid() << ", Write msg to pipe => " << messages[1] << "\n";
        write(pipe_fds2[1], messages[1], sizeof(messages[1]));
    } else {
        std::cout << "(p)pid = " << getpid() << ", Write msg to pipe => " << messages[0] << "\n";
        write(pipe_fds1[1], messages[0], sizeof(messages[0]));
        read(pipe_fds2[0], read_buffer, sizeof(read_buffer));
        std::cout << "(c)pid = " << getpid() << ", read buffer = " << read_buffer << "\n";
    }

    return 0;
}

