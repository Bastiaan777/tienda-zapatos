#include <stdio.h>
#include "sqlite3.h"

int main()
{

    int opcion;

    printf("BIENVENIDO ADMINISTRADOR, QUE DESEAS HACER?\n");

    printf("1. Añadir y eliminar zapatos\n");
    printf("2. Visualizar clientes\n");
    printf("3. Visualizar pedidos\n");
    printf("4. Crear administrador\n");
    printf("5. Salir\n");

    printf("Seleccione la opcion que desea");
    scanf("%d", &opcion);

    switch (opcion)
    {

    case 1:

        printf("Has elegido la opcion de añadir o eliminar usuarios\n");

        printf("base de datos abierta/n");

        break;

    case 2:

        printf("Has elegido ver clientes\n");
        sqlite3 *db;

        printf("base de datos abierta/n");

        break;

    case 3:

        printf("Has elegido ver los pedidos\n");
        break;

    case 4:

        printf("Has elegido crear un administrador\n");
        break;

    case 5:

        printf("Salir\n");
        break;

    default:
        printf("opcion invalida\n");
        break;
    }

    return 0;
}