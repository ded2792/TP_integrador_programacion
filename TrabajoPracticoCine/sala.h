#ifndef SALA_H_INCLUDED
#define SALA_H_INCLUDED

#include <stdbool.h>

#define MAX_CODIGO_SALA 20

// Estructura que representa una sala del cine
typedef struct {
    char codigo[MAX_CODIGO_SALA];  // Identificador único de la sala (ej: "SALA-A" p "SALA-1", etc)
    int capacidad;                  // Cantidad de lugares
} Sala;

// Funciones para manipular salas (LAS QEU VAN EN sala.c)
Sala crearSala();
void mostrarSala(Sala s);
bool salaVacia(Sala s);
Sala salaVaciaCrear();

#endif // SALA_H_INCLUDED
