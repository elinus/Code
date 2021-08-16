#include <iostream>
#include <sys/stat.h>
#include <cstring>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_FILE "/tmp/myfifo"

using namespace std;

void reverse(char *str) {
    int first = 0, last;
    last = strlen(str) - 1;
    while (first < last) {
        char tmp = str[first];
        str[first] = str[last];
        str[last] = tmp;
        first++;
        last--;
    }
}

int main (int argc, char *argv[]) {
    int fd;
    char read_buffer[100];
    char end[10];
    int to_end;
    int read_bytes;

    if (mkfifo(FIFO_FILE, S_IFIFO|0664) == -1) {
        cout << "Error creating fifo!\n";
        return 1;
    }
    fd = open(FIFO_FILE, O_RDWR);
    strcpy(end, "end");
    while (true) {
        read_bytes = read(fd, read_buffer, sizeof(read_buffer));
        read_buffer[read_bytes] = '\0';
        cout << "[Server] read buff. = " << read_buffer << ", len = " << (int) strlen(read_buffer) << "\n";
        to_end = strcmp(read_buffer, end);
        if (to_end == 0) {
            close(fd);
            break;
        }
        reverse(read_buffer);
        cout << "[Server] reverse string = " << read_buffer << ", len = " << strlen(read_buffer) << "\n";
        write(fd, read_buffer, strlen(read_buffer));
        sleep(2);
    }
    return 0;
}


