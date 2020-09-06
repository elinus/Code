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

    std::cout << "Write msg to pipe => " << messages[0] << "\n";
    write(pipe_fds[1], messages[0], sizeof(messages[0]));
    read(pipe_fds[0], read_buffer, sizeof(read_buffer));
    std::cout << "read buffer = " << read_buffer << "\n\n";
    
    std::cout << "Write msg to pipe => " << messages[1] << "\n";
    write(pipe_fds[1], messages[1], sizeof(messages[1]));
    read(pipe_fds[0], read_buffer, sizeof(read_buffer));
    std::cout << "read buffer = " << read_buffer << "\n";
    return 0;
}

