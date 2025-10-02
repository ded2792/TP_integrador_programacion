#ifndef RESERVA_H_INCLUDED
#define RESERVA_H_INCLUDED

#include <stdbool.h>

#define MAX_ESTADO 15

// Estructura que representa una reserva de entrada
typedef struct {
    int id;                      // ID único de reserva
    int dniCliente;              // Referencia al cliente
    int idFuncion;               // Referencia a la función
    char estado[MAX_ESTADO];     // "activa", "cancelada", "asistida"
} Reserva;

// Funciones para manipular reservas
Reserva crearReserva(int dniCliente, int idFuncion);
void mostrarReserva(Reserva r);
bool reservaVacia(Reserva r);
Reserva reservaVaciaCrear();

// Funciones para cambiar estado (VAN A ESTAR EN reserva.c)
void cancelarReserva(Reserva *r);
void marcarAsistida(Reserva *r);

#endif // RESERVA_H_INCLUDED
