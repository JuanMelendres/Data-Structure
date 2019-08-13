#include <stdio.h>
#include <stdlib.h>

struct point2D {
	int x;
	int y;
};

int main(int argc, char const *argv[]) {
	// struct point2D p1 = {2,3};
	// struct point2D *pt1, *pt2;

	// pt1 = (struct point2D *) malloc(16); //malloc(sizeof( struct point2D)); como correguir si nos da un error (Struct point2D *)

	int *array = (int*) calloc(10, sizeof(int)); //malloc(sizeof(int) * 10)

	for (int i = 0; i < 10; ++i) {
		*(array + i) = i;
	}

	for (int i = 0; i < 10; ++i) {
		printf("%d\n", array[i]);
	}
	

	// printf("(%d, %d)\n", p1.x, p1.y);
	return 0;
}

//los arreglos comienan en 0 es por que guardo la base addres, y el desplazamiento es el indice