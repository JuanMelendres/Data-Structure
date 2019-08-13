#include <stdio.h>

int add(int a, int b){
    return a + b;
}

int main(int argc, char const *argv[]) {
    /* My firt program in c */
    int x;
    int y;

    printf("Give me a number : ");
    scanf("%d", &x);

    printf("Give me a number : ");
    scanf("%d", &y);

    printf("Hello, World!! \n" );

    for (size_t i = 0; i < 10; i++) {
        /* code */
        if (i == 1) {
            printf("Hello %zu time \n", i);
        }
        else{
            printf("Hello %zu times \n", i);
        }
    }

    printf("The sum of %d + %d = %i\n", x, y ,add(x,y));

    return 0;
}
