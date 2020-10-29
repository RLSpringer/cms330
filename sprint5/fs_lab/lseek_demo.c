#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>

int main(int argc, char *argv[]) {
    char buffer[10];
    int i;
    int iterations = 4;
    
    int fd = open("data.txt", O_RDONLY);
    assert(fd >= 0);

    for(i = 0; i < iterations; i++) {
        //vary last parameter between SEEK_SET, SEEK_CUR, and 
        //SEEK_END to see different behaviors
        int rc = lseek(fd, 10, SEEK_END);
        printf("offset %d\n", rc);
    
        //read 10 bytes & display them
        read(fd, buffer, sizeof(buffer));
        printf("contents: %s\n", buffer);
    }
    
    return 0;
}