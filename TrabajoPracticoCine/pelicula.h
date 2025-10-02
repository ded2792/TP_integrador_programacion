#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED

#include <stdbool.h>

// constantes para tama�os de strings
#define MAX_TITULO 100
#define MAX_IDIOMA 30
#define MAX_GENERO 30
#define MAX_FORMATO 10
#define MAX_CLASIFICACION 5

// Estructura que representa una pel�cula
// Tiene todos los datos del enunciado
typedef struct {
    int codigo;                      // id �nico
    char titulo[MAX_TITULO];         // Nombre de la pel�cula
    int duracion;                    // En minutos
    char clasificacion[MAX_CLASIFICACION]; // ATP, +13, +16, +18
    char idioma[MAX_IDIOMA];         // Espa�ol, Ingles, etc.
    char genero[MAX_GENERO];         // Acci�n, drama, comedia, etc.
    char formato[MAX_FORMATO];       // 2D, 3D, 4D
} Pelicula;

// Declaraci�n de funciones
// ESTAS SON LAS QUE SE VAN A INVOCAR/LLAMAR EN pelicula.c

// Crea una pel�cula solicitando datos por teclado
Pelicula crearPelicula();

// Muestra los datos de una pel�cula por pantalla
void mostrarPelicula(Pelicula p);

// Verifica si una pel�cula est� vac�a (no inicializada)
// Una pel�cula vac�a tiene c�digo = 0
bool peliculaVacia(Pelicula p);

// Crea una pel�cula vac�a (para inicializaci�n)
Pelicula peliculaVaciaCrear();

#endif // PELICULA_H_INCLUDED
