/*
    Juan Antonio Melendres Villa A00369017
    comentarios: llenar matriz se le pasa el txt, el txt es de la siguiente manera:
                        1 2
                        3 4

*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

#define MAX 20
#define LINEA 1024

typedef struct matriz{
    int matriz[MAX][MAX];
    int filas;
    int columnas;
} matriz;

int llenarMatriz(matriz *mat) {
    FILE *stuff;
    char ch[LINEA] = {0};
    char *p, *ep;
    int fila = 0;

    if ((stuff = fopen ("test.txt", "r")) == NULL) {
        printf ("Archivo faltante...");
        exit (1);
    }
    while (fgets (ch, LINEA, stuff)) {
        int col = 0;
        p = ep = ch;
        errno = 0;
        while (*p && *p != '-' && (*p < '0' || *p > '9')) {
            p++;
        }
        while (errno == 0) {
            mat->matriz[fila][col++] = (int) strtol (p, &ep, 10);

            if (col == MAX) {
                fprintf (stderr, "llenarMatriz() error: Llego al tope de columnas.\n");
                break;
            }
            while (*ep && *ep != '-' && (*ep < '0' || *ep > '9')) {
                ep++;
            }
            if (*ep) {
                p = ep;
            }
            else {
                break;
            }
        }
        if (fila == 0) {
            mat->columnas = col;
        }
        if (col != mat->columnas) {
            fprintf (stderr, "llenarMatriz() error: Numero invalido de columnas, fila '%d'.\n", fila);
            fclose (stuff);
            return -1;
        }
        fila++;
        if (fila == MAX) {
            fprintf (stderr, "llenarMatriz() error: Llego al tope de filas.\n");
            break;
        }
    }
    fclose (stuff);
    mat->filas = fila;
    return 0;

}

matriz mult(matriz *mat1, matriz *mat2, matriz *res, int *ptr1, int *ptr2, int *ptr3) {
    int sum;
    for(int i = 0; i < mat1; i++){
        for(int j = 0; j < mat2; j++){
            for(int k = 0 ; k < mat2; k++) {
                sum+=*(ptr1+i*10+k)**(ptr2+k*10+j);
                *(ptr3+i*10+j) = sum;
                sum = 0;
            }
        }
    }
}

int main (void) {
    int fila1, col1, fila2, col2;

    printf("Ingrese el numero de filas de la Primera matriz: ");
    scanf("%d", &fila1);
    printf("Ingrese el numero de columnas de la Primera matriz: ");
    scanf("%d", &col1);

    printf("Ingrese el numero de filas de la Segunda matriz: ");
    scanf("%d", &fila2);
    printf("Ingrese el numero de columnas de la Segunda matriz: ");
    scanf("%d", &col2);

    if (col1 != fila2) {
        printf("No se puede realizar la multiplicacion de matrices: ");
        
    }
    else {
        matriz mat1[fila1][col1];
        matriz mat2[fila2][col2];
        matriz prod[fila1][col1];
        int *ptr1,*ptr2,*ptr3;
        ptr1 = mat1; ptr2 = mat2; ptr3 = prod;

        if (llenarMatriz (&mat1) == -1) {
            fprintf (stderr, "error: llenarMatriz.\n");
            return 1;
        }

        printf ("\nmatriz 1:\n");    
        for (int j = 0; j < fila1; j++) {
            char *pad = " [ "; \
            for (int k = 0; k < col1; k++) {
                printf ("%s%2d", pad, mat1[j][k]);
                pad = ", ";
            }
            printf (" ]\n");
        }
        putchar ('\n');

        if (llenarMatriz (&mat2) == -1) {
            fprintf (stderr, "error: llenarMatriz.\n");
            return 1;
        }

        printf ("\nmatriz 2:\n");    
        for (int j = 0; j < fila2; j++) {
            char *pad = " [ "; \
            for (int k = 0; k < col2; k++) {
                printf ("%s%2d", pad, mat2[j][k]);
                pad = ", ";
            }
            printf (" ]\n");
        }
        putchar ('\n');
        mult(mat1, mat2, prod, ptr1, ptr2, ptr3);

        printf("Product of both matrices is : \n");   
        for (int i = 0; i < fila1; i++) {
            for (int j = 0; j < col1; j++) {
                printf("%d ", *(*(prod + i) + j));
            }
            printf("\n");
        }
    }

    return 0;
}