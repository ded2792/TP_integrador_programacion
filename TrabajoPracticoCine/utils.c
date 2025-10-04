#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

// FUNCIONES DE VALIDACIÓN

bool esBisiesto(int anio) {
    return (anio % 4 == 0) && (!(anio % 100 == 0) || (anio % 400 == 0));
}

bool fechaValida(int dia, int mes, int anio) {
    if (anio < 1900 || anio > 2100) return false;
    if (mes < 1 || mes > 12) return false;

    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (esBisiesto(anio)) {
        diasPorMes[1] = 29;
    }

    if (dia < 1 || dia > diasPorMes[mes - 1]) {
        return false;
    }

    return true;
}

Fecha crearFecha(int dia, int mes, int anio) {
    Fecha f;
    f.dia = dia;
    f.mes = mes;
    f.anio = anio;
    return f;
}

Fecha obtenerFechaActual() {
    return crearFecha(3, 10, 2025);  // Fecha actual del TP
}

int calcularEdad(Fecha nacimiento, Fecha actual) {
    int edad = actual.anio - nacimiento.anio;

    if (actual.mes < nacimiento.mes) {
        edad--;
    } else if (actual.mes == nacimiento.mes && actual.dia < nacimiento.dia) {
        edad--;
    }

    return edad;
}

int compararFechas(Fecha fecha1, Fecha fecha2) {
    if (fecha1.anio < fecha2.anio) return -1;
    if (fecha1.anio > fecha2.anio) return 1;

    if (fecha1.mes < fecha2.mes) return -1;
    if (fecha1.mes > fecha2.mes) return 1;

    if (fecha1.dia < fecha2.dia) return -1;
    if (fecha1.dia > fecha2.dia) return 1;

    return 0;
}

bool emailValido(char email[]) {
    int longitud = strlen(email);

    if (longitud < 5) {
        return false;
    }

    int posicionArroba = -1;
    int i;
    for (i = 0; i < longitud; i++) {
        if (email[i] == '@') {
            posicionArroba = i;
            break;
        }
    }

    if (posicionArroba == -1 || posicionArroba == 0 || posicionArroba == longitud - 1) {
        return false;
    }

    bool hayPuntoDespuesDeArroba = false;
    for (i = posicionArroba + 1; i < longitud; i++) {
        if (email[i] == '.') {
            hayPuntoDespuesDeArroba = true;
            break;
        }
    }

    if (!hayPuntoDespuesDeArroba || email[posicionArroba + 1] == '.') {
        return false;
    }

    return true;
}

