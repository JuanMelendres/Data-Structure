#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include "avlTree.h"

#define TECLA_ARRIBA 65
#define TECLA_ABAJO 66
#define ENTER 10

struct Node *root = NULL;

void menuPrincipal();
int menu(const char *titulo, const char *opciones[], int n);
void menuIngresar();
void menuEliminar();
void menuEditar();
void menuRecuperar();
void menuReporte();
void menuBuscar();
void menuHerramientas();

// void loadData(){

// }

// void saveData(){
	
// }

int getch(void) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

void gotoxy(int x,int y) {
	printf("%c[%d;%df",0x1B,y,x);
}

int main() {
	menuPrincipal();
	system("clear");
	return 0;
}

int menu(const char *titulo, const char *opciones[], int n) {
	int opSelecionada = 1;
	int tecla;
	//char ch;
	bool repite = true;
	do {
		//limpiar pantalla
		system("clear");
		//Desplazamiento
		gotoxy(0, 0);
		printf("Para desplazarse en el menú use la flecha arriba y abajo. Precione Enter para su opcion \n");
		//selecionar
		gotoxy(5, 5 + opSelecionada);
		printf("==> ");
		//titulo
		gotoxy(15, 4);
		printf("%s", titulo);
		//opciones
		for (int i = 0; i < n; ++i) {
			gotoxy(10, 6 + i);
			printf("%d. %s", i + 1, opciones[i]);
		}
		do {
			tecla = getch();
		} while(tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);
		switch(tecla) {
			case TECLA_ARRIBA:
				opSelecionada--;
				if (opSelecionada < 1) {
					opSelecionada = n;
				}
				break;
			case TECLA_ABAJO:
				opSelecionada++;
				if (opSelecionada > n) {
					opSelecionada = 1;
				}
				break;
			case ENTER:
				repite = false;
				break;
		}
	} while(repite);
	return opSelecionada;
}

void menuPrincipal() {
	bool repite = true;
	int op;
	//titulo y opciones
	const char *titulo = "Menú Princiapal";
	const char *opciones[] = {"Ingresar paciente", "Eliminar Paciente", "Editar paciente", "Recuperar paciente", "Reporte", "Buscar", "Herramientas administrativas", "Salir"};
	int n = 8; //numero de opciones
	do {
		op = menu(titulo, opciones, n);
		//alternativas
		switch(op) {
			case 1:
				menuIngresar();
				break;
			case 2:
				menuEliminar();
				break;
			case 3:
				menuEditar();
				break;
			case 4:
				menuRecuperar();
				break;
			case 5:
				menuReporte();
				break;
			case 6:
				menuBuscar();
				break;
			case 7:
				menuHerramientas();
				break;
			case 0:
				repite = false;
				break;
		}
	} while(!repite);
}

void menuIngresar() {
	bool repite = true;
	int op;
	//titulo y opciones
	const char *titulo = "Ingresar Paciente";
	const char *opciones[] = {"Ingresar nuevo paciente", "Regresar"};
	int n = 2; //numero de opciones
	int id;
	do {
		op = menu(titulo, opciones, n);
		switch(op) {
			case 1:
				gotoxy(5, 10);
				printf("Ingrese ID: ");
				scanf("%d", &id);
				//root = insert(root, id);
				printf("ID agregado!\n");
				break;
			case 2:
				repite = false;
				break;
		}
	} while(repite);
}

void menuEliminar() {
	bool repite = true;
	int op;
	//titulo y opciones
	const char *titulo = "Menú Eliminar";
	const char *opciones[] = {"Eliminar 1", "Eliminar 2", "Eliminar 3", "Regresar"};
	int n = 4; //numero de opciones
	do {
		op = menu(titulo, opciones, n);
		//alternativas
		switch(op) {
			case 1:
				printf("\n\t Eliminar 1\n");
				break;
			case 2:
				printf("\n\t Eliminar 3 \n");
				break;
			case 3:
				printf("\n\t Eliminar 3 \n");
				break;
			case 0:
				menuPrincipal();
				repite = false;
				break;
		}
	} while(repite);
}

void menuEditar() {
	bool repite = true;
	int op;
	//titulo y opciones
	const char *titulo = "Editar Paciente";
	const char *opciones[] = {"Editar paciente", "Regresar"};
	int n = 2; //numero de opciones
	int rfc;
	do {
		op = menu(titulo, opciones, n);
		switch(op) {
			case 1:
				gotoxy(5, 10);
				printf("Nuevo Medicamento");
				scanf("%d", &rfc);
				gotoxy(5, 12);
				printf("%d\n", rfc);
				break;
			case 0:
				menuPrincipal();
				repite = false;
				break;
		}
	} while(repite);
}

void menuRecuperar() {
	bool repite = true;
	int op;
	//titulo y opciones
	const char *titulo = "Recuperar Paciente";
	const char *opciones[] = {"Editar paciente", "Regresar"};
	int n = 2; //numero de opciones
	int rfc;
	do {
		op = menu(titulo, opciones, n);
		switch(op) {
			case 1:
				gotoxy(5, 10);
				printf("Recuperar paciente");
				break;
			case 0:
				repite = false;
				menuPrincipal();
				break;
		}
	} while(repite);
}

void menuReporte() {
	bool repite = true;
	int op;
	//titulo y opciones
	const char *titulo = "Reporte de los pacientes";
	const char *opciones[] = {"Reporte total", "Regresar"};
	int n = 2; //numero de opciones
	int rfc;
	do {
		op = menu(titulo, opciones, n);
		switch(op) {
			case 1:
				gotoxy(5, 10);
				printf("Reporte total se muestra en el archivo ...txt");
				break;
			case 0:
				menuPrincipal();
				repite = false;
				break;
		}
	} while(repite);
}

void menuBuscar() {
	bool repite = true;
	int op;
	//titulo y opciones
	const char *titulo = "Buscar Paciente";
	const char *opciones[] = {"look for an id", "Buscar 2", "Regresar"};
	int n = 3; //numero de opciones
	do {
		op = menu(titulo, opciones, n);
		//alternativas
		switch(op) {
			case 1:
				gotoxy(5, 10);
				printf("\n\tlook for an id\n");
				break;
			case 2:
				gotoxy(5, 10);
				printf("\n\tLook for a String in the other fields\n");
				break;
			case 0:
				menuPrincipal();
				repite = false;
				break;
		}
	} while(repite);
}

void menuHerramientas() {
	bool repite = true;
	int op;
	//titulo y opciones
	const char *titulo = "Herramientas administrativas";
	const char *opciones[] = {"Guardar txt", "Cargar nuevo txt", "Regresar"};
	int n = 3; //numero de opciones
	do {
		op = menu(titulo, opciones, n);
		//alternativas
		switch(op) {
			case 1:
				gotoxy(5, 10);
				printf("\nGuardar txt\n");
				break;
			case 2:
				printf("\n\tCargar nuevo txt\n");
				break;
			case 3:
				printf("\n\tRegresar\n");
				break;
			case 0:
				repite = false;
				menuPrincipal();
				break;
		}
	} while(repite);
}