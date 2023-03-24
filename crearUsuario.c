#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100 // máximo número de usuarios que podemos tener

typedef struct {
    char username[50];
    char password[50];
} User;

User users[MAX_USERS]; // arreglo para almacenar todos los usuarios

int num_users = 0; // contador de usuarios actuales

void read_users_file() {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        return;
    }
    while (!feof(file)) {
        fscanf(file, "%s %s", users[num_users].username, users[num_users].password);
        num_users++;
    }
    fclose(file);
}

void write_users_file() {
    FILE *file = fopen("users.txt", "w");
    if (file == NULL) {
        printf("Error al crear archivo de usuarios\n");
        return;
    }
    for (int i = 0; i < num_users; i++) {
        fprintf(file, "%s;%s\n", users[i].username, users[i].password);
    }
    fclose(file);
}

void create_user() {
    char username[50];
    char password[50];
    printf("Ingresa el nombre de usuario: ");
    scanf("%s", username);
    printf("Ingresa la contraseña: ");
    scanf("%s", password);
    if (num_users >= MAX_USERS) {
        printf("No se pueden crear más usuarios\n");
        return;
    }
    strcpy(users[num_users].username, username);
    strcpy(users[num_users].password, password);
    num_users++;
    write_users_file();
    printf("Usuario creado exitosamente\n");
}

int main() {
    read_users_file();
    printf("Bienvenido al sistema de registro de usuarios\n");
    while (1) {
        printf("¿Que deseas hacer?\n");
        printf("1. Crear usuario\n");
        printf("2. Salir\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
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
}