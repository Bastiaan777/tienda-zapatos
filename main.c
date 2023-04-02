#include <stdio.h>
#include "crearUsuario.h"
#include "crearAdministrador.h"
#include "AnyadirZapatos.h"
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"
#include "EliminarZapatos.h"
#include "UsuarioPrincipal.h"
#include <time.h>


#define MAX_USUARIOS 100
#define MAX_LEN 50
#define MAX_ADMINS 100

//FUNCION PARA IMPRIMIR TODOS LOS ZAPATOS DE LA BD EN ELIMINAR ZAPATO
int imprimirZapatos(void *data, int tamanyo, char **zapato, char **nombreColumna){
   int i;
   for(i=0; i<tamanyo; i++){
      printf("%s = %s  ", nombreColumna[i], zapato[i]);
   }
   printf("\n");
   return 0;
}

int main()
{

    FILE *archivo;
    char admins[MAX_ADMINS][3][MAX_LEN];
    char nombre[MAX_LEN], contrasena[MAX_LEN], codigo[MAX_LEN];
    int num_admins = 0;
    int i, encontrado = 0;
    char usuarios[MAX_USUARIOS][2][MAX_LEN];
    int num_usuarios = 0;

    int opcion;

    printf("BIENVENIDO, ¿ERES ADMINISTRADOR O USUARIO?\n");

    printf("1. Crear Usuario\n");
    printf("2. Crear Administrador\n");
    printf("3. Login de Usuario\n");
    printf("4. Login de Administrador\n");

    printf("Seleccione la opcion que desea: ");
    scanf("%d", &opcion);

    switch (opcion)
    {

    case 1:;

        read_users_file();
        printf("Bienvenido al sistema de registro de usuarios\n");
        while (1)
        {
            printf("¿Que deseas hacer?\n");
            printf("1. Crear usuario\n");
            printf("2. Salir\n");
            int choice;
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                create_user();
                break;
            case 2:
                printf("Adiós!\n");
                exit(0);
            default:
                printf("Opción inválida\n");
            }
        }
        return 0;
        break;

    case 2:;

        read_admins_file();
        printf("Bienvenido al sistema de registro de administradores\n");
        while (1)
        {
            printf("¿Que deseas hacer?\n");
            printf("1. Crear administrador\n");
            printf("2. Salir\n");
            int choice;
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:;
                create_admin();
                break;
            case 2:;
                printf("Adios!\n");
                exit(0);
            default:;
                printf("Opcion invalida\n");
            }
        }
        return 0;
        break;

    case 3:;

        archivo = fopen("users.txt", "r"); // abrir archivo en modo lectura

        if (archivo == NULL)
        {
            printf("Error al abrir el archivo.\n");
            return 1; // salir del programa con código de error
        }

        // leer los usuarios y contraseñas del archivo y guardarlos en la matriz usuarios
        while (fscanf(archivo, "%[^;];%s\n", usuarios[num_usuarios][0], usuarios[num_usuarios][1]) != EOF)
        {
            num_usuarios++;
        }

        fclose(archivo); // cerrar archivo

        printf("Introduce tu nombre de usuario: ");
        scanf("%s", nombre);

        printf("Introduce tu contrasenia: ");
        scanf("%s", contrasena);

        // comprobar si el nombre de usuario y contraseña introducidos coinciden con alguno en el archivo
        for (i = 0; i < num_usuarios; i++)
        {
            if (strcmp(usuarios[i][0], nombre) == 0 && strcmp(usuarios[i][1], contrasena) == 0)
            {
                encontrado = 1;
                break;
            }
        }

        // mostrar mensaje de éxito o fallo en el inicio de sesión
        if (encontrado)
        {
            printf("Inicio de sesion exitoso!\n");
            //aqui empieza el main de usuario principal
            sqlite3 *db;
             int rc;
             rc = sqlite3_open("tiendaBD.db", &db);

            if (rc)
            {
                fprintf(stderr, "No se puede abrir la BD: %s\n", sqlite3_errmsg(db));
                return 0;
            }

            int opcion;
            int talla;
            char tipo[50], nombre[50], color[20];
            char username[50] = "nombre_de_usuario";

            do
            {
                printf("BIENVENIDO USUARIO, QUE DESEAS HACER?\n");

                printf("1. Ver zapatos\n");
                printf("2. Ver cesta\n");
                printf("3. Mi perfil\n");
                printf("4. Comprar\n");
                printf("0. Salir\n");
                scanf("%d", &opcion);

                switch (opcion)
                {
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
                    if (opcion == 1)
                    {
                        agregar_a_cesta(db, nombre, color, talla, precio); // llama al metodo
                    }
                    break;

                case 2:
                    printf("\nCesta:\n");
                    ver_cesta();
                    printf("\n");
                    break;

                case 3:
                    printf("Estos son los datos de tu perfil\n");
                    mostrar_usuario(username); // llama al metodo
                    break;

                case 4:
                    printf("\nComprar cesta:\n");
                    comprar_cesta(db, username);
                    printf("\n");
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
        else
        {
            printf("Nombre de usuario o contraseña incorrectos.\n");
        }

        return 0;
        break;

    case 4:;

        archivo = fopen("admins.txt", "r"); // abrir archivo en modo lectura

        if (archivo == NULL)
        {
            printf("Error al abrir el archivo.\n");
            return 1; // salir del programa con código de error
        }

        // leer los administradores y contraseñas del archivo y guardarlos en la matriz admins
        while (fscanf(archivo, "%[^;];%[^;];%s\n", admins[num_admins][0], admins[num_admins][1], admins[num_admins][2]) != EOF)
        {
            num_admins++;
        }

        fclose(archivo); // cerrar archivo

        printf("Introduce tu nombre de administrador: ");
        scanf("%s", nombre);

        printf("Introduce tu contrasenia: ");
        scanf("%s", contrasena);

        printf("Introduce tu codigo de administrador: ");
        scanf("%s", codigo);

        // comprobar si el nombre de usuario, contraseña y código introducidos coinciden con alguno en el archivo
        for (i = 0; i < num_admins; i++)
        {
            if (strcmp(admins[i][0], nombre) == 0 && strcmp(admins[i][1], contrasena) == 0 && strcmp(admins[i][2], codigo) == 0)
            {
                encontrado = 1;
                break;
            }
        }

        // mostrar mensaje de éxito o fallo en el inicio de sesión
        if (encontrado)
        {
            printf("Inicio de sesion exitoso como administrador!\n");

            int opciones2;

            printf("1. Aniadir zapatos\n");
            printf("2. Eliminar zapatos\n");

            printf("Seleccione la opcion que desea: ");
            scanf("%d", &opciones2);

            Zapateria zapateria;
            
            switch (opciones2)
            {

            case 1:;

                Zapato zp;

                printf("Has escogido la opcion de aniadir zapatos: \n");
                Zapateria_init(&zapateria, "zapateria.db");
                //Zapato zapato = {0, "Adidas", "Superstar", 100.0};

                printf("ID del zapato a aniadir: ");
                scanf("%d", &zp.id);

                printf("Tipo de zapato a aniadir: ");
                scanf("%s", &zp.tipo);

                printf("Nombre del zapato a aniadir: ");
                scanf("%s", &zp.nombre);

                printf("Color del zapato a aniadir: ");
                scanf("%s", &zp.color);

                printf("Talla del zapato aniadir: ");
                scanf("%f", &zp.talla);

                printf("Precio del zapato aniadir: ");
                scanf("%f", &zp.precio);

                Zapateria_add_zapato(&zapateria, &zp);
                Zapateria_close(&zapateria);
                break;

            case 2: ; //se va a elimiar solo pasandole el id

                printf("Has escogido la opcion de eliminar zapatos: \n");
                
                
                Zapateria_init(&zapateria, "zapateria.db");

                char *zErrMsg = 0;
                int rc;
                rc = sqlite3_exec(zapateria.db, "SELECT * FROM zapatos", imprimirZapatos, 0, &zErrMsg);
                
                if( rc != SQLITE_OK ) {
                    fprintf(stderr, "Error al ejecutar la consulta: %s\n", zErrMsg);
                    sqlite3_free(zErrMsg);
                } 


                printf("ID del zapato a eliminar: ");
                scanf("%d", &zp.id);
                printf("Si el codigo introducido estaba en la BD ha sido eliminado\n");

                Zapateria_eliminar_zapato_Elm(&zapateria, zp.id); // Elimina el zapato con id 1
                Zapateria_close_Elm(&zapateria);

                break;
            }
            
             
        }

        else
            {
            printf("Nombre de usuario, contrasenia o codigo de administrador incorrectos.\n");
            }
             return 0;

            break;
        
        default:
            printf("opcion invalida\n");
            break;

        

        return 0;
    }
}