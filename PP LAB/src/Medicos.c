#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Medicos.h"
static int idProgresivo = 100;

static sMedico unMedico[TAM_MEDICO] = {{101, "Dr. Jose Hernandez", 201},
									   {102, "Dr. Pablo Mariuzzi", 202},
									   {103, "Dra. Maria Cerrato", 203},
									   {104, "Dr. Carlos Sanchez", 203},
									   {105, "Dra. Samara Julio", 202},
									   {106, "Dra. Silvia Sorredo", 201},
									   {107, "Dr. Fernando Montes", 202}};

static sDiagnostico unDiagnostico[TAM_DIAGNOSTICO] = {{0, "Sin diagnosticar"},
													  {1, "Gripe-A"},
													  {2, "Covid-19"},
													  {3, "Pre Infarto"}};

static sEspecialidad unaEspecialidad[TAM_ESPECIALIDAD] = {{201, "Cirujano"},
														  {202, "Cardiologo"},
														  {203, "Infectologo"}};

static sHospital unHospital[TAM_HOSPITAL] = {{201,"Hospital Britanico", "Raquel Español", 389},
										     {202, "Hospital de Wilde", "Bahia Blanca", 785},
											 {203, "Hospital de Quilmes", "Paysandu", 98}};


void limpiar()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int idProgresive()
{
	idProgresivo++;

	return idProgresivo;
}

int idDesincremental()
{
	idProgresivo--;

	return idProgresivo;
}

int initConsulta(sConsulta unaConsulta[], int sizeConsulta)
{
	int j;
	j=-1;

	for(int i=0; i<sizeConsulta; i++)
	{
		unaConsulta[i].isEmpty = VACIO;
		j=0;
	}

	return j;
}

int altaConsulta(sConsulta unaConsulta[], int sizeConsulta)
{
	int j;

	j = buscarLibre(unaConsulta, sizeConsulta);

	if(j!=-1)
	{
		unaConsulta[j] = cargarConsulta(unMedico, unaEspecialidad);
	}

	return j;
}

int buscarLibre(sConsulta unaConsulta[], int sizeConsulta)
{
	int j;
	j=-1;

	for(int i=0; i<sizeConsulta; i++)
	{
		if(unaConsulta[i].isEmpty == VACIO)
		{
			j=i;
			break;
		}
	}

	return j;
}

void printConsultas(sConsulta unaConsulta[], int sizeConsulta)
{

	printf(" ID |   NOMBRE   |     FECHA    | ID MEDICO | DIAGNOSTICO \n"
			"----------------------------------------------------------\n");
	for(int i=0; i<sizeConsulta; i++)
	{
			printUnaConsulta(unaConsulta, sizeConsulta, i);
	}
	printf("\n");
}


void printUnaConsulta(sConsulta unaConsulta[], int sizeConsulta, int posicion)
{
	char diagnosticoStr[20];

	for(int j=0; j<TAM_DIAGNOSTICO; j++)
	{
		if(unaConsulta[posicion].idDiagnostico == unDiagnostico[j].idDiagnostico)
		{
			strcpy(diagnosticoStr, unDiagnostico[j].descDiagnostico);
		}
	}

	if(unaConsulta[posicion].isEmpty == LLENO)
	{
		printf("%d | %10s |  %2d/%2d/%d  | %6d    | %s\n",unaConsulta[posicion].idConsulta,
														  unaConsulta[posicion].nombrePaciente,
														  unaConsulta[posicion].fechaConsulta.dia,
														  unaConsulta[posicion].fechaConsulta.mes,
														  unaConsulta[posicion].fechaConsulta.anio,
														  unaConsulta[posicion].idMedico,
														  diagnosticoStr);
	}
}

void printMedicos()
{

	printf(" ID |     NOMBRE MEDICO      | ESPECIALIDAD \n"
			"-------------------------------------------\n");
	for(int i=0; i<TAM_MEDICO; i++)
	{
		printUnMedico(i);
	}
}

