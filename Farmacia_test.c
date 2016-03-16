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
	int NumVentas;
	int Reserva;
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
void D_M_C(Medicamento med[]);
void D_M_B(Medicamento med[]);
void GuardaArrAux(Medicamento med[],float auxiliar[]);
void OrdenaMayMen(float auxiliar[]);
void MuestraOrden(float auxiliar[],Medicamento med[]);
void OrdenaMenMay(float auxiliar[]);

//Se define el main
int main()
{
	int num,o1,o2,o3,pos;
	float *auxiliar;
	Medicamento *med;
	
	float promedio;
	
	indice=-1;
	
	printf("Cuantos medicamentos quiere registrar como maximo: ");
	scanf("%d",&num);
	
	med=(Medicamento *)malloc(num*sizeof(Medicamento));
	auxiliar=(float *)malloc(num*sizeof(float));
	
	printf("\n");
	
	do
	{
		char cadena[MAX];
		
		o1 = Menu("\t\t\tMENU PRINCIPAL\n1) Agregar\n2) Borrar\n3) Consultar\n4) Actualizar\n5) Estadisticas \n6) Salir\n\nSeleccione una opcion: ",6);
		
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
						o2= Menu("\t\t\tConsulta\n1) Mostrar medicamentos por precio (mas caro-mas barato)\n2) Mostrar medicamentos por precio (mas barato-mas caro)\n3) Mostrar medicamentos por sintoma\n4) Mostrar todos los medicamentos\n5) Regresar al menu principal\n\nSeleccione una opcion: ",5);					
						switch(o2)
						{
							case 1:
								//Ordenar por precio(mas caro a mas barato)
								GuardaArrAux(med,auxiliar);//Guarda un arreglo auxiliar
								OrdenaMayMen(auxiliar);
								MuestraOrden(auxiliar,med);
								break;
							case 2:
								//Ordenar por precio(mas barato a mas caro)
								GuardaArrAux(med,auxiliar);//Guarda un arreglo auxiliar
								OrdenaMenMay(auxiliar);
								MuestraOrden(auxiliar,med);
								break;
							case 3:
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
							case 4:
								//Mostrar todos los medicamentos
								Muestra_Medicamentos(med);
								break;
						}
					}while(o2!=5);
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
			case 5:
				if(indice!=-1)
				{
					do
					{
						char sintoma[MAX];
						o3= Menu("\t\t\tEstadisticas\n1) Medicamento mas barato \n2) Medicamento mas caro \n3) Promedio de precios \n4) Medicamento menos vendido \n5) Medicamento mas vendido \n6) Promedio de ventas por medicamento \n7) Sintoma con mas ventas \n8) Sintoma con menos ventas \n9) Promedio de ventas por sintoma \n10) Medicamento con mas cantidad en reserva \n11) Medicamento con menos cantidad en reserva \n12) Promedio de medicamentos en reserva \n13) Salir \n\nSeleccione una opcion: ",13);					
						switch(o3)
						{
							case 1:
								D_M_B(med);//Determina medicamento barato
								break;
							case 2:
								D_M_C(med);//Determina medicamento caro
								break;
							case 3:
								//Promedio de precios por medicamento
								promedio=PromedioPrecios(med);
								printf("\nEl promedio de precios es: %2f \n",promedio);
								break;
							case 4:
								break;
							case 5:
								break;
							case 6:
								break;
							case 7:
								break;
							case 8:
								break;
							case 9:
								break;
							case 10:
								break;
							case 11:
								break;
							case 12:
								break;
						}
					}while(o3!=13);
				}
				else
				{
					printf("Error no hay ningun dato para poder mostrar alguna estadistica\n");
				}
				break;
		}
	}while(o1!=6);
	free(med);
	free(auxiliar);
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
	printf("Numero de ventas: ");
	scanf("%d",&m[indice].NumVentas);
	printf("Cantidad en reserva: ");
	scanf("%d",&m[indice].Reserva);
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
	printf("Numero de ventas: ");
	scanf("%d",&med.NumVentas);
	printf("Cantidad en reserva: ");
	scanf("%d",&med.Reserva);
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
			printf("\nNumero de ventas: %d",med[i].NumVentas);
			printf("\nCantidad en reserva: %d",med[i].Reserva);
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
		printf("\nNumero de ventas: %d",med[i].NumVentas);
		printf("\nCantidad en reserva: %d",med[i].Reserva);
		printf("\nSintoma que trata: %s", med[i].trata);
		printf("\nVia de administracion: %s \n\n",med[i].v_a);
	}
}

