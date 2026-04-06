#include<stdio.h>

int cool_function() {
    int a = 5;
    printf("Here is cool function and the local variable a is %d\n",a);
    return 0;
}

int main() {
    int a = 100;
    printf("welcome to stack lab.\n");
    cool_function();
    printf("Back to main function and the local variable a is %d\n",a);
    return 0;
}