void printUnMedico(int posicion)
{
	char especialidadStr[20];
	for(int j=0; j<TAM_ESPECIALIDAD; j++)
	{
		if(unMedico[posicion].idEspecialidad == unaEspecialidad[j].idEspecialidad)
		{
			strcpy(especialidadStr,unaEspecialidad[j].descEspecialidad);
			break;
		}
	}

	printf("%d | %22s | %12s\n", unMedico[posicion].idMedico,
							 unMedico[posicion].nombreMedico,
							 especialidadStr);
}

void printIdConsultas(sConsulta unaConsulta[], int sizeConsulta)
{
	for(int i=0; i<sizeConsulta; i++)
	{
		if(unaConsulta[i].isEmpty == LLENO)
		{
			printf("%d\n",unaConsulta[i].idConsulta);
		}
	}
}

void printUnHospital(int posicion)
{
	printf("%d  | %s | %s | %d\n",unHospital[posicion].idEspecialidadDelHospital,
						 unHospital[posicion].descripcionEdificio,
						 unHospital[posicion].calle,
						 unHospital[posicion].numeroDeCalle);
}

int modificarConsulta(sConsulta unaConsulta[], int sizeCosulta, int id)
{
	int ok;
	int posicion;
	int modificacion;
	ok=0;

	posicion = buscarIdConsulta(unaConsulta,sizeCosulta, id);

	printf("Seleccione que se quiere modificar: \n"
			"1_ Nombre del paciente.\n"
			"2_ Fecha de consulta.\n"
			"3_ Medico.\n");
	scanf("%d",&modificacion);
	validarEntero(&modificacion, 1, 3);

	switch(modificacion)
	{
		case 1:
			limpiar();
					printf("Ingrese el nuevo nombre del paciente: ");
					fflush(stdin);
					gets(unaConsulta[posicion].nombrePaciente);
					stringCorrecto(unaConsulta[posicion].nombrePaciente, "nombre");
					ok=1;
			break;

		case 2:
			limpiar();
					printf("Ingrese la nueva fecha de consulta:\n");
					printf("Ingrese el nuevo año: ");
					scanf("%d",&unaConsulta[posicion].fechaConsulta.anio);
					validarEntero(&unaConsulta[posicion].fechaConsulta.anio, 2022, 2024);

					printf("Ingrese el nuevo mes: ");
					scanf("%d",&unaConsulta[posicion].fechaConsulta.mes);
					validarEntero(&unaConsulta[posicion].fechaConsulta.mes, 1, 12);

					printf("Ingrese el nuevo dia: ");
					scanf("%d",&unaConsulta[posicion].fechaConsulta.dia);
					validarFecha(unaConsulta[posicion].fechaConsulta.mes, &unaConsulta[posicion].fechaConsulta.dia);
					ok=1;
			break;

		case 3:
			limpiar();
					printf("Ingrese el nuevo ID del medico que atendera su consulta: ");
					printMedicos(unMedico, unaEspecialidad);
					scanf("%d",&unaConsulta[posicion].idMedico);
					validarEntero(&unaConsulta[posicion].idMedico, 101, 107);
					ok=1;
			break;
	}

	return ok;
}

int buscarIdConsulta(sConsulta unaConsulta[], int sizeCosulta, int id)
{
	int posicion;
	posicion=-1;

	for(int i=0; i<sizeCosulta; i++)
	{
		if(unaConsulta[i].idConsulta == id)
		{
			posicion=i;
			break;
		}
	}

	return posicion;
}

int removeConsulta(sConsulta unaConsulta[], int sizeCosulta, int id)
{
	int rta;
	rta=0;

	for(int i=0; i<sizeCosulta; i++)
	{
		if(unaConsulta[i].idConsulta == id && unaConsulta[i].isEmpty == LLENO)
		{
			unaConsulta[i].isEmpty = VACIO;
			rta=1;
		}
	}

	return rta;
}

