#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelicula.h"

// ==============================================
// IMPLEMENTACIÓN DE FUNCIONES DE PELÍCULA
// ==============================================

// Función para crear una película vacía
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

// Verifica si una película está vacía
bool peliculaVacia(Pelicula p) {
    return p.codigo == 0;
}

// Función para crear una película ingresando datos por teclado
Pelicula crearPelicula() {
    Pelicula p;

    printf("\n=== ALTA DE PELICULA ===\n");

    // Ingreso de código
    printf("Ingrese codigo de pelicula: ");
    scanf("%d", &p.codigo);

    // Validación: el código no puede ser 0 (reservado para vacío)
    if (p.codigo == 0) {
        printf("ERROR: El codigo no puede ser 0.\n");
        return peliculaVaciaCrear();
    }

    // Limpiamos buffer del scanf anterior
    while (getchar() != '\n');

    // Ingreso de título
    printf("Ingrese titulo: ");
    scanf(" %99[^\n]", p.titulo);

    // Ingreso de duración
    printf("Ingrese duracion (minutos): ");
    scanf("%d", &p.duracion);

    // Validación de duración
    if (p.duracion <= 0) {
        printf("ERROR: La duracion debe ser mayor a 0.\n");
        return peliculaVaciaCrear();
    }

    while (getchar() != '\n');

    // Ingreso de clasificación
    printf("Ingrese clasificacion (ATP, +13, +16, +18): ");
    scanf(" %4[^\n]", p.clasificacion);

    while (getchar() != '\n');

    // Ingreso de idioma
    printf("Ingrese idioma: ");
    scanf(" %29[^\n]", p.idioma);

    while (getchar() != '\n');

    // Ingreso de género
    printf("Ingrese genero: ");
    scanf(" %29[^\n]", p.genero);

    while (getchar() != '\n');

    // Ingreso de formato
    printf("Ingrese formato (2D, 3D, 4D): ");
    scanf(" %9[^\n]", p.formato);

    printf("\nPelicula creada exitosamente!\n");
    return p;
}

// Función para mostrar una película por pantalla
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
