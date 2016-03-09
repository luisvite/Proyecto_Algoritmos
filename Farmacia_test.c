#include <stdlib.h>
#include <stdio.h>
#define MAX 30
/*Este documento es sin errores de compilacion nada mas es para ir testeando que todo valla bien hasta que  terminemos el proyecto*/
int indice;
typedef struct
{	
	char nombre_med[MAX];
	char grupo_med[MAX];
	float precio;
	char trata[MAX];
	char via_administracion[MAX];
}Medicamento;

int menu(char texto[], int n);

int main(){
	int num,o1,o2;
	Medicamento *med;
	
	printf("Cuantos medicamentos quiere registrar como maximo: ");
	scanf("%d",&num);
	
	med=(Medicamento *)malloc(num*sizeof(Medicamento));
	
	printf("\n");
	
	do{
		o1 = Menu("\t\t\tMENU PRINCIPAL\n1) Agregar\n2) Borrar\n3) Consultar\n4) Actualizar\n5) Salir\n\nSeleccione una opcion: ",5);
		switch(o1)
		{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
		}
	}while(o1!=5);
}

int Menu(char texto[], int n)
{
	int opcion;
	do
	{				
		printf("%s",texto);
		scanf("%d",&opcion);
		if (opcion<1 || opcion>n)
		{
			printf("Error:la opcion seleccionada no es valida");
		}
	}while(opcion<1 || opcion>n);
	return opcion;
}
