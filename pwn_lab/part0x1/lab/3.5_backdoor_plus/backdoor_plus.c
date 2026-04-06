#include <stdio.h>
#include <stdlib.h>

void open_shell(){
    system("/bin/sh");
}

int main(){
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stdout, 0, 2, 0);
    char name[16];
    char password[8];
    char key[512];
    puts("----Welcome backdoor plus----");
    printf("name:");
    fflush(stdout);
    read(0,name,16);
    printf("password:");
    read(0,password,8);
    printf("Hello %s",&name);
    printf("your key:");
    read(0,key,2025);
    puts("bye~");
    return 0;
}