#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdbool.h>

#define MAX_NOMBRE 50
#define MAX_EMAIL 100
#define MAX_PASSWORD 50

// Estructura para almacenar fecha
typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

// Estructura que representa un cliente
typedef struct {
    char nombre[MAX_NOMBRE];
    int dni;
    char email[MAX_EMAIL];
    char password[MAX_PASSWORD];
    Fecha fechaNacimiento;
} Cliente;

// Declaraciones de funciones (implementaremos después)
Cliente crearCliente();
void mostrarCliente(Cliente c);
bool clienteVacio(Cliente c);
Cliente clienteVacioCrear();
int calcularEdad(Fecha nacimiento, Fecha actual);
bool esMayorDeEdad(Cliente c, Fecha fechaActual);

#endif // CLIENTE_H_INCLUDED
