#include <iostream>
#include <sys/stat.h>
#include <cstring>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_FILE "/tmp/myfifo"

using namespace std;

int main (int argc, char *argv[]) {
    int fd, string_len;
    char read_buffer[100];
    char end[10];
    int to_end;
    int read_bytes;

    cout << "Client :: send message infinitely (close command :: 'end')\n";
    fd = open(FIFO_FILE, O_CREAT|O_RDWR);
    strcpy(end, "end");
    while (true) {
        cout << "[Client] Enter string :: ";
        fgets(read_buffer, sizeof(read_buffer), stdin);
        int string_len = strlen(read_buffer);
        read_buffer[string_len - 1] = '\0';
        to_end = strcmp(read_buffer, end);

        write(fd, read_buffer, strlen(read_buffer));
        cout << "[Client] Sent string: " << read_buffer << ", len = " << strlen(read_buffer) << "\n";
        sleep(2);
        if (to_end == 0) {
            close(fd);
            break;
        }
        read_bytes = read(fd, read_buffer, strlen(read_buffer));
        read_buffer[read_bytes] = '\0';
        cout << "[Client] Received string: " << read_buffer << ", len = " << strlen(read_buffer) << "\n";
    }
    return 0;
}


