#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	int a, b, c;
	int *p1, *p2, *p3;
	printf("Ingrese un valor de a:\n");
	scanf("%d", &a);
	printf("Ingrese un valor de b:\n");
	scanf("%d", &b);
	c = a + b;
	printf("a + b = %d \n", c);
	p1 = &a;
	p2 = &b;
	printf("*p1 + *p2 = %d\n", *p1 + *p2);
	p3 = &c;
	printf("Dirección de a es %p\nDirección de b es %p\nY la de c es %p\n\n", p1, p2, p3);
	return 0;
}