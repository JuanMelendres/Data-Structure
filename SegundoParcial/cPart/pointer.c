
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a = 10; //45
    int *pti;
    char *ptc;

    pti = &a;
    ptc = (char *) &a;

    printf("%p\n", &a);
    printf("%p\n", pti);
    printf("%d\n", *pti);

    printf("pti is store at %p\n", &pti);
    printf("The size of the pointer to int is %d \n", (int) sizeof(pti));
    printf("the size of a char is %d\n", (int) sizeof(char));
    printf("el contenido del pointer a char vale %c\n", *ptc);
    ptc++;
    * ptc = 1;
    printf("el contenido del pointer a char vale %c\n", *ptc);
    printf("###### ##### %d\n", *pti);

    return 0;
}
