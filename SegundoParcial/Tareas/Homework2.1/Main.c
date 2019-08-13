/*
    Juan Antonio Melendres Villa A00369017
    comentarios: la forma para ingresar los datos es de la siguiente manera:
        3
        hola
        --No
        civic
        --Yes
        ese
        --Yes

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char *palindromo, int lenght) {
    char *charPti = palindromo;
    char *reve = malloc(lenght + 1);
    for (int i = 0; i < lenght; i++) {
        reve[lenght - 1 - i] = charPti[i];
    }

    reve[lenght + 1] = '\0';
    for (int i = 0; i < lenght; i++) {
        if (reve[i] != charPti[i]) {
            return 1;
        }
    }
    free(reve);
    return 0;
}


int main() {
    int n;
    char pal[1024];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s",pal);
        if (is_palindrome(pal, strlen(pal))) {
            printf("--No\n");
        } 
        else {
            printf("--Yes\n");
        }
    }
    return 0;
}