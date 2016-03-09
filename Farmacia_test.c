#include <stdlib.h>
#include <stdio.h>
#define MAX 30

/*Este documento es sin errores de compilacion nada mas es para ir testeando que todo valla bien hasta que  terminemos el proyecto*/

int indice;

int menu(char texto[], int n);

int main(){
	int opcion;
		
	do{
		opcion = Menu("1) Agregar\n2) Borrar\n3) Consultar\n4) Actualizar\n5) Salir\n",5);
		/*Aqui todavia no capturo nada por lo que aun no estan disponibles las opciones para utilizar XD*/
	}while(opcion!=5);
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
