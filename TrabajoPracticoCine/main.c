#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcion = -1;

    do {
        system("cls");
        printf("\n=== Cine Nacional ===\n");
        printf("1 - Operar como Cliente\n");
        printf("2 - Operar como Administrador\n");
        printf("0 - Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\n>>> Menu Cliente <<<\n");
                /*
                va a ir los subsmenus del cliente, crear usuario, elegir pelicular, etc
                */
                break;

            case 2:
                printf("\n>>> Menu Administrador <<<\n");
                /*
                lo mismo pero las opciones van a ser la de gestionar salas, agregar peliculas, etc
                */
                break;

            case 0:
                printf("\nGracias por usar el sistema. Hasta luego!\n");
                break;

            default:
                printf("\nOpcion invalida. Intente de nuevo.\n");
                break;
        }

        if (opcion != 0) {
            printf("\nPresione Enter para continuar..."); // limpiar buffer
            while ((opcion = getchar()) != '\n' && opcion != EOF); // tiene que ingresar el enter el usuario
            getchar();
        }

    } while (opcion != 0);

    return 0;
}
