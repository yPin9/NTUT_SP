#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void open_shell(){
    system("/bin/sh");
}

int main(){
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);

    char buf[64];

    puts("==== Canary edition ====");

    printf("What's your name? ");
    read(0, buf, 63);
    buf[63] = 0;
    printf("Hello, ");
    printf(buf);
    printf("\n");

    printf("Leave a comment: ");
    read(0, buf, 200);

    puts("bye~");
    return 0;
}
