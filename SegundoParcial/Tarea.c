//tarea palindromo
#include <stdio.h>

int palindromo(char *inicio, char *fin) {
	while(inicio < fin) {
		if (*inicio != *fin) {
			return 0;
		}
		inicio++;
		fin--;
	}
	return 1;
}

int palindromoRecursivo(char *inicio, char *fin) {
	if (fin <= inicio) {
		return 1;
	}
	if (*inicio == *fin) {
		return palindromoRecursivo(++inicio, --fin); 
	}
	return 0;
}

int main(int argc, char const *argv[]) {
	char in[20];
	char *p1;
	char *p2;

	fgets(in, 20, stdin);

	p1 = p2 = in;

	while(*p2) {
		p2++;
	}
	p2-=2;

	if (palindromo(p1, p2)) {
		printf("Si es palindromo\n");
	}
	else {
		printf("No es palindromo\n");
	}

	if (palindromoRecursivo(p1, p2)) {
		printf("Si es palindromo\n");
	}
	else {
		printf("No es palindromo\n");
	}

	// printf("%s\n", in);
	// printf("p1 = %c\n", *p1);
	// printf("p2 = %c\n", *p2);

	return 0;
}