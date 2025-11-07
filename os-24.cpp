#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[50] = "Hello Operating System\n";

    fd = open("sample.txt", O_RDWR | O_CREAT, 0777);

    write(fd, buffer, sizeof(buffer));
    lseek(fd, 0, 0);
    read(fd, buffer, sizeof(buffer));

    printf("File Content:\n%s\n", buffer);

    close(fd);
    return 0;
}

