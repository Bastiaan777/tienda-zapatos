#include <stdio.h>
#include <string.h>

#define MAX_USUARIOS 100  // número máximo de usuarios permitidos
#define MAX_LEN 50        // longitud máxima para el nombre de usuario y contraseña

int main() {
    FILE* archivo;
    char usuarios[MAX_USUARIOS][2][MAX_LEN];
    char nombre[MAX_LEN], contrasena[MAX_LEN];
    int num_usuarios = 0;
    int i, encontrado = 0;

    archivo = fopen("users.txt", "r"); // abrir archivo en modo lectura

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1; // salir del programa con código de error
    }

    // leer los usuarios y contraseñas del archivo y guardarlos en la matriz usuarios
    while (fscanf(archivo, "%[^;];%s\n", usuarios[num_usuarios][0], usuarios[num_usuarios][1]) != EOF) {
        num_usuarios++;
    }

    fclose(archivo); // cerrar archivo

    printf("Introduce tu nombre de usuario: ");
    scanf("%s", nombre);

    printf("Introduce tu contraseña: ");
    scanf("%s", contrasena);

    // comprobar si el nombre de usuario y contraseña introducidos coinciden con alguno en el archivo
    for (i = 0; i < num_usuarios; i++) {
        if (strcmp(usuarios[i][0], nombre) == 0 && strcmp(usuarios[i][1], contrasena) == 0) {
            encontrado = 1;
            break;
        }
    }

    // mostrar mensaje de éxito o fallo en el inicio de sesión
    if (encontrado) {
        printf("¡Inicio de sesión exitoso!\n");
    } else {
        printf("Nombre de usuario o contraseña incorrectos.\n");
    }

    return 0; // salir del programa con código de éxito
}
