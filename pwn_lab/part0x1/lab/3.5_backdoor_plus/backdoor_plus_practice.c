#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void open_shell(){
    system("/bin/sh");
}

int main(){
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    char id[20];
    char token[12];
    char message[256];
    puts("----Backdoor plus practice----");
    printf("id:");
    fflush(stdout);
    read(0, id, 20);
    printf("token:");
    read(0, token, 12);
    printf("Hello %s", &id);
    printf("your message:");
    read(0, message, 1500);
    puts("done~");
    return 0;
}
