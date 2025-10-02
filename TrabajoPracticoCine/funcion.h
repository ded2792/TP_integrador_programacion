#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED

#include <stdbool.h>
#include "pelicula.h"
#include "sala.h"
#include "cliente.h"  // para la estructura Fecha, en una libreria se peuden incluir librerias propias

// Estructura para almacenar hora
typedef struct {
    int hora;    // 0-23
    int minuto;  // 0-59
} Hora;

// Estructura que representa una función de cine
typedef struct {
    int id;                      // id de la función
    int codigoPelicula;          // Referencia a la película
    char codigoSala[MAX_CODIGO_SALA]; // Referencia a la sala
    Fecha fecha;                 // Fecha de la función
    Hora horaInicio;             // Hora de inicio
    int reservasHechas;          // Contador de reservas
    float precio;                // Precio de la entrada
} Funcion;

// Funciones para manipular funciones (SON LAS QUE VAN A ESTAR EN funcion.c)
Funcion crearFuncion();
void mostrarFuncion(Funcion f);
bool funcionVacia(Funcion f);
Funcion funcionVaciaCrear();

#endif // FUNCION_H_INCLUDED
