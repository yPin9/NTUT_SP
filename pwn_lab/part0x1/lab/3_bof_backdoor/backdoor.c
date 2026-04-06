#include <stdio.h>
#include <stdlib.h>

void open_shell(){
    system("/bin/sh");
}

int main(){
    char buf[8];
    printf("Welcome backdoor lab~\n");
    gets(buf);
    return 0;
}