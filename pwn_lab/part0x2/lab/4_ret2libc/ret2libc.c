#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void init(){
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stdin, 0, 2, 0);
}

int main(){
    init();
    char buf[0x40];

    puts("==== ROP master ====");

    printf("Greet: ");
    read(0, buf, 0x40);
    printf(buf);
    printf("\n");

    printf("Pwn: ");
    read(0, buf, 0x100);

    puts("bye~");
    return 0;
}
