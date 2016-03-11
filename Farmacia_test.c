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
void Captura_Medicamento(Medicamento m[]);
int Buscar(char cadena[], Medicamento med[]);
void Borrar(int pos,Medicamento med[]);
void Actualizar(Medicamento med);
float PromedioPrecios(Medicamento med[]);
int BusquedaSintoma(char cadena[], Medicamento med[]);
void mostrarXsintoma(char cadena[], Medicamento med[]);
void Muestra_Medicamentos(Medicamento med[]);

//Se define el main
int main()
{
	int num,o1,o2,pos;
	Medicamento *med;
	
	float promedio;
	
	indice=-1;
	
	printf("Cuantos medicamentos quiere registrar como maximo: ");
	scanf("%d",&num);
	
	med=(Medicamento *)malloc(num*sizeof(Medicamento));
	
	printf("\n");
	
	do
	{
		char cadena[MAX];
		
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
				if(indice!=-1)
				{
					do
					{
						char sintoma[MAX];
						o2= Menu("\t\t\tConsulta\n1) Medicamento mas caro\n2) Medicamento mas barato\n3) Promedio de precios\n4) Mostrar medicamentos por precio (mas caro-mas barato)\n5) Mostrar medicamentos por precio (mas barato-mas caro)\n6) Mostrar medicamentos por sintoma\n7) Mostrar todos los medicamentos\n8) Regresar al menu principal\n\nSeleccione una opcion: ",8);					
						switch(o2)
						{
							case 1:
								//Medicamento mas caro
								Prinf("\nMedicamento más caro:%2f\n",med->Medicamento[j]= aux);
								break;
							case 2:
								//Medicamento mas barato
								Prinf("\nMedicamento más barato:%2f\n",med->Medicamento[k]= aux);
								break;
							case 3:
								//Promedio de precios
								promedio=PromedioPrecios(med);
								printf("\nEl promedio de precios es: %2f \n",promedio);
								break;
							case 4:
								//Ordenar por precio(mas caro)
								break;
							case 5:
								//Ordenar por precio(mas barato)
								break;
							case 6:
								//Mostrar medicamentos por sintoma
								printf("Ingrese el sintoma que trata el medicamento: ");
								fflush(stdin);
								gets(sintoma);
								pos=BusquedaSintoma(sintoma, med);
								if(pos!=-1)
								{			
									printf("\t\t\tMedicamentos que tratan el sintoma %s\n",sintoma);
									mostrarXsintoma(sintoma, med);
								}
								break;
							case 7:
								//Mostrar todos los medicamentos
								Muestra_Medicamentos(med);
								break;
						}
					}while(o2!=8);
				}
				else
				{
					printf("Error no hay ningun dato para poder realizar una consulta\n");
				}
				break;
			case 4:
				if (indice!=-1)
				{
					printf("Ingrese el nombre del medicamento a actualizar: ");
					fflush(stdin);
					gets(cadena);
					pos=Buscar(cadena, med);
					if(pos!=-1)
					{
						Actualizar(med[pos]);
					}
				}
				else
				{
					printf("Error, no se encontro nunguna informacion para actualizar.\n");
				}	
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
			printf("Error:la opcion seleccionada no es valida\n");
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
	scanf("%f",&m[indice].precio);
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

//del case1 del case 3

void Intercambio(Medicamento *med) {
   int i,j, aux;

   for(i=0; i< med->indice ; i++) {
      for(j=i+1; j<= med->indice; j++) {
         if (med->Medicamento[i] > med->Medicamento[j]){
            aux = med->Medicamento[i];
            med->Medicamento[i] = med->medicamento[j];
            med->Medicamento[j]= aux;
         }
      }
   }
}
//Del case 2 del case 3


void Intercambio(Medicamento *med) {
   int k,l, aux;

   for(k=0; k>med->indice ; k++) {
      for(l=k+1; l>= med->indice; l++) {
         if (med->Medicamento[k] < med->Medicamento[l]){
            aux = med->Medicamento[k];
            med->Medicamento[k] = med->medicamento[l];
            med->Medicamento[l]= aux;
         }
      }
   }
}
void Actualizar(Medicamento med)
{
	printf("Nombre del medicamento: ");
	fflush(stdin);
	gets(&med.nombre_med);
	printf("Grupo al que pertenece: ");
	fflush(stdin);
	gets(&med.grupo_med);
	printf("Precio: ");
	scanf("%f",&med.precio);
	printf("Sintoma que trata: ");
	fflush(stdin);
	gets(&med.trata);
	printf("Via de administracion: ");
	fflush(stdin);
	gets(&med.v_a);
}

float PromedioPrecios(Medicamento med[])
{
	int i,contador;
	float promedio=0;
	
	contador=0;
	
	for(i=0;i<=indice;i++)
	{
		promedio=promedio+med[i].precio;
		contador++;
	}
	
	promedio=promedio/contador;
	
	return(promedio);
}

int BusquedaSintoma(char cadena[], Medicamento med[])
{
	int i,ret;
	for(i=0;i<=indice;i++)
	{
		ret = strncmp(cadena, med[i].trata, MAX);
		if(ret==0)
		{
			return i;
		}
	}
	printf("No hay resgistrado algun medicamento que trate ese sintoma\n");
	return (-1);
}

void mostrarXsintoma(char cadena[], Medicamento med[])
{
	int i,ret;
	for(i=0;i<=indice;i++)
	{
		ret = strncmp(cadena, med[i].trata, MAX);
		if(ret==0)
		{
			printf("\nNombre del medicamento: %s", med[i].nombre_med);
			printf("\nGrupo al que pertenece: %s", med[i].grupo_med);
			printf("\nPrecio: %2f",med[i].precio);
			printf("\nSintoma que trata: %s", med[i].trata);
			printf("\nVia de administracion: %s \n\n",med[i].v_a);
		}
	}
}

void Muestra_Medicamentos(Medicamento med[])
{
	int i;
	for (i=0;i<=indice;i++)
	{
		printf("\nNombre del medicamento: %s", med[i].nombre_med);
		printf("\nGrupo al que pertenece: %s", med[i].grupo_med);
		printf("\nPrecio: %2f",med[i].precio);
		printf("\nSintoma que trata: %s", med[i].trata);
		printf("\nVia de administracion: %s \n\n",med[i].v_a);
	}
}









