#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

typedef struct{

    char nombre[100];
    char apellido [100];
    char correo[100];
    int dni;
    char contraseña[100];

}usuarioNuevo;


int main(){

    printf ("Nombre:");
    scanf ("%s", usuarioNuevo.nombre);

    printf ("Apellido:");
    scanf ("%s", usuarioNuevo.apellido);

    printf("Correo:");
    scanf("%s", usuarioNuevo.correo);

    printf("dni:");
    scanf("%i", usuarioNuevo.dni);

    printf("Contraseña:");
    scanf("%s", usuarioNuevo.contraseña);



}



