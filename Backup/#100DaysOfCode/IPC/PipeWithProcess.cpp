#include <iostream>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char *argv[]) {
    int pipe_fds[2];
    char messages[2][20] = {"Hi", "Hello"};
    char read_buffer[20];
    int status = pipe(pipe_fds);
    if (status == -1) {
        std::cout << "Not able to create file!\n";
        return 1;
    }

    int pid = fork();

    if (pid == 0) {
        read(pipe_fds[0], read_buffer, sizeof(read_buffer));
        std::cout << "(c)pid = " << getpid() << ", read buffer = " << read_buffer << "\n";
        read(pipe_fds[0], read_buffer, sizeof(read_buffer));
        std::cout << "(c)pid = " << getpid() << ", read buffer = " << read_buffer << "\n";
    } else {
        std::cout << "(p)pid = " << getpid() << ", Write msg to pipe => " << messages[0] << "\n";
        write(pipe_fds[1], messages[0], sizeof(messages[0]));
        std::cout << "(p)pid = " << getpid() << ", Write msg to pipe => " << messages[1] << "\n";
        write(pipe_fds[1], messages[1], sizeof(messages[1]));
    }

    return 0;
}

