#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crearAdministrador.h"

Admin admin[MAX_ADMIN]; // arreglo para almacenar todos los usuarios

int num_admin = 0; // contador de usuarios actuales

void read_admins_file()
{
    FILE *file = fopen("admins.txt", "r");
    if (file == NULL)
    {
        return;
    }
    num_admin = 0; // reinicia el contador
    while (!feof(file))
    {
        if (fscanf(file, "%[^;];%[^;];%s", admin[num_admin].username, admin[num_admin].password, admin[num_admin].codigo) != 3)
        {
            break; // termina si la línea leída no tiene tres elementos
        }
        num_admin++; // aumenta el contador al inicio
    }
    fclose(file);
}

/*void read_admins_file() {
    FILE *file = fopen("admins.txt", "r");
    if (file == NULL) {
        return;
    }
    while (!feof(file)) {
        fscanf(file, "%s %s %s", admin[num_admin].username, admin[num_admin].password, admin[num_admin].codigo);
        num_admin++;
    }
    fclose(file);
}*/
void write_admins_file()
{
    FILE *file = fopen("admins.txt", "w");
    if (file == NULL)
    {
        printf("Error al crear archivo de usuarios\n");
        return;
    }
    for (int i = 0; i < num_admin; i++)
    {
        fprintf(file, "%s;%s;%s\n", admin[i].username, admin[i].password, admin[i].codigo);
    }
    fclose(file);
}

void create_admin()
{
    char username[50];
    char password[50];
    char codigo[20];

    printf("Ingresa el nombre de administrador: ");
    scanf("%s", username);
    printf("Ingresa la contrasenia del administrador: ");
    scanf("%s", password);
    printf("Ingresa el codigo de administrador: ");
    scanf("%s", codigo);

    if (num_admin >= MAX_ADMIN)
    {
        printf("No se pueden crear más administradores\n");
        return;
    }
    sprintf(admin[num_admin].username, "%s", username);
    sprintf(admin[num_admin].password, "%s", password);
    sprintf(admin[num_admin].codigo, "%s", codigo);
    num_admin++;
    write_admins_file();
    printf("Administrador creado exitosamente\n");
}

/*int main() {
    read_admins_file();
    printf("Bienvenido al sistema de registro de administradores\n");
    while (1) {
        printf("¿Que deseas hacer?\n");
        printf("1. Crear administrador\n");
        printf("2. Salir\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: ;
                create_admin();
                break;
            case 2: ;
                printf("Adios!\n");
                exit(0);
            default: ;
                printf("Opcion invalida\n");
        }
    }
    return 0;
}*/