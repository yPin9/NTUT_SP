#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);

    char buf[256];

    puts("No backdoor this time. Show me your skill.");
    for (int i = 0; i < 8; i++) {
        printf("[%d]> ", i);
        ssize_t n = read(0, buf, 255);
        if (n <= 0) break;
        buf[n] = 0;
        printf(buf);
    }
    puts("Goodbye.");
    return 0;
}
