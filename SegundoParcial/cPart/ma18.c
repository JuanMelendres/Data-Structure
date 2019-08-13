#include <stdio.h>
#include <string.h>

struct alumno{
    int mat; //matricula
    char nombre[40]; //nombre
};

int main(int argc, char const *argv[]) {

    struct alumno a1;
    struct alumno *pta;
    pta = &a1;

    a1.mat = 34;
    strcpy(a1.nombre, "Juan Eduardo");

    printf("%d\n", a1.mat);
    printf("%s\n", a1.nombre);

    printf("%d\n", pta->mat);
    printf("%s\n", pta->nombre);

    printf("%d\n", (*pta).mat);
    printf("%s\n", (*pta).nombre);

    printf("La variable a1 esta guardada en %p\n", &a1);
    printf("La estrcutura esata en %p\n", &a1);
    printf("La direccion donde esta pta es %p\n", &pta);
    printf("Lo guardado en pta es %p\n", pta);

    printf("El tamanio de la estructura es %ld \n", sizeof(struct alumno));

    return 0;
}
