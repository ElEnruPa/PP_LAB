#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Medicos.h"

sConsulta cargarConsulta(sMedico unMedico[], sEspecialidad unaEspecialidad[])
{
	sConsulta unaConsulta;

	printf("Ingrese el nombre del paciente: ");
	fflush(stdin);
	gets(unaConsulta.nombrePaciente);
	stringCorrecto(unaConsulta.nombrePaciente, "nombre");

	printf("Ingrese el año de la consulta (2022-2024): ");
	scanf("%d",&unaConsulta.fechaConsulta.anio);
	validarEntero(&unaConsulta.fechaConsulta.anio, 2022, 2024);

	printf("Ingrese el mes de la consulta (1-12): ");
	scanf("%d",&unaConsulta.fechaConsulta.mes);
	validarEntero(&unaConsulta.fechaConsulta.mes, 1, 12);

	printf("Ingrese el dia de la consulta: ");
	scanf("%d",&unaConsulta.fechaConsulta.dia);
	validarFecha(unaConsulta.fechaConsulta.mes, &unaConsulta.fechaConsulta.dia);

	printf("Ingrese el ID del medico que atiende su consulta: \n");
	printMedicos(unMedico, unaEspecialidad);
	scanf("%d",&unaConsulta.idMedico);
	validarEntero(&unaConsulta.idMedico, 101, 107);

	unaConsulta.idDiagnostico = 0;
	unaConsulta.idConsulta = idProgresive();
	unaConsulta.isEmpty = LLENO;

	return unaConsulta;
}


void validarEntero(int* num, int minimo, int maximo)
{

	while(*num < minimo || *num > maximo)
	{
		printf("Ingrese una opcion valida (%d-%d): ",minimo ,maximo);
		fflush(stdin);
		scanf("%d",num);
	}
}

int validarString(char string[])
{
    int ok;
    ok = 1;

    for(int i = 0; i < strlen(string); i++)
    {
        if (isdigit(string[i]) == 1)
        {
        	ok = 0;
        }
    }

    return ok;
}

void stringCorrecto(char string[], char mensaje[])
{
	int ok;
	ok=validarString(string);

	while(ok==0)
	{
		printf("Ingrese un %s valido: ",mensaje);
		fflush(stdin);
		gets(string);
		ok=validarString(string);
	}
}

void validarFecha(int mes, int* dia)
{
	if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
	{
		validarEntero(dia, 1, 31);
	}
	else
	{
		if(mes == 2)
		{
			validarEntero(dia, 1, 28);
		}
		else
		{
			validarEntero(dia, 1, 30);
		}
	}
}