int diagnosticarConsulta (sConsulta unaConsulta[], int size)
{
	int ok = 0;
	int idMedico;
	int idConsulta;
	int posicion;

	printf("Ingrese el ID medico para ver las consultas: \n");
	printMedicos(unMedico, unaEspecialidad);
	scanf("%d",&idMedico);
	validarEntero(&idMedico, 101, 107);

	printf("\nIngrese el ID de la consulta que quiere diagnosticar: \n");
	buscarYMostrarIdConsulta(unaConsulta, size, idMedico);
	scanf("%d",&idConsulta);
	posicion = buscarIdConsulta(unaConsulta, size, idConsulta);

	printf("Ingrese el diagnostico del paciente (1-Gripe A, 2-Covid-19, 3-Pre infarto): ");
	scanf("%d",&unaConsulta[posicion].idDiagnostico);
	validarEntero(&unaConsulta[posicion].idDiagnostico, 1, 3);

	if(unaConsulta[posicion].idDiagnostico != 0)
	{
		ok = 1;
	}

	return ok;
}

void buscarYMostrarIdConsulta(sConsulta unaConsulta[], int sizeConsulta, int idMedico)
{
	char diagnosticoStr[20];
	for(int i=0; i<sizeConsulta; i++)
	{
		if(unaConsulta[i].isEmpty == LLENO && unaConsulta[i].idDiagnostico == 0 && unaConsulta[i].idMedico == idMedico)
		{
			for(int j=0; j<4; j++)
			{
				if(unaConsulta[i].idDiagnostico == unDiagnostico[j].idDiagnostico)
				{
					strcpy(diagnosticoStr,unDiagnostico[j].descDiagnostico);
				}
			}

			printf("%d | %s | %s\n", unaConsulta[i].idConsulta,
									 unaConsulta[i].nombrePaciente,
									 diagnosticoStr);
		}
	}
}

void mostrarCinco(sConsulta unaConsulta[], int sizeConsulta)
{
	int listar;
	int especialidad;

	printf("Ingrese que listar:\n"
			"1_ Todos los medicos.\n" //OK
			"2_ Todos las consultas.\n" //OK
			"3_ Todos los médicos con consultas diagnosticadas.\n" //OK
			"4_ Listado de consultas ordenadas por fecha, desde la más reciente hasta la más antigua.\n" //OK
			"5_ Listado de consultas que ya fueron diagnosticadas.\n" //OK
			"6_ Listado de las consultas diagnosticadas con covid-19 desde el inicio de la pandemia hasta la actualidad.\n" //OK
			"7_ Listado de consultas ordenadas por especialidad alfabéticamente.\n" //OK
			"8_ Listado de todas las consultas entre el mes de abril y julio para una especialidad determinada.\n" //OK
			"9_ Porcentaje de consultas diagnosticadas que atiende cada médico en función del total de diagnósticos.\n" //OK
			"10_ La enfermedad menos diagnosticada.\n" //OK
			"11_ La especialidad más estudiada por los médicos.\n" //OK
			"12_ Listado de cada medico en el hospital que trabaja con sus respectivas consultas.\n" //OK
			"13_ Salir.\n");
	scanf("%d",&listar);
	validarEntero(&listar, 1, 13);

	switch(listar)
	{
		case 1:
			limpiar();

			printMedicos();
			system("pause");
			break;

		case 2:
			limpiar();

			printConsultas(unaConsulta, sizeConsulta);
			system("pause");
			break;

		case 3:
			limpiar();

			medicosConsultasDiagnosticadas(unaConsulta, sizeConsulta);
			system("pause");
			break;

		case 4:
			limpiar();

			ordenamientoPorFecha(unaConsulta, sizeConsulta);
			printConsultas(unaConsulta, sizeConsulta);
			ordenamientoPorId(unaConsulta, sizeConsulta);
			system("pause");
			break;

		case 5:
			limpiar();

			listadoConsultasDiagnosticadas(unaConsulta, sizeConsulta);
			system("pause");
			break;

		case 6:
			limpiar();

			listadoDeCovid(unaConsulta, sizeConsulta);
			system("pause");
			break;

		case 7:
			limpiar();

			ordenamientoPorEspecialidad();
			listadoDeConsultasPorEspecialidad(unaConsulta, sizeConsulta);
			system("pause");
			break;

		case 8:
			limpiar();
			printf("Ingrese que especialidad desea listar:\n"
					"1_ Cirujano.\n"
					"2_ Cardiologo.\n"
					"3_ Infectologo.\n");
			scanf("%d",&especialidad);
			validarEntero(&especialidad, 1, 3);

			listadoConsultasAbrilYJulio(unaConsulta, sizeConsulta, especialidad);
			system("pause");
			break;

		case 9:
			limpiar();

			porcentajeConsultasDiagnosticadas(unaConsulta, sizeConsulta);
			system("pause");
			break;

		case 10:
			limpiar();

			enfermedadMenosDiagnosticada(unaConsulta, sizeConsulta);
			system("pause");
			break;

		case 11:
			limpiar();

			especialidadMasEstudiada();
			system("pause");
			break;

		case 12:
			limpiar();

			listadoHospital(unaConsulta, sizeConsulta);
			system("pause");
			break;

		case 13:
			break;
	}
}

