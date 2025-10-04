#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <stdbool.h>
#include "cliente.h"
#include "pelicula.h"
#include "sala.h"

// FUNCIONES DE VALIDACIÓN

bool esBisiesto(int anio);
bool fechaValida(int dia, int mes, int anio);
Fecha crearFecha(int dia, int mes, int anio);
Fecha obtenerFechaActual();
int calcularEdad(Fecha nacimiento, Fecha actual);
int compararFechas(Fecha fecha1, Fecha fecha2);
bool emailValido(char email[]);
bool dniValido(int dni);
void limpiarBuffer();

// FUNCIONES DE PERSISTENCIA (ARCHIVOS .TXT)

// Películas
bool guardarPeliculas(Pelicula peliculas[], int cantidad);
int cargarPeliculas(Pelicula peliculas[], int capacidad);

// Salas
bool guardarSalas(Sala salas[], int cantidad);
int cargarSalas(Sala salas[], int capacidad);

// Clientes
bool guardarClientes(Cliente clientes[], int cantidad);
int cargarClientes(Cliente clientes[], int capacidad);

#endif // UTILS_H_INCLUDED
