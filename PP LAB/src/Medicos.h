#ifndef MEDICOS_H_
#define MEDICOS_H_
#define VACIO 0
#define LLENO 1
#define TAM_MEDICO 7
#define TAM_DIAGNOSTICO 4
#define TAM_ESPECIALIDAD 3
#define TAM_HOSPITAL 3

typedef struct
{
	int idMedico;
	char nombreMedico[50];
	int idEspecialidad;

}sMedico;

typedef struct
{
	int dia;
	int mes;
	int anio;

}sFecha;

typedef struct
{
	int idConsulta;
	char nombrePaciente[50];
	sFecha fechaConsulta;
	int idDiagnostico;
	int idMedico;
	int isEmpty;

}sConsulta;

typedef struct
{
	int idDiagnostico;
	char descDiagnostico[20];

}sDiagnostico;

typedef struct
{
	int idEspecialidad;
	char descEspecialidad[20];

}sEspecialidad;

typedef struct
{
	int idEspecialidadDelHospital;
	char descripcionEdificio[40];
	char calle[30];
	int numeroDeCalle;

}sHospital;

/// \brief Carga una consulta
/// \param unMedico estructura del medico
/// \param unaEspecialidad estructura de una especialidad
/// \return retorna la consulta que se ingreso
sConsulta cargarConsulta(sMedico unMedico[], sEspecialidad unaEspecialidad[]);

/// \brief Valida si el numero es entero y esta entre los rangos marcados
/// \param num Numero a validar
/// \param minimo El rango minimo
/// \param maximo El rango maximo
void validarEntero(int* num, int minimo, int maximo);

/// \brief Valida si la cadena tiene algun digito
/// \param string String a validar
/// \return Retorna el 1 si no tiene digitos, 0 si tiene digitos
int validarString(char string[]);

/// \brief Valida si es un string
/// \param string String a validar
/// \param mensaje mensaje por si da error
void stringCorrecto(char string[], char mensaje[]);

/// \brief Valida si la fecha es correcta
/// \param mes Mes ingresado
/// \param dia Dia ingresado
void validarFecha(int mes, int* dia);

/// \brief Limpia la consola con muchas "\n"
void limpiar();

/// \brief ID statico que aumenta en 1
/// \return Retorna el ID aumentandole 1
int idProgresive();

/// \brief ID estatico que disminuye en 1
/// \return Devuelve el ID disminuido en 1
int idDesincremental();

/// \brief Pone el parametro isEmpty en Vacio
/// \param unaConsulta Estructura de consulta
/// \param sizeConsulta Tamaño de la estructura de consulta
/// \return -1 si no se pudo poner vacio y 0 si se vacio
int initConsulta(sConsulta unaConsulta[], int sizeConsulta);

/// \brief Da un alta a una consulta
/// \param unaConsulta Estructura de consulta
/// \param sizeConsulta Tamaño de la estructura de consulta
/// \return Retorna la posicion de la consulta que se agrego
int altaConsulta(sConsulta unaConsulta[], int sizeConsulta);

/// \brief Busca si hay un espacio libre en el array de unaConsulta
/// \param unaConsulta Estructura de consulta
/// \param sizeConsulta Tamaño de la estructura de consulta
/// \return Retorna la primera posicion libre del array de unaConsulta
int buscarLibre(sConsulta unaConsulta[], int sizeConsulta);

/// \brief Muestra en consola todas las consultas
/// \param unaConsulta Estructura de consulta
/// \param sizeConsulta Tamaño de la estructura de consulta
void printConsultas(sConsulta unaConsulta[], int sizeConsulta);

/// \brief Muestra una sola consulta
/// \param unaConsulta Estructura de consulta
/// \param sizeConsulta Tamaño de la estructura de consulta
/// \param posicion Posicion de la consulta que se quiere mostrar
void printUnaConsulta(sConsulta unaConsulta[], int sizeConsulta, int posicion);

/// \brief Muestra todos los medicos
void printMedicos();

/// \brief Muestra un medico
/// \param posicion Posicion del medico que se quiere mostrar
void printUnMedico(int posicion);

/// \brief Muestra los ID de las consultas que estan llenas
/// \param unaConsulta Estructura de consulta
/// \param sizeConsulta Tamaño de la estructura de consulta
void printIdConsultas(sConsulta unaConsulta[], int sizeConsulta);

/// \brief Muestra un hospital
/// \param posicion Posicion del hospital que se quiere mostrar
void printUnHospital(int posicion);

/// \brief Modifica una consulta
/// \param unaConsulta Estructura de consulta
/// \param sizeCosulta Tamaño de la estructura de consulta
/// \param id Id de la consulta que se quiere modificar
/// \return Devuelve 0 si no se pudo modificar, o 1 si se modifico correctamente
int modificarConsulta(sConsulta unaConsulta[], int sizeCosulta, int id);

