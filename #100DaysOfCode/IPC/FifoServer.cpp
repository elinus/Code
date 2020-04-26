#include <iostream>
#include <sys/stat.h>
#include <cstring>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_FILE "/tmp/myfifo"

using namespace std;

int main (int argc, char *argv[]) {
    int fd;
    char read_buffer[100];
    char end[10];
    int to_end;
    int read_bytes;

    if (mknod(FIFO_FILE, S_IFIFO|0664, 0) == -1) {
        cout << "Error creating fifo!\n";
        return 1;
    }
    fd = open(FIFO_FILE, O_RDONLY);
    strcpy(end, "end");
    while (true) {
        read_bytes = read(fd, read_buffer, sizeof(read_buffer));
        read_buffer[read_bytes] = '\0';
        cout << "read buff. = " << read_buffer << ", len = " << (int) strlen(read_buffer) << "\n";
        to_end = strcmp(read_buffer, end);
        if (to_end == 0) {
            close(fd);
            break;
        }
        sleep(2);
    }
    return 0;
}