void D_M_C(Medicamento med[])
{
	float aux;
	int i;
	aux=med[0].precio;
	for(i=0;i<=indice;i++)
	{
		if(aux<med[i].precio)
		{
			aux=med[i].precio;
		}
	}
	for(i=0;i<=indice;i++)
	{
		if(aux==med[i].precio)
		{
			printf("\nNombre del medicamento: %s", med[i].nombre_med);
			printf("\nGrupo al que pertenece: %s", med[i].grupo_med);
			printf("\nPrecio: %2f",med[i].precio);
			printf("\nNumero de ventas: %d",med[i].NumVentas);
			printf("\nCantidad en reserva: %d",med[i].Reserva);
			printf("\nSintoma que trata: %s", med[i].trata);
			printf("\nVia de administracion: %s \n\n",med[i].v_a);
		}
	}
	
}

void D_M_B(Medicamento med[])
{
	float aux;
	int i;
	aux=med[0].precio;
	for(i=0;i<=indice;i++)
	{
		if(aux>med[i].precio)
		{
			aux=med[i].precio;
		}
	}
	for(i=0;i<=indice;i++)
	{
		if(aux==med[i].precio)
		{
			printf("\nNombre del medicamento: %s", med[i].nombre_med);
			printf("\nGrupo al que pertenece: %s", med[i].grupo_med);
			printf("\nPrecio: %2f",med[i].precio);
			printf("\nNumero de ventas: %d",med[i].NumVentas);
			printf("\nCantidad en reserva: %d",med[i].Reserva);
			printf("\nSintoma que trata: %s", med[i].trata);
			printf("\nVia de administracion: %s \n\n",med[i].v_a);
		}
	}
	
}

void GuardaArrAux(Medicamento med[],float auxiliar[])
{
	int i;
	for (i=0;i<=indice;i++)
	{
		auxiliar[i]=med[i].precio;
	}
}

void OrdenaMayMen(float auxiliar[])
{
	int i,j;
	float aux;
	for(i=0;i<indice;i++)
	{
		for(j=i+1;j<=indice;j++)
		{
			if(auxiliar[i]<auxiliar[j])
			{
				aux=auxiliar[i];
				auxiliar[i]=auxiliar[j];
				auxiliar[j]=aux;
			}
		}
	}
}

void MuestraOrden(float auxiliar[],Medicamento med[])
{
	int i,j;
	for(i=0;i<=indice;i++)
	{
		for(j=0;j<=indice;j++)
		{
			if(auxiliar[i]==med[j].precio)
			{
				printf("\nNombre del medicamento: %s", med[j].nombre_med);
				printf("\nGrupo al que pertenece: %s", med[j].grupo_med);
				printf("\nPrecio: %2f",med[j].precio);
				printf("\nNumero de ventas: %d",med[j].NumVentas);
			printf("\nCantidad en reserva: %d",med[j].Reserva);
				printf("\nSintoma que trata: %s", med[j].trata);
				printf("\nVia de administracion: %s \n\n",med[j].v_a);
			}
		}
	}
}

void OrdenaMenMay(float auxiliar[])
{
	int i,j;
	float aux;
	for(i=0;i<indice;i++)
	{
		for(j=i+1;j<=indice;j++)
		{
			if(auxiliar[i]>auxiliar[j])
			{
				aux=auxiliar[i];
				auxiliar[i]=auxiliar[j];
				auxiliar[j]=aux;
			}
		}
	}
}








