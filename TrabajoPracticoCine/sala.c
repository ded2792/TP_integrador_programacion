#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sala.h"

// IMPLEMENTACIÓN DE FUNCIONES DE SALA

// Función para crear una sala vacía
// Usamos capacidad = 0 como centinela
Sala salaVaciaCrear() {
    Sala s;
    strcpy(s.codigo, "");     // String vacío
    s.capacidad = 0;          // Centinela
    return s;
}

// Verifica si una sala está vacía
// ¿Cómo? Verificando si la capacidad es 0
bool salaVacia(Sala s) {
    return s.capacidad == 0;
}

// Función para crear una sala ingresando datos por teclado
Sala crearSala() {
    Sala s;

    printf("\n=== ALTA DE SALA ===\n");

    // Limpiamos el buffer antes de leer strings
    while (getchar() != '\n');

    // Ingreso de código de sala
    printf("Ingrese codigo de sala (ej: SALA-A, SALA-1, S1): ");
    scanf(" %19[^\n]", s.codigo);

    // Validación: el código no puede estar vacío
    if (strlen(s.codigo) == 0) {
        printf("ERROR: El codigo no puede estar vacio.\n");
        return salaVaciaCrear();
    }

    // Convertimos el código a mayúsculas para uniformidad
    // ¿Por qué? Para que "sala-a" y "SALA-A" sean iguales
    int i;
    for (i = 0; s.codigo[i] != '\0'; i++) {
        if (s.codigo[i] >= 'a' && s.codigo[i] <= 'z') {
            s.codigo[i] = s.codigo[i] - 32;  // Convertir a mayúscula
            // 'a' = 97, 'A' = 65, diferencia = 32
        }
    }

    // Ingreso de capacidad
    printf("Ingrese capacidad (cantidad de butacas): ");
    scanf("%d", &s.capacidad);

    // Validación de capacidad
    if (s.capacidad <= 0) {
        printf("ERROR: La capacidad debe ser mayor a 0.\n");
        return salaVaciaCrear();
    }

    // Validación: capacidad razonable (entre 1 y 1000)
    if (s.capacidad > 1000) {
        printf("ADVERTENCIA: Capacidad muy alta. Se establecera en 1000.\n");
        s.capacidad = 1000;
    }

    printf("\nSala creada exitosamente!\n");
    return s;
}

// Función para mostrar una sala por pantalla
void mostrarSala(Sala s) {
    // Verificamos que no esté vacía antes de mostrar
    if (salaVacia(s)) {
        printf("(Sala vacia)\n");
        return;
    }

    printf("\n--- DATOS DE SALA ---\n");
    printf("Codigo: %s\n", s.codigo);
    printf("Capacidad: %d butacas\n", s.capacidad);
    printf("---------------------\n");
}
