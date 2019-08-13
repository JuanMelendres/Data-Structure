#include <stdio.h>
#include <string.h>

int suma (int a, int b) {
    a++;
    b++;
    return a + b;
}

int suma2 (int *a, int *b) {
    (*a) ++;
    (*b) ++;
    return *a + *b;
}

void suma3 (int x, int y, int *z) {
    *z = x + y;
}

int main(int argc, char const *argv[]) {
    int x = 22;
    int y = 13;

    printf("La suma de %d + %d es %d\n", x, y, suma(x, y));

    printf("La suma de %d + %d es ", x, y);
    printf("%d\n", suma2(&x, &y));

    printf("La suma de %d + %d \n", x, y);

    int suma = 0;
    suma3(x, y, &suma);
    printf("La suma de %d mas %d es %d\n", x, y, suma);
    return 0;
}
