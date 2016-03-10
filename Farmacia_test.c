//Se definen las librerias a utilizar
/*Este documento es sin errores de compilacion nada mas es para ir testeando que todo valla bien hasta que  terminemos el proyecto*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX 30
//Se definen variables globales
int indice;
//se declara la estructura medicamento
typedef struct
{	
	char nombre_med[MAX];
	char grupo_med[MAX];
	float precio;
	char trata[MAX];
	char v_a[MAX];    /*Via de administracion*/
}Medicamento;
//Se empiezan a declarar metodos
int Menu(char texto[], int n);
int Lleno(int indice,int num);
int Vacio(int indice);
void Captura_Medicamento(Medicamento m[]);
int Buscar(char cadena[], Medicamento med[]);
void Borrar(int pos,Medicamento med[]);

//Se define el main
int main(){
	int num,o1,o2,pos;
	Medicamento *med;
	char cadena[MAX];
	
	indice=-1;
	
	printf("Cuantos medicamentos quiere registrar como maximo: ");
	scanf("%d",&num);
	
	med=(Medicamento *)malloc(num*sizeof(Medicamento));
	
	printf("\n");
	
	do{
		o1 = Menu("\t\t\tMENU PRINCIPAL\n1) Agregar\n2) Borrar\n3) Consultar\n4) Actualizar\n5) Salir\n\nSeleccione una opcion: ",5);
		switch(o1)
		{
			case 1:
				if(indice<num-1)
				{
					Captura_Medicamento(med);
				}
				else
				{
					printf("Error, no hay espacio\n");
				}
				break;
			case 2:
				if(indice!=-1)
				{
					printf("Ingrese el nombre del medicamento a borrar: ");
					fflush(stdin);
					gets(cadena);
					pos=Buscar(cadena, med);
					if(pos!=-1)
					{
						Borrar(pos,med);
					}
				}
				else
				{
					printf("Error no se encontro ninguna informacion\n");
				}
				break;
			case 3:
				break;
			case 4:
				break;
		}
	}while(o1!=5);
	free(med);
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

void Captura_Medicamento(Medicamento m[])
{
	indice ++;
	printf("Nombre del medicamento: ");
	fflush(stdin);
	gets(&m[indice].nombre_med);
	printf("Grupo al que pertenece: ");
	fflush(stdin);
	gets(&m[indice].grupo_med);
	printf("Precio: ");
	scanf("%d",&m[indice].precio);
	printf("Sintoma que trata: ");
	fflush(stdin);
	gets(&m[indice].trata);
	printf("Via de administracion: ");
	fflush(stdin);
	gets(&m[indice].v_a);
}

int Buscar(char cadena[], Medicamento med[])
{
	int i,ret;
	for(i=0;i<=indice;i++)
	{
		ret = strncmp(cadena, med[i].nombre_med, MAX);
		if(ret==0)
		{
			return i;
		}
	}
	printf("No existe el dato");
	return (-1);
}

void Borrar(int pos,Medicamento med[])
{
	med[pos]=med[indice];
	indice--;
}






































