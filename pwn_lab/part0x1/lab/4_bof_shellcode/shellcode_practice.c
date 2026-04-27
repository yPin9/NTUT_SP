#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    char buf[256];
    printf("Your buffer is at %p\n", &buf);
    printf("Inject your shellcode: ");
    fflush(stdout);

    read(0, &buf[0], 1500);

    return 0;
}