void listadoConsultasDiagnosticadas(sConsulta unaConsulta[], int sizeConsulta)
{

	printf("Consultas que fueron diagnosticas:\n");
	for(int i=0; i<sizeConsulta; i++)
	{
		if(unaConsulta[i].isEmpty == LLENO && unaConsulta[i].idDiagnostico != 0)
		{
			printUnaConsulta(unaConsulta, sizeConsulta, i);
		}
	}
	printf("\n");
}


void medicosConsultasDiagnosticadas(sConsulta unaConsulta[], int sizeConsulta)
{
	for(int i=0; i<TAM_MEDICO; i++)
	{
		printUnMedico(i);
		printf("Posee estas consultas:\n");

		for(int j=0; j<sizeConsulta; j++)
		{
			if(unMedico[i].idMedico == unaConsulta[j].idMedico && unaConsulta[j].idDiagnostico != 0)
			{
				printUnaConsulta(unaConsulta, sizeConsulta, j);
			}
		}
		printf("\n\n");
	}
}

void ordenamientoPorFecha(sConsulta unaConsulta[], int sizeConsulta)
{
	sConsulta auxiliar;
	for(int i=0; i<sizeConsulta; i++)
	{
		for(int j=i+1; j<sizeConsulta; j++)
		{
			if(unaConsulta[i].fechaConsulta.anio < unaConsulta[j].fechaConsulta.anio)
			{
				auxiliar = unaConsulta[i];
				unaConsulta[i] = unaConsulta[j];
				unaConsulta[j] = auxiliar;
			}
			else
			{
				if(unaConsulta[i].fechaConsulta.anio == unaConsulta[j].fechaConsulta.anio)
				{
					if(unaConsulta[i].fechaConsulta.mes < unaConsulta[j].fechaConsulta.mes)
					{
						auxiliar = unaConsulta[i];
						unaConsulta[i] = unaConsulta[j];
						unaConsulta[j] = auxiliar;
					}
					else
					{
						if(unaConsulta[i].fechaConsulta.mes == unaConsulta[j].fechaConsulta.mes)
						{
							if(unaConsulta[i].fechaConsulta.dia < unaConsulta[j].fechaConsulta.dia)
							{
								auxiliar = unaConsulta[i];
								unaConsulta[i] = unaConsulta[j];
								unaConsulta[j] = auxiliar;
							}
						}
					}
				}
			}
		}
	}
}

