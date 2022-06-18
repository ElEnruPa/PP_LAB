#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Medicos.h"
#define TAM_CONSULTA 100

int main(void)
{
	setbuf(stdout, NULL);

	/*sConsulta unaConsulta[TAM_CONSULTA] = {{idProgresive(), "Enru", {1,12,2022}, 1, 103, 1},
										   {idProgresive(), "Martu", {2,8,2023}, 2, 104, 1},
										   {idProgresive(), "Jose", {12,6,2024}, 1, 102, 1},
										   {idProgresive(), "Gonza", {11,4,2023}, 3, 106, 1},
										   {idProgresive(), "Maria", {25,9,2022}, 0, 102, 1},
										   {idProgresive(), "Paul", {18,3,2024}, 2, 102, 1},
										   {idProgresive(), "Rocio", {22,5,2023}, 2, 105, 1}};*/

	int opcion;
	int retorno;
	int id;
	int consultaIngresada = 0;
	sConsulta unaConsulta[TAM_CONSULTA];

	initConsulta(unaConsulta, TAM_CONSULTA);

	do
	{
		limpiar();
		printf("Ingrese una opcion:\n"
				"1_ Alta consulta.\n"
				"2_ Modificar consulta.\n"
				"3_ Cancelar consulta.\n"
				"4_ Diagnosticar.\n"
				"5_ Listar.\n"
				"6_ Salir.\n");
		scanf("%d",&opcion);
		validarEntero(&opcion, 1, 6);

		switch(opcion)
		{
			case 1:
				limpiar();

				retorno = altaConsulta(unaConsulta, TAM_CONSULTA);

				if(retorno!=-1)
				{
					printf("Carga exitosa.\n");
					consultaIngresada++;
				}
				else
				{
					printf("No hay lugar para una nueva consulta.\n");
				}

				system("pause");
				break;

			case 2:
				limpiar();

				if(consultaIngresada != 0)
				{
					printf("Ingrese el ID de la consulta que se quiere modificar: \n");
					printIdConsultas(unaConsulta, TAM_CONSULTA);
					scanf("%d",&id);
					validarEntero(&id, 101, idProgresive()-1);
					idDesincremental();

					modificarConsulta(unaConsulta, TAM_CONSULTA, id);
				}
				else
				{
					printf("No se puede modificar ninguna consulta si no se ingresa una antes.\n");
				}

				system("pause");
				break;

			case 3:
				limpiar();

				if(consultaIngresada != 0)
				{
					printf("Ingrese el ID de la consulta que quiere cancelar: \n");
					printIdConsultas(unaConsulta, TAM_CONSULTA);
					scanf("%d",&id);
					validarEntero(&id, 101, idProgresive()-1);
					idDesincremental();

					removeConsulta(unaConsulta, TAM_CONSULTA, id);
					consultaIngresada--;
				}
				else
				{
					printf("No se puede remover ninguna consulta si no se ingresa una antes.\n");
				}

				system("pause");
				break;

			case 4:
				limpiar();

				if(consultaIngresada != 0)
				{
					diagnosticarConsulta(unaConsulta, TAM_CONSULTA);
				}
				else
				{
					printf("No se puede diagnosticar ninguna consulta si no se ingresa una antes.\n");
				}

				system("pause");
				break;

			case 5:
				limpiar();

				mostrarCinco(unaConsulta, TAM_CONSULTA);
				break;

		}
	}while(opcion!=6);

	limpiar();
	printf("------CONSOLA APAGADA------");

	return 0;
}


