#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void backdoor(){
    system("/bin/sh");
    return;
}


int main() {
  setvbuf(stdin, 0, 2, 0);
  setvbuf(stdout, 0, 2, 0);
  char note[12];
  char input[24];
  printf("Leave a short note:");
  gets(note);
  printf("Your note:");
  printf(note);
  printf("\n");
  printf("Last input before bye:");
  read(0, input, 1500);
  puts(input);
  return 0;
}