void ordenamientoPorId(sConsulta unaConsulta[], int sizeConsulta)
{
	sConsulta auxiliar;
	for(int i=0; i<sizeConsulta; i++)
	{
		for(int j=i+1; j<sizeConsulta; j++)
		{
			if(unaConsulta[i].idConsulta > unaConsulta[j].idConsulta)
			{
				auxiliar = unaConsulta[i];
				unaConsulta[i] = unaConsulta[j];
				unaConsulta[j] = auxiliar;
			}
		}
	}
}

void listadoDeCovid (sConsulta unaConsulta[], int sizeConsulta)
{
	printf("La pandemia empezo el 17/3/2020.\n"
			"Estos son los casos resgistrasdos desde esa fecha hasta hoy: \n");
	for(int i=0; i<sizeConsulta; i++)
	{
		if(unaConsulta[i].isEmpty == LLENO && unaConsulta[i].idDiagnostico == 2 && unaConsulta[i].fechaConsulta.anio >= 2020)
		{
			if(unaConsulta[i].fechaConsulta.anio == 2020)
			{
				if(unaConsulta[i].fechaConsulta.mes >= 3)
				{
					if(unaConsulta[i].fechaConsulta.mes == 3)
					{
						if(unaConsulta[i].fechaConsulta.dia >= 17)
						{
							printUnaConsulta(unaConsulta, sizeConsulta, i);
						}
					}
					else
					{
						printUnaConsulta(unaConsulta, sizeConsulta, i);
					}
				}
			}
			else
			{
				printUnaConsulta(unaConsulta, sizeConsulta, i);
			}
		}
	}
}

void ordenamientoPorEspecialidad()
{
	sEspecialidad auxiliar;
	for(int i=0; i<TAM_ESPECIALIDAD; i++)
	{
		for(int j=i+1; j<TAM_ESPECIALIDAD; j++)
		{
			if(strcmp(unaEspecialidad[i].descEspecialidad,unaEspecialidad[j].descEspecialidad) > 0)
			{
				auxiliar = unaEspecialidad[i];
				unaEspecialidad[i] = unaEspecialidad[j];
				unaEspecialidad[j] = auxiliar;
			}
		}
	}
}

void listadoDeConsultasPorEspecialidad(sConsulta unaConsulta[], int sizeConsulta)
{
	for(int i=0; i<TAM_ESPECIALIDAD; i++)
	{
		printf("%s: \n",unaEspecialidad[i].descEspecialidad);

		for(int j=0; j<TAM_MEDICO; j++)
		{
			if(unaEspecialidad[i].idEspecialidad == unMedico[j].idEspecialidad)
			{
				for(int k=0; k<sizeConsulta; k++)
				{
					if(unMedico[j].idMedico == unaConsulta[k].idMedico)
					{
						printUnaConsulta(unaConsulta, sizeConsulta, k);
					}
				}
			}
		}
		printf("\n\n");
	}
}

void listadoConsultasAbrilYJulio (sConsulta unaConsulta[], int sizeConsulta, int especialidad)
{
	switch(especialidad)
	{
		case 1:
			limpiar();
			printf("Cirujano:\n");
			especialidad=201;
			break;

		case 2:
			limpiar();
			printf("Cardiologo:\n");
			especialidad=202;
			break;

		case 3:
			limpiar();
			printf("Infectologo:\n");
			especialidad=203;
			break;
	}

	for(int i=0; i<TAM_MEDICO; i++)
	{
		if(especialidad == unMedico[i].idEspecialidad)
		{
			for(int j=0; j<sizeConsulta; j++)
			{
				if(unMedico[i].idMedico == unaConsulta[j].idMedico)
				{
					if(unaConsulta[j].fechaConsulta.mes > 3 && unaConsulta[j].fechaConsulta.mes < 8)
					{
						printUnaConsulta(unaConsulta, sizeConsulta,j);
					}
				}
			}
		}
	}
}

