#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // ← AGREGAR para strcmp
#include "pelicula.h"
#include "sala.h"
#include "cliente.h"
#include "utils.h"

// Definimos tamaños máximos
#define MAX_PELICULAS 100
#define MAX_SALAS 20
#define MAX_CLIENTES 500

// ===== VARIABLES GLOBALES =====
Pelicula peliculas[MAX_PELICULAS];
int cantidadPeliculas = 0;

Sala salas[MAX_SALAS];
int cantidadSalas = 0;

Cliente clientes[MAX_CLIENTES];
int cantidadClientes = 0;

// ==============================================
// FUNCIONES DE PERSISTENCIA (ya las teníamos)
// ==============================================

void cargarTodosDatos() {
    printf("\n=== CARGANDO BASE DE DATOS ===\n");

    cantidadPeliculas = cargarPeliculas(peliculas, MAX_PELICULAS);
    printf("Peliculas cargadas: %d\n", cantidadPeliculas);

    cantidadSalas = cargarSalas(salas, MAX_SALAS);
    printf("Salas cargadas: %d\n", cantidadSalas);

    cantidadClientes = cargarClientes(clientes, MAX_CLIENTES);
    printf("Clientes cargados: %d\n", cantidadClientes);

    printf("==============================\n\n");
    printf("Presione Enter para continuar...");
    limpiarBuffer();
    getchar();
}

void guardarTodosDatos() {
    printf("\n=== GUARDANDO BASE DE DATOS ===\n");

    if (guardarPeliculas(peliculas, cantidadPeliculas)) {
        printf("Peliculas guardadas: %d\n", cantidadPeliculas);
    }

    if (guardarSalas(salas, cantidadSalas)) {
        printf("Salas guardadas: %d\n", cantidadSalas);
    }

    if (guardarClientes(clientes, cantidadClientes)) {
        printf("Clientes guardados: %d\n", cantidadClientes);
    }

    printf("===============================\n\n");
}

// ==============================================
// FUNCIONES ABM DE PELÍCULAS (ya las teníamos)
// ==============================================

