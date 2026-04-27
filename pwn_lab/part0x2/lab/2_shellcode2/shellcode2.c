#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);

    char buf[512];

    printf("Tag: ");
    read(0, buf, 64);
    buf[63] = 0;
    printf("Welcome, ");
    printf(buf);
    printf("\n");

    printf("Code> ");
    read(0, buf, 2025);

    return 0;
}
