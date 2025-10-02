#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED

#include <stdbool.h>

// constantes para tamaños de strings
#define MAX_TITULO 100
#define MAX_IDIOMA 30
#define MAX_GENERO 30
#define MAX_FORMATO 10
#define MAX_CLASIFICACION 5

// Estructura que representa una película
// Tiene todos los datos del enunciado
typedef struct {
    int codigo;                      // id único
    char titulo[MAX_TITULO];         // Nombre de la película
    int duracion;                    // En minutos
    char clasificacion[MAX_CLASIFICACION]; // ATP, +13, +16, +18
    char idioma[MAX_IDIOMA];         // Español, Ingles, etc.
    char genero[MAX_GENERO];         // Acción, drama, comedia, etc.
    char formato[MAX_FORMATO];       // 2D, 3D, 4D
} Pelicula;

// Declaración de funciones
// ESTAS SON LAS QUE SE VAN A INVOCAR/LLAMAR EN pelicula.c

// Crea una película solicitando datos por teclado
Pelicula crearPelicula();

// Muestra los datos de una película por pantalla
void mostrarPelicula(Pelicula p);

// Verifica si una película está vacía (no inicializada)
// Una película vacía tiene código = 0
bool peliculaVacia(Pelicula p);

// Crea una película vacía (para inicialización)
Pelicula peliculaVaciaCrear();

#endif // PELICULA_H_INCLUDED
