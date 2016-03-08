#include <stdlib.h>
#include <stdio.h>
#define MAX 30

int indice;

typedef struct{
	
	char nombre_med[];
	char grupo_med[];
	float precio;
	char sintomas[];
	char lab_patente[];

}Medicamento;

// No sabia donde poner los medicamentos así que aqui estan y pondre el precio del soriana, dodega aurrera, etc(precio en mexico)


//Medicamentos Genericos
Metformina, 30 tabletas de 850 gr - $65 
Metrool, 20 tabletas de 100 gr - $15
Paracetamol, Caja con frasco de 30 ml 100 mg/ml.Solucion gotas - $11
Loratadina, 10 tabletas de 10 mmg - $43.50
Katerolaco, 10 tabletas de 10 mg - $29.90
Pravastanina, Caja con 30 tabletas de 10 mg - $46
Ketoconazol, Caja con tubo con 40 gr de crema 2% - $56
Senosidos A-B, Caja con 10 tabletas de 187 mg - $35
Miconazol, , Caja con tubo con 20 gr de crema - $14.08
Pantoprazol, Caja con 14 tabletas o grageas de 40 mg - $79
Naproxeno Sodico con Paracetamol,  Caja con frasco con 15 tabletas de 275 mg a 300 mg - $21
Ibopufreno, Caja con 20 tabletas o grageas de 400 mg - $19
Nimesulina, 10 tabletas de 100 mg - $35
Tamsulosina, Caja con 20 capsulas de 0.4 mg - $162.88
Simbastatina, Caja con 14 tabletas de 10 mg- $64

//Medicamentos de patente
Mucosolvan, Frasco con 120 ml, solución con vaso dosificador - $72
Steerimar, Caja con envase de 100 ml - $133.80
Norvas, Caja con 30 tabletas de 5 mg - $499
Supradol, Caja con 4 tabletas sublinguales de 30 mg - $82.95
Riopan, Caja con frasco de 250 ml gel - $124
Pantozol, Caja con 14 grageas de 40 mg - $408
Libertrim sii, Caja con 24 comprimidos d 200 mg a 75 mg - $220
Nootrolpil, Caja con 14 tabletas de 800 mg - $396
Nexium-Mups, Caja con 14 tabletas de 40 mg - $421
Novovartalon, Caja con 30 sobres con polvo - $547
Plavix, Caja con 28 tabletas de 75 mg - $904.20
Yasmin, Caja con 21 omprimidos - $218.10
Meticorten, Caja con 30 tabletas de 5 mg - $204
Livial, Caja con 30 talbetas de 2.5 mg - $444
Treda, Caja con 20 tabletas - $96.70








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
	scanf("%d",&t)

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
				gets(&cap)
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

};

int Borrar(int pos)
{
	/*Faltan determinar parametros*/

	indice --;
};

int Buscar(char cap[])
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
	return -1;
};

void Actualizar(int pos)
{
	captura_medicamento(med[pos]);
}
