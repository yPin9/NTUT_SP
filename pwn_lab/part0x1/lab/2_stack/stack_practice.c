#include<stdio.h>

int inner_function() {
    int y = 9;
    printf("Inside inner_function, the local variable y is %d\n", y);
    return y;
}

int outer_function() {
    int x = 7;
    printf("Inside outer_function, the local variable x is %d\n", x);
    inner_function();
    printf("Back to outer_function, x is still %d\n", x);
    return 0;
}

int main() {
    int n = 50;
    printf("welcome to stack practice.\n");
    outer_function();
    printf("Back to main, the local variable n is %d\n", n);
    return 0;
}