int buscarPeliculaPorCodigo(int codigo) {
    int i;
    for (i = 0; i < cantidadPeliculas; i++) {
        if (peliculas[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void altaPelicula() {
    system("cls");

    if (cantidadPeliculas >= MAX_PELICULAS) {
        printf("\nERROR: No hay espacio para mas peliculas.\n");
        return;
    }

    Pelicula nueva = crearPelicula();

    if (peliculaVacia(nueva)) {
        return;
    }

    if (buscarPeliculaPorCodigo(nueva.codigo) != -1) {
        printf("\nERROR: Ya existe una pelicula con ese codigo.\n");
        return;
    }

    peliculas[cantidadPeliculas] = nueva;
    cantidadPeliculas++;
    printf("\nPelicula agregada correctamente!\n");

    guardarPeliculas(peliculas, cantidadPeliculas);
}

void bajaPelicula() {
    system("cls");

    if (cantidadPeliculas == 0) {
        printf("\nNo hay peliculas registradas.\n");
        return;
    }

    int codigo;
    printf("\n=== BAJA DE PELICULA ===\n");
    printf("Ingrese codigo de pelicula a eliminar: ");
    scanf("%d", &codigo);

    int indice = buscarPeliculaPorCodigo(codigo);

    if (indice == -1) {
        printf("\nERROR: No existe pelicula con ese codigo.\n");
        return;
    }

    printf("\nPelicula a eliminar:");
    mostrarPelicula(peliculas[indice]);

    char confirma;
    printf("\nEsta seguro? (S/N): ");
    scanf(" %c", &confirma);

    if (confirma == 'S' || confirma == 's') {
        int i;
        for (i = indice; i < cantidadPeliculas - 1; i++) {
            peliculas[i] = peliculas[i + 1];
        }

        peliculas[cantidadPeliculas - 1] = peliculaVaciaCrear();
        cantidadPeliculas--;

        printf("\nPelicula eliminada correctamente!\n");
        guardarPeliculas(peliculas, cantidadPeliculas);
    } else {
        printf("\nOperacion cancelada.\n");
    }
}

void modificarPelicula() {
    system("cls");

    if (cantidadPeliculas == 0) {
        printf("\nNo hay peliculas registradas.\n");
        return;
    }

    int codigo;
    printf("\n=== MODIFICACION DE PELICULA ===\n");
    printf("Ingrese codigo de pelicula a modificar: ");
    scanf("%d", &codigo);

    int indice = buscarPeliculaPorCodigo(codigo);

    if (indice == -1) {
        printf("\nERROR: No existe pelicula con ese codigo.\n");
        return;
    }

    printf("\nPelicula actual:");
    mostrarPelicula(peliculas[indice]);

    printf("\nIngrese nuevos datos:\n");
    Pelicula modificada = crearPelicula();

    if (!peliculaVacia(modificada)) {
        modificada.codigo = codigo;
        peliculas[indice] = modificada;
        printf("\nPelicula modificada correctamente!\n");

        guardarPeliculas(peliculas, cantidadPeliculas);
    }
}

void listarPeliculas() {
    system("cls");
    printf("\n=== LISTADO DE PELICULAS ===\n");

    if (cantidadPeliculas == 0) {
        printf("No hay peliculas registradas.\n");
        return;
    }

    int i;
    for (i = 0; i < cantidadPeliculas; i++) {
        mostrarPelicula(peliculas[i]);
    }
}

void menuPeliculas() {
    int opcion = -1;

    do {
        system("cls");
        printf("\n=== GESTION DE PELICULAS ===\n");
        printf("1 - Alta de pelicula\n");
        printf("2 - Baja de pelicula\n");
        printf("3 - Modificar pelicula\n");
        printf("4 - Listar peliculas\n");
        printf("0 - Volver al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                altaPelicula();
                break;
            case 2:
                bajaPelicula();
                break;
            case 3:
                modificarPelicula();
                break;
            case 4:
                listarPeliculas();
                break;
            case 0:
                printf("\nVolviendo al menu principal...\n");
                break;
            default:
                printf("\nOpcion invalida.\n");
                break;
        }

        if (opcion != 0) {
            printf("\nPresione Enter para continuar...");
            while (getchar() != '\n');
            getchar();
        }

    } while (opcion != 0);
}

// ==============================================
// FUNCIONES ABM DE SALAS ← NUEVO
// ==============================================

// Busca una sala por código
// Devuelve el índice donde está, o -1 si no existe
// ¿Por qué strcmp? Porque el código es un string, no un int
int buscarSalaPorCodigo(char codigo[]) {
    int i;
    for (i = 0; i < cantidadSalas; i++) {
        // strcmp compara strings
        // Devuelve 0 si son iguales
        if (strcmp(salas[i].codigo, codigo) == 0) {
            return i;  // Encontrada
        }
    }
    return -1;  // No encontrada
}

// Función para dar de ALTA una sala
void altaSala() {
    system("cls");

    // Verificar espacio disponible
    if (cantidadSalas >= MAX_SALAS) {
        printf("\nERROR: No hay espacio para mas salas.\n");
        printf("Maximo permitido: %d salas.\n", MAX_SALAS);
        return;
    }

    // Crear nueva sala
    Sala nueva = crearSala();

    // Verificar que no se canceló la creación
    if (salaVacia(nueva)) {
        return;
    }

    // Verificar que no exista ya ese código
    if (buscarSalaPorCodigo(nueva.codigo) != -1) {
        printf("\nERROR: Ya existe una sala con el codigo '%s'.\n", nueva.codigo);
        return;
    }

    // Agregar al array
    salas[cantidadSalas] = nueva;
    cantidadSalas++;

    printf("\nSala agregada correctamente!\n");

    // Guardar automáticamente
    guardarSalas(salas, cantidadSalas);
}

// Función para dar de BAJA una sala
void bajaSala() {
    system("cls");

    if (cantidadSalas == 0) {
        printf("\nNo hay salas registradas.\n");
        return;
    }

    char codigo[MAX_CODIGO_SALA];
    printf("\n=== BAJA DE SALA ===\n");

    // Limpiamos buffer antes de leer string
    while (getchar() != '\n');

    printf("Ingrese codigo de sala a eliminar: ");
    scanf(" %19[^\n]", codigo);

    // Convertir a mayúsculas para la búsqueda
    int i;
    for (i = 0; codigo[i] != '\0'; i++) {
        if (codigo[i] >= 'a' && codigo[i] <= 'z') {
            codigo[i] = codigo[i] - 32;
        }
    }

    int indice = buscarSalaPorCodigo(codigo);

    if (indice == -1) {
        printf("\nERROR: No existe sala con el codigo '%s'.\n", codigo);
        return;
    }

    // Mostramos la sala que se va a eliminar
    printf("\nSala a eliminar:");
    mostrarSala(salas[indice]);

    // Confirmación
    char confirma;
    printf("\nEsta seguro? (S/N): ");
    scanf(" %c", &confirma);

    if (confirma == 'S' || confirma == 's') {
        // Desplazamos elementos hacia arriba
        for (i = indice; i < cantidadSalas - 1; i++) {
            salas[i] = salas[i + 1];
        }

        // Limpiamos última posición
        salas[cantidadSalas - 1] = salaVaciaCrear();

        cantidadSalas--;

        printf("\nSala eliminada correctamente!\n");

        // Guardar automáticamente
        guardarSalas(salas, cantidadSalas);
    } else {
        printf("\nOperacion cancelada.\n");
    }
}

// Función para MODIFICAR una sala
void modificarSala() {
    system("cls");

    if (cantidadSalas == 0) {
        printf("\nNo hay salas registradas.\n");
        return;
    }

    char codigo[MAX_CODIGO_SALA];
    printf("\n=== MODIFICACION DE SALA ===\n");

    // Limpiamos buffer
    while (getchar() != '\n');

    printf("Ingrese codigo de sala a modificar: ");
    scanf(" %19[^\n]", codigo);

    // Convertir a mayúsculas
    int i;
    for (i = 0; codigo[i] != '\0'; i++) {
        if (codigo[i] >= 'a' && codigo[i] <= 'z') {
            codigo[i] = codigo[i] - 32;
        }
    }

    int indice = buscarSalaPorCodigo(codigo);

    if (indice == -1) {
        printf("\nERROR: No existe sala con el codigo '%s'.\n", codigo);
        return;
    }

    printf("\nSala actual:");
    mostrarSala(salas[indice]);

    printf("\nIngrese nuevos datos:\n");
    Sala modificada = crearSala();

    if (!salaVacia(modificada)) {
        // Mantenemos el código original (no se puede cambiar)
        strcpy(modificada.codigo, codigo);

        salas[indice] = modificada;
        printf("\nSala modificada correctamente!\n");

        // Guardar automáticamente
        guardarSalas(salas, cantidadSalas);
    }
}

// Función para LISTAR todas las salas
void listarSalas() {
    system("cls");
    printf("\n=== LISTADO DE SALAS ===\n");

    if (cantidadSalas == 0) {
        printf("No hay salas registradas.\n");
        return;
    }

    printf("\nTotal de salas: %d\n", cantidadSalas);

    int i;
    for (i = 0; i < cantidadSalas; i++) {
        mostrarSala(salas[i]);
    }

    // Calcular capacidad total del cine
    int capacidadTotal = 0;
    for (i = 0; i < cantidadSalas; i++) {
        capacidadTotal += salas[i].capacidad;
    }

    printf("\n=========================\n");
    printf("CAPACIDAD TOTAL DEL CINE: %d butacas\n", capacidadTotal);
    printf("=========================\n");
}

// Menú de gestión de salas
void menuSalas() {
    int opcion = -1;

    do {
        system("cls");
        printf("\n=== GESTION DE SALAS ===\n");
        printf("1 - Alta de sala\n");
        printf("2 - Baja de sala\n");
        printf("3 - Modificar sala\n");
        printf("4 - Listar salas\n");
        printf("0 - Volver al menu anterior\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                altaSala();
                break;
            case 2:
                bajaSala();
                break;
            case 3:
                modificarSala();
                break;
            case 4:
                listarSalas();
                break;
            case 0:
                printf("\nVolviendo al menu anterior...\n");
                break;
            default:
                printf("\nOpcion invalida.\n");
                break;
        }

        if (opcion != 0) {
            printf("\nPresione Enter para continuar...");
            while (getchar() != '\n');
            getchar();
        }

    } while (opcion != 0);
}

// ==============================================
// MENÚ DE ADMINISTRADOR ← ACTUALIZADO
// ==============================================

void menuAdministrador() {
    int opcion = -1;

    do {
        system("cls");
        printf("\n=== MENU ADMINISTRADOR ===\n");
        printf("1 - Gestion de Peliculas\n");
        printf("2 - Gestion de Salas\n");
        printf("3 - Gestion de Clientes\n");
        printf("4 - Gestion de Funciones\n");
        printf("0 - Volver al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                menuPeliculas();
                break;
            case 2:
                menuSalas();  // ← NUEVO
                break;
            case 3:
                printf("\n(Proximamente: Gestion de Clientes)\n");
                break;
            case 4:
                printf("\n(Proximamente: Gestion de Funciones)\n");
                break;
            case 0:
                printf("\nVolviendo al menu principal...\n");
                break;
            default:
                printf("\nOpcion invalida.\n");
                break;
        }

        if (opcion != 0) {
            printf("\nPresione Enter para continuar...");
            while (getchar() != '\n');
            getchar();
        }

    } while (opcion != 0);
}

// ==============================================
// FUNCIÓN PRINCIPAL
// ==============================================

int main() {
    // Cargar datos al iniciar
    cargarTodosDatos();

    // Inicializar arrays vacíos si es primera ejecución
    if (cantidadPeliculas == 0) {
        int i;
        for (i = 0; i < MAX_PELICULAS; i++) {
            peliculas[i] = peliculaVaciaCrear();
        }
    }

    if (cantidadSalas == 0) {
        int i;
        for (i = 0; i < MAX_SALAS; i++) {
            salas[i] = salaVaciaCrear();
        }
    }

    int opcion = -1;

    do {
        system("cls");
        printf("\n=== CINE NACIONAL ===\n");
        printf("1 - Operar como Cliente\n");
        printf("2 - Operar como Administrador\n");
        printf("0 - Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\n>>> Menu Cliente <<<\n");
                printf("(Proximamente...)\n");
                break;

            case 2:
                menuAdministrador();  // ← ACTUALIZADO
                break;

            case 0:
                guardarTodosDatos();
                printf("\nGracias por usar el sistema. Hasta luego!\n");
                break;

            default:
                printf("\nOpcion invalida. Intente de nuevo.\n");
                break;
        }

        if (opcion != 0) {
            printf("\nPresione Enter para continuar...");
            while (getchar() != '\n');
            getchar();
        }

    } while (opcion != 0);

    return 0;
}