bool dniValido(int dni) {
    if (dni <= 0) return false;
    if (dni < 1000000 || dni > 99999999) return false;
    return true;
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// PERSISTENCIA: PELÍCULAS EN ARCHIVO .TXT

// Guarda todas las películas en peliculas.txt
// Formato: cantidad\ncodigo|titulo|duracion|clasificacion|idioma|genero|formato
bool guardarPeliculas(Pelicula peliculas[], int cantidad) {
    // Abrimos archivo en modo escritura de texto
    // "w" = write (escritura) - Si existe, lo sobrescribe
    FILE *archivo = fopen("peliculas.txt", "w");

    // Verificamos que se pudo abrir
    if (archivo == NULL) {
        printf("ERROR: No se pudo crear/abrir el archivo peliculas.txt\n");
        return false;
    }

    // Escribimos la cantidad de películas en la primera línea
    // fprintf es como printf pero escribe en un archivo
    fprintf(archivo, "%d\n", cantidad);

    // Escribimos cada película en una línea
    int i;
    for (i = 0; i < cantidad; i++) {
        // Usamos | como separador de campos
        // %s no admite espacios, por eso usamos el título completo
        fprintf(archivo, "%d|%s|%d|%s|%s|%s|%s\n",
                peliculas[i].codigo,
                peliculas[i].titulo,
                peliculas[i].duracion,
                peliculas[i].clasificacion,
                peliculas[i].idioma,
                peliculas[i].genero,
                peliculas[i].formato);
    }

    // Cerramos el archivo (muy importante)
    fclose(archivo);

    return true;  // Éxito
}

// Carga las películas desde peliculas.txt
// Devuelve la cantidad de películas cargadas
int cargarPeliculas(Pelicula peliculas[], int capacidad) {
    // Abrimos archivo en modo lectura de texto
    // "r" = read (lectura)
    FILE *archivo = fopen("peliculas.txt", "r");

    // Si el archivo no existe, no es error
    // Simplemente es la primera vez que se ejecuta el programa
    if (archivo == NULL) {
        return 0;  // 0 películas cargadas
    }

    int cantidad;
    // Leemos la primera línea que tiene la cantidad
    // fscanf es como scanf pero lee desde un archivo
    fscanf(archivo, "%d\n", &cantidad);

    // Verificamos que no exceda la capacidad del array
    if (cantidad > capacidad) {
        printf("ADVERTENCIA: El archivo tiene mas peliculas de las que caben.\n");
        printf("Se cargaran solo las primeras %d.\n", capacidad);
        cantidad = capacidad;
    }

    // Leemos cada película línea por línea
    int i;
    for (i = 0; i < cantidad; i++) {
        // %[^|] significa "lee hasta encontrar |"
        // Esto permite leer strings con espacios
        fscanf(archivo, "%d|%99[^|]|%d|%4[^|]|%29[^|]|%29[^|]|%9[^\n]\n",
               &peliculas[i].codigo,          // Lee hasta |
               peliculas[i].titulo,           // Lee hasta |
               &peliculas[i].duracion,        // Lee hasta |
               peliculas[i].clasificacion,    // Lee hasta |
               peliculas[i].idioma,           // Lee hasta |
               peliculas[i].genero,           // Lee hasta |
               peliculas[i].formato);         // Lee hasta \n (fin de línea)
    }

    // Cerramos el archivo
    fclose(archivo);

    return cantidad;  // Devolvemos cuántas películas se cargaron
}

// PERSISTENCIA: SALAS EN ARCHIVO .TXT

bool guardarSalas(Sala salas[], int cantidad) {
    FILE *archivo = fopen("salas.txt", "w");

    if (archivo == NULL) {
        printf("ERROR: No se pudo crear/abrir el archivo salas.txt\n");
        return false;
    }

    // Primera línea: cantidad de salas
    fprintf(archivo, "%d\n", cantidad);

    // Cada sala en una línea: codigo|capacidad
    int i;
    for (i = 0; i < cantidad; i++) {
        fprintf(archivo, "%s|%d\n",
                salas[i].codigo,
                salas[i].capacidad);
    }

    fclose(archivo);
    return true;
}

int cargarSalas(Sala salas[], int capacidad) {
    FILE *archivo = fopen("salas.txt", "r");

    if (archivo == NULL) {
        return 0;  // Archivo no existe
    }

    int cantidad;
    fscanf(archivo, "%d\n", &cantidad);

    if (cantidad > capacidad) {
        cantidad = capacidad;
    }

    int i;
    for (i = 0; i < cantidad; i++) {
        // Lee codigo hasta | y luego capacidad hasta \n
        fscanf(archivo, "%19[^|]|%d\n",
               salas[i].codigo,
               &salas[i].capacidad);
    }

    fclose(archivo);
    return cantidad;
}

// PERSISTENCIA: CLIENTES EN ARCHIVO .TXT

bool guardarClientes(Cliente clientes[], int cantidad) {
    FILE *archivo = fopen("clientes.txt", "w");

    if (archivo == NULL) {
        printf("ERROR: No se pudo crear/abrir el archivo clientes.txt\n");
        return false;
    }

    // Primera línea: cantidad de clientes
    fprintf(archivo, "%d\n", cantidad);

    // Cada cliente: nombre|dni|email|password|dia|mes|anio
    int i;
    for (i = 0; i < cantidad; i++) {
        fprintf(archivo, "%s|%d|%s|%s|%d|%d|%d\n",
                clientes[i].nombre,
                clientes[i].dni,
                clientes[i].email,
                clientes[i].password,
                clientes[i].fechaNacimiento.dia,
                clientes[i].fechaNacimiento.mes,
                clientes[i].fechaNacimiento.anio);
    }

    fclose(archivo);
    return true;
}

int cargarClientes(Cliente clientes[], int capacidad) {
    FILE *archivo = fopen("clientes.txt", "r");

    if (archivo == NULL) {
        return 0;
// Archivo no existe
    }

    int cantidad;
    fscanf(archivo, "%d\n", &cantidad);

    if (cantidad > capacidad) {
        cantidad = capacidad;
    }

    int i;
    for (i = 0; i < cantidad; i++) {
        // Lee todos los campos separados por |
        fscanf(archivo, "%49[^|]|%d|%99[^|]|%49[^|]|%d|%d|%d\n",
               clientes[i].nombre,
               &clientes[i].dni,
               clientes[i].email,
               clientes[i].password,
               &clientes[i].fechaNacimiento.dia,
               &clientes[i].fechaNacimiento.mes,
               &clientes[i].fechaNacimiento.anio);
    }

    fclose(archivo);
    return cantidad;
}
