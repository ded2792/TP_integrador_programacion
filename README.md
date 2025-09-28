Trabajo Práctico Integrador 2025 – Sistema de Reservas de Cine

Este repositorio contiene el desarrollo del Trabajo Práctico Integrador de la materia Programación de Computadoras (Licenciatura en Sistemas - UNLa).

El proyecto consiste en la implementación de un sistema de reservas de entradas de cine utilizando el lenguaje C.

🎬 Descripción del Proyecto

Un cine nacional solicitó la creación de un sistema para gestionar sus funciones y reservas.

El sistema permitirá:

Registrar películas, salas y clientes.

Programar funciones asignando película, sala, fecha, hora y precio.

Gestionar reservas de entradas, validando edad, disponibilidad y cantidad máxima.

Cancelar reservas y registrar asistencia a funciones.

Generar reportes con información relevante (ej. funciones programadas, reservas por cliente, etc.).

🛠️ Funcionalidades
Gestión de entidades

Alta, baja y modificación de:

Películas (código, título, duración, clasificación, idioma, género, formato).

Salas (código y capacidad de butacas).

Clientes (nombre, DNI, email, contraseña y fecha de nacimiento).

Programación de funciones en salas específicas.

Reservas

Búsqueda de funciones por película, idioma, género y disponibilidad.

Reserva de entradas por cliente:

Mayores de edad: hasta 5 entradas por función.

Menores de edad: solo 1 entrada.

Control de butacas disponibles y reglas de clasificación por edad.

Identificador único de reserva y estado: activa, cancelada o asistida.

Reglas y validaciones

No se permiten funciones solapadas en la misma sala (duración + limpieza).

No se pueden reservar entradas para funciones pasadas.

Validación de datos de entrada (DNI único, emails sin repetir, contraseñas con longitud mínima).

Descuentos aplicables según el día de la semana (ej. miércoles a mitad de precio).

Reportes

Listado de funciones programadas.

Historial de reservas de cada cliente.

Estado de ocupación de salas.

⚙️ Compilación y Ejecución

Todos los programas están escritos en C estándar y pueden compilarse con GCC u otro compilador compatible.

# Compilar
gcc main.c -o cine

# Ejecutar
./cine


En Windows se puede usar Code::Blocks, Visual Studio o MinGW.

🎯 Objetivos de Aprendizaje

Diseñar e implementar un sistema completo en lenguaje C.

Aplicar estructuras, funciones y modularización.

Manejar validaciones de datos y reglas de negocio.

Practicar organización de proyectos en repositorios.

✨ Autor

Desarrollado por Diego Delgado como parte de la cursada de Programación en la Universidad Nacional de Lanús (UNLa).# TP_integrador_programacion
