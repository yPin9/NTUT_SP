#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void win(){
    system("/bin/sh");
}

int main(){
    char buf[16];
    printf("Backdoor practice lab~\n");
    printf("Give me your input: ");
    fflush(stdout);
    read(0, buf, 64);
    return 0;
}
