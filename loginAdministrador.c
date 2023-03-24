#include <stdio.h>
#include <string.h>

#define MAX_ADMINS 100   // número máximo de administradores permitidos
#define MAX_LEN 50       // longitud máxima para el nombre de usuario, contraseña y código

int main() {
    FILE* archivo;
    char admins[MAX_ADMINS][3][MAX_LEN];
    char nombre[MAX_LEN], contrasena[MAX_LEN], codigo[MAX_LEN];
    int num_admins = 0;
    int i, encontrado = 0;

    archivo = fopen("admins.txt", "r"); // abrir archivo en modo lectura

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1; // salir del programa con código de error
    }

    // leer los administradores y contraseñas del archivo y guardarlos en la matriz admins
    while (fscanf(archivo, "%[^;];%[^;];%s\n", admins[num_admins][0], admins[num_admins][1], admins[num_admins][2]) != EOF) {
        num_admins++;
    }

    fclose(archivo); // cerrar archivo

    printf("Introduce tu nombre de usuario: ");
    scanf("%s", nombre);

    printf("Introduce tu contrasenia: ");
    scanf("%s", contrasena);

    printf("Introduce tu codigo de administrador: ");
    scanf("%s", codigo);

    // comprobar si el nombre de usuario, contraseña y código introducidos coinciden con alguno en el archivo
    for (i = 0; i < num_admins; i++) {
        if (strcmp(admins[i][0], nombre) == 0 && strcmp(admins[i][1], contrasena) == 0 && strcmp(admins[i][2], codigo) == 0) {
            encontrado = 1;
            break;
        }
    }

    // mostrar mensaje de éxito o fallo en el inicio de sesión
    if (encontrado) {
        printf("Inicio de sesion exitoso como administrador!\n");
    } else {
        printf("Nombre de usuario, contrasenia o codigo de administrador incorrectos.\n");
    }

    return 0; // salir del programa con código de éxito
}