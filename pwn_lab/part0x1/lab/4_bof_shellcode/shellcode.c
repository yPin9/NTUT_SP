#include <stdio.h>
#include <stdlib.h>

int main(){
    char buf[512];
    printf("The buf is at %p\n",&buf);
    printf(">");
    fflush(stdout);

    read(0,&buf[0],2025);

    return 0;
}