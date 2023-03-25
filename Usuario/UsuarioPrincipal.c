#include <stdio.h>
#include "sqlite3.h"
#include <string.h>
#include "UsuarioPrincipal.h"
//los metodos estan creados en UsuarioPrincipal.h
int main() {
    sqlite3 *db;
    int rc;
    rc = sqlite3_open("tiendaBD.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    }
    

    int opcion, talla;
    char tipo[50], nombre[50], color[20];
    char username[50] = "nombre_de_usuario";

    do {
        printf("BIENVENIDO USUARIO, QUE DESEAS HACER?\n");

        printf("1. Ver zapatos\n");
        printf("2. Ver cesta\n");
        printf("3. Mi perfil\n");
        printf("0. Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ver_tipos(db);
                printf("Elija un tipo de zapato: ");
                scanf(" %[^\n]", tipo);

                ver_zapatos_tipo(db, tipo);
                printf("Elija un zapato: ");
                scanf(" %[^\n]", nombre);

                ver_opciones_zapato(db, nombre);
                printf("Elija un color: ");
                scanf(" %[^\n]", color);

                printf("Elija una talla: ");
                scanf("%d", &talla);

                double precio;
                obtener_precio(db, nombre, color, talla, &precio);
                printf("Precio del zapato: $%.2f\n", precio);

                printf("¿Desea agregar este zapato a la cesta? (1.Si, 2.No): ");
                scanf("%d", &opcion);
                if (opcion == 1) {
                    agregar_a_cesta(db, nombre, color, talla, precio); //llama al metodo
                }
                break;
            
            case 2:
                printf("\nCesta:\n");
                ver_cesta();
                printf("\n");
                break;
            
            case 3:
                printf("Estos son los datos de tu perfil\n");
                mostrar_usuario(username); //llama al metodo
                break;
            
            case 0:
                printf("Gracias por usar nuestra tienda. ¡Hasta luego!\n");
                break;
            
            default:
                printf("Opción no válida. Por favor, elija una opción correcta.\n");
                break;
        }
    } while (opcion != 0);

    sqlite3_close(db);
    return 0;
}

