#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crearUsuario.h"


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

