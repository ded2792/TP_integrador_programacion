#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdbool.h>

#define MAX_NOMBRE 50
#define MAX_EMAIL 100
#define MAX_PASSWORD 50

// Estructura para almacenar fecha de nacimiento
// Separamos día, mes y año para facilitar validaciones
typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

// estructura que representa un cliente del cine
typedef struct {
    char nombre[MAX_NOMBRE];
    int dni;                        // Identificador único (centinela/bandera)
    char email[MAX_EMAIL];
    char password[MAX_PASSWORD];
    Fecha fechaNacimiento;          // Estructura anidada
} Cliente;

// Funciones para manipular clientes (LAS QUE VAN EN cliente.c)
Cliente crearCliente();
void mostrarCliente(Cliente c);
bool clienteVacio(Cliente c);
Cliente clienteVacioCrear();

// Función para calcular edad
int calcularEdad(Fecha nacimiento, Fecha actual);

// Función para verificar si un cliente es mayor de edad
bool esMayorDeEdad(Cliente c, Fecha fechaActual);

#endif // CLIENTE_H_INCLUDED