void enfermedadMenosDiagnosticada (sConsulta unaConsulta[], int sizeConsulta)
{
	int cantidadGripe = 0;
	int cantidadCovid = 0;
	int cantidadPreInfarto = 0;

	for(int i=0; i<sizeConsulta; i++)
	{
		if(unaConsulta[i].isEmpty == LLENO)
		{
			switch(unaConsulta[i].idDiagnostico)
			{
				case 1:
					cantidadGripe++;
					break;
				case 2:
					cantidadCovid++;
					break;
				case 3:
					cantidadPreInfarto++;
					break;
			}
		}
	}

	if(cantidadGripe < cantidadCovid && cantidadGripe < cantidadPreInfarto)
	{
		printf("La enfermedad menos diagnosticada es la Gripe-A.\n");
	}
	else
	{
		if(cantidadCovid < cantidadGripe && cantidadCovid < cantidadPreInfarto)
		{
			printf("La enfermedad menos diagnosticada es el Covid-19.\n");
		}
		else
		{
			if(cantidadPreInfarto < cantidadCovid)
			{
				printf("La enfermedad menos diagnosticada es el Pre Infarto.\n");
			}
			else
			{
				printf("No hay una enfermedad que sea la menos diagnosticada.\n");
			}
		}
	}
}

void especialidadMasEstudiada()
{
	int cantidadCirujano;
	int cantidadCardiologo;
	int cantidaInfectologo;

	for(int i=0; i<TAM_MEDICO; i++)
	{
		switch(unMedico[i].idEspecialidad)
		{
			case 1:
				cantidadCirujano++;
				break;
			case 2:
				cantidadCardiologo++;
				break;
			case 3:
				cantidaInfectologo++;
				break;
		}
	}

	if(cantidadCirujano > cantidadCardiologo && cantidadCirujano > cantidaInfectologo)
	{
		printf("La especialidad mas estudiada es Cirujano.\n");
	}
	else
	{
		if(cantidadCardiologo > cantidadCirujano && cantidadCardiologo > cantidaInfectologo)
		{
			printf("La especialidad mas estudiada es Cardiologo.\n");
		}
		else
		{
				printf("La especialidad mas estudiada es Infectologo.\n");
		}
	}

}

void listadoHospital(sConsulta unaConsulta[], int sizeConsulta)
{
	for(int i=0; i<TAM_HOSPITAL; i++)
	{
		printf("\n\n");
		printUnHospital(i);
		printf("En este hospital atienden estos medicos: \n");

		for(int j=0; j<TAM_MEDICO; j++)
		{
			if(unMedico[j].idEspecialidad == unHospital[i].idEspecialidadDelHospital)
			{
				printUnMedico(j);
				printf("Este medico tiene estas consultas: \n");

				for(int k=0; k<sizeConsulta; k++)
				{
					if(unMedico[j].idMedico == unaConsulta[k].idMedico)
					{
						printUnaConsulta(unaConsulta, sizeConsulta, k);
					}
				}
				printf("\n");
			}
		}
	}
}

void porcentajeConsultasDiagnosticadas(sConsulta unaConsulta[], int sizeConsulta)
{
	int totalDiagnosticos = 0;
	int contadorDiagnosticados[TAM_MEDICO];
	float promedio;

	for(int i=0; i<TAM_MEDICO; i++)
	{
		contadorDiagnosticados[i] = 0;
		for(int j=0; j<sizeConsulta; j++)
		{
			if(unMedico[i].idMedico == unaConsulta[j].idMedico && unaConsulta[j].idDiagnostico != 0)
			{
				contadorDiagnosticados[i]++;
				totalDiagnosticos++;
			}
		}
	}

	for(int i=0; i<TAM_MEDICO; i++)
	{
		promedio = ((float)contadorDiagnosticados[i]*100)/totalDiagnosticos;
		printUnMedico(i);
		printf("Tuvo un %.2f%s de consultas diagnosticadas. \n\n\n",promedio,"%");
	}
}

