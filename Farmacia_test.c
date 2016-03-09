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
	char v_a[MAX];    /*Via de administracion*/
}Medicamento;

int menu(char texto[], int n);
void captura_medicamento(Medicamento m);

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
				if(indice<num)  //Aqui hay que revisar porque se supone que es num-1 pero marca un error si unicamente se quiere registrar un medicamento
				{
					captura_medicamento(med[indice+1]);
				}
				else
					printf("Error, no hay espacio");
				break;
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
		}
	}while(o1!=5);
	free(o1);
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

void captura_medicamento(Medicamento m)
{
	indice ++;
	printf("Nombre del medicamento: ");
	fflush(stdin);
	gets(&m.nombre_med);
	printf("Grupo al que pertenece: ");
	fflush(stdin);
	gets(&m.grupo_med);
	printf("Precio: ");
	scanf("%d",&m.precio);
	printf("Sintoma que trata: ");
	fflush(stdin);
	gets(&m.trata);
	printf("Via de administracion: ");
	fflush(stdin);
	gets(&m.v_a);
}







