/// \brief Encuentra la posicion del array en donde esta el ID ingresado
/// \param unaConsulta Estructura de consulta
/// \param sizeCosulta Tamaño de la estructura de consulta
/// \param id Id que se quiere encontrar
/// \return Devuelve el ID si se encontro en el array de las consultas, o -1 si no se pudo encontrar
int buscarIdConsulta(sConsulta unaConsulta[], int sizeCosulta, int id);

/// \brief Remueve la consulta del ID ingresado
/// \param unaConsulta Estructura de consulta
/// \param sizeCosulta Tamaño de la estructura de consulta
/// \param id Id que se quiere eliminar del array
/// \return Devuelve la posicion del array de la consulta que se removio, o -1 si no se pudo remover
int removeConsulta(sConsulta unaConsulta[], int sizeCosulta, int id);

/// \brief Diagnostica una consulta
/// \param unaConsulta Estructura de consulta
/// \param sizeConsulta Tamaño de la estructura de consulta
/// \return Devuelve 1 si se pudo diagnosticar la consulta, o 0 si no se pudo
int diagnosticarConsulta (sConsulta unaConsulta[], int sizeConsulta);

/// \brief Busca e imprime la consulta con el Id seleccionado
/// \param unaConsulta Estructura de consulta
/// \param sizeConsulta Tamaño de la estructura de consulta
/// \param idMedico Id que se quiere buscar e imprimir
void buscarYMostrarIdConsulta(sConsulta unaConsulta[], int sizeConsulta, int idMedico);

/// \brief Busca e imprime las consultas que ya fueron diagnosticadas
/// \param unaConsulta Estructura de consulta
/// \param sizeConsulta Tamaño de la estructura de consulta
void listadoConsultasDiagnosticadas(sConsulta unaConsulta[], int sizeConsulta);

/// \brief Imprime el medico con sus respectivas consultas diagnosticadas
/// \param unaConsulta Estructura de consulta
/// \param sizeConsulta Tamaño de la estructura de consulta
void medicosConsultasDiagnosticadas(sConsulta unaConsulta[], int sizeConsulta);

/// \brief Contiene el punto 5 encapsulado en esta funcion
/// \param unaConsulta Estructura de consulta
/// \param sizeConsulta Tamaño de la estructura de consulta
void mostrarCinco(sConsulta unaConsulta[], int sizeConsulta);

/// \brief Ordena las consultas por fecha
/// \param unaConsulta Estructura de consulta
/// \param sizeConsulta Tamaño de la estructura de consulta
void ordenamientoPorFecha(sConsulta unaConsulta[], int sizeConsulta);

/// \brief Ordena las consultas por ID
/// \param unaConsulta Estructura de consulta
/// \param sizeConsulta Tamaño de la estructura de consulta
void ordenamientoPorId(sConsulta unaConsulta[], int sizeConsulta);

/// \brief Muestra los pacientes diagnosticados de covid desde la pandemia hasta la actualidad
/// \param unaConsulta Estructura de consulta
/// \param sizeConsulta Tamaño de la estructura de consulta
void listadoDeCovid (sConsulta unaConsulta[], int sizeConsulta);

/// \brief Ordena las especialidades alfabeticamente
void ordenamientoPorEspecialidad();

/// \brief Muestra las consultas ordenadas por especialidad
/// \param unaConsulta Estructura de consulta
/// \param sizeConsulta Tamaño de la estructura de consulta
void listadoDeConsultasPorEspecialidad(sConsulta unaConsulta[], int sizeConsulta);

/// \brief Muestra las consultas entre abril y julio de una especialidad determinada
/// \param unaConsulta Estructura de consulta
/// \param sizeConsulta Tamaño de la estructura de consulta
/// \param especialidad Especialidad que se desea mostrar
void listadoConsultasAbrilYJulio (sConsulta unaConsulta[], int sizeConsulta, int especialidad);

/// \brief Calcula y muestra la enfermedad menos diagnosticada
/// \param unaConsulta Estructura de consulta
/// \param sizeConsulta Tamaño de la estructura de consulta
void enfermedadMenosDiagnosticada (sConsulta unaConsulta[], int sizeConsulta);

/// \brief Calcula y muestra la especialidad mas estudiada
void especialidadMasEstudiada();

/// \brief Listado de cada medico en el hospital que trabaja con sus respectivas consultas
/// \param unaConsulta Estructura de consulta
/// \param sizeConsulta Tamaño de la estructura de consulta
void listadoHospital(sConsulta unaConsulta[], int sizeConsulta);

/// \brief Calcula y muestra  el porcentaje de consultas diagnosticadas que atiende cada médico
/// \param unaConsulta Estructura de consulta
/// \param sizeConsulta Tamaño de la estructura de consulta
void porcentajeConsultasDiagnosticadas(sConsulta unaConsulta[], int sizeConsulta);


#endif /* MEDICOS_H_ */
