#include <stdio.h>

int main(int argc, char const *argv[]) {
    // int arr[3];
    int arr2[2][2];

    // arr[0] = 1;
    // arr[1] = 2;
    // arr[2] = 18;

    arr2[0][0] = 1;
    arr2[0][1] = 38;
    arr2[1][0] = -5;
    arr2[1][1] = 348;

    //int *pti = arr;
    int *pti = (int *) arr2;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%5d\t %p", *pti, pti);
            pti++;
        }
        printf("\n");
    }

    //printf("%p\n", &);

    // printf("%p\n", arr);
    // printf("%p\n", pti);
    //
    // for (int i = 0; i < 3; i++) {
    //     printf("%d\n", *pti);
    //     pti++;
    // }
    //
    // printf("%d\n", *pti);

    // arr[122] = 97;
    // printf("la ps robada es %d\n", arr[122]);

    return 0;
}
