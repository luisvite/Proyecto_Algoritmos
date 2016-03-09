#include <stdlib.h>
#include <stdio.h>
#define MAX 30

int indice;

typedef struct
{	
	char nombre_med[MAX];
	char grupo_med[MAX];
	float precio;
	char trata[MAX];
	char via_administracion[MAX];
}Medicamento;

/*Aqui seran declaradas los prototipos de nuestras funciones*/
int menu(char texto[], int n);
void captura_medicamento(Medicamento med);
int Borrar(int pos, Medicamento med);
int Buscar(char cap[], Medicamento med);
void Actualizar(int pos);
/*Este sera el main*/
int main()
{
	int opcion,t,pos,o2;
	indice = -1;
	Medicamento *med;
	char cap[MAX];

	printf("Cuantos medicamentos quieres registrar: ");
	scanf("%d",&t);

	med=(Medicamento *)malloc(t*sizeof(Medicamento));

	do{
		opcion = menu("1) Agregar\n2) Borrar\n3) Consultar\n 4)Actualizar\n 5)Salir\n",5);
		switch(opcion)
		{
			case 1:
				if (indice<t-1)
				{
					captura_medicamento(med[indice+1]);
				}
				else
					printf("Error, no hay espacio");
				break;
			case 2:
				printf("Ingrese el nombre del medicamento a borrar: ");
				fflush(stdin);
				gets(&cap);
				pos=Buscar(cap);
				if(pos!=-1)
				{
					Borrar(pos);
				}
				break;
			case 3:
				do
				{
					o2 = menu("\t\t\tConsulta\n 1)\n 2)\n 3)\n 4)\n 5)\n 6)\n 7)\n 8)Salir al menu principal",7);
					switch(o2)
					{
						case 1:
							break;
						case 2:
							break;
						case 3:
							break;
						case 4:
							break;
						case 5:
							break;
						case 6:
							break;
						case 7:
							break;
					}
				}while(opcion!8);
				break;
			case 4:
				printf("Cual es el nombre del medicamento a actualizar: ");
				fflush(stdin);
				gets(&cap)
				pos=Buscar(cap);
				if(pos!=-1)
				{
					Actualizar(pos);
				}
				break;
		}
	}while(opcion!=5)
}

/*Apartir de aqui ya declararemos nuestros metodos*/
int Menu(char texto[], int n)
{
	int opción,dato;
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
};

void captura_medicamento(Medicamento med)
{
	printf("Nombre del medicamento: ", );
	fflush(stdin);
	gets(&med.nombre_med);
	printf("Grupo al que pertenece: ", );
	fflush(stdin);
	gets(&med.grupo_med);
	printf("Precio: ", );
	scanf("%d",&med.precio)
	printf("Sintoma que trata: ", );
	fflush(stdin);
	gets(&med.trata);
	printf("Via de administracion: ", );
	fflush(stdin);
	gets(&med.via_administracion);

};

int Borrar(int pos)
{
	/*Faltan determinar parametros*/

	indice --;
};

int Buscar(char texto[],Medicamento med)
{
	int i;
	for(i=0;i<=indice;i++)
	{
		if(cap[]==med[i])
		{
			return i;
		}
	}
	else
		printf("No existe el dato");
	return (-1);
};

void Actualizar(int pos)
{
	captura_medicamento(med[pos]);
};
