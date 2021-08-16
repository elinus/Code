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

    cout << __FILE__ << " :: send message infinitely (close command :: 'end')\n";
    fd = open(FIFO_FILE, O_CREAT|O_WRONLY);
    strcpy(end, "end");
    while (true) {
        cout << "Enter string :: ";
        fgets(read_buffer, sizeof(read_buffer), stdin);
        int string_len = strlen(read_buffer);
        read_buffer[string_len - 1] = '\0';
        to_end = strcmp(read_buffer, end);

        write(fd, read_buffer, strlen(read_buffer));
        cout << "Sent string: " << read_buffer << ", len = " << strlen(read_buffer) << "\n";
        if (to_end == 0) {
            close(fd);
            break;
        }
    }
    return 0;
}


