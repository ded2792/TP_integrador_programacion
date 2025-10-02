#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelicula.h"

// ==============================================
// IMPLEMENTACI�N DE FUNCIONES DE PEL�CULA
// ==============================================

// Funci�n para crear una pel�cula vac�a
Pelicula peliculaVaciaCrear() {
    Pelicula p;
    p.codigo = 0;  // Centinela
    strcpy(p.titulo, "");
    p.duracion = 0;
    strcpy(p.clasificacion, "");
    strcpy(p.idioma, "");
    strcpy(p.genero, "");
    strcpy(p.formato, "");
    return p;
}

// Verifica si una pel�cula est� vac�a
bool peliculaVacia(Pelicula p) {
    return p.codigo == 0;
}

// Funci�n para crear una pel�cula ingresando datos por teclado
Pelicula crearPelicula() {
    Pelicula p;

    printf("\n=== ALTA DE PELICULA ===\n");

    // Ingreso de c�digo
    printf("Ingrese codigo de pelicula: ");
    scanf("%d", &p.codigo);

    // Validaci�n: el c�digo no puede ser 0 (reservado para vac�o)
    if (p.codigo == 0) {
        printf("ERROR: El codigo no puede ser 0.\n");
        return peliculaVaciaCrear();
    }

    // Limpiamos buffer del scanf anterior
    while (getchar() != '\n');

    // Ingreso de t�tulo
    printf("Ingrese titulo: ");
    scanf(" %99[^\n]", p.titulo);

    // Ingreso de duraci�n
    printf("Ingrese duracion (minutos): ");
    scanf("%d", &p.duracion);

    // Validaci�n de duraci�n
    if (p.duracion <= 0) {
        printf("ERROR: La duracion debe ser mayor a 0.\n");
        return peliculaVaciaCrear();
    }

    while (getchar() != '\n');

    // Ingreso de clasificaci�n
    printf("Ingrese clasificacion (ATP, +13, +16, +18): ");
    scanf(" %4[^\n]", p.clasificacion);

    while (getchar() != '\n');

    // Ingreso de idioma
    printf("Ingrese idioma: ");
    scanf(" %29[^\n]", p.idioma);

    while (getchar() != '\n');

    // Ingreso de g�nero
    printf("Ingrese genero: ");
    scanf(" %29[^\n]", p.genero);

    while (getchar() != '\n');

    // Ingreso de formato
    printf("Ingrese formato (2D, 3D, 4D): ");
    scanf(" %9[^\n]", p.formato);

    printf("\nPelicula creada exitosamente!\n");
    return p;
}

// Funci�n para mostrar una pel�cula por pantalla
void mostrarPelicula(Pelicula p) {
    if (peliculaVacia(p)) {
        printf("(Pelicula vacia)\n");
        return;
    }

    printf("\n--- DATOS DE PELICULA ---\n");
    printf("Codigo: %d\n", p.codigo);
    printf("Titulo: %s\n", p.titulo);
    printf("Duracion: %d minutos\n", p.duracion);
    printf("Clasificacion: %s\n", p.clasificacion);
    printf("Idioma: %s\n", p.idioma);
    printf("Genero: %s\n", p.genero);
    printf("Formato: %s\n", p.formato);
    printf("-------------------------\n");
}
