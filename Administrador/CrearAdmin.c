#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

typedef struct{

    char nombre[100];
    char apellido [100];
    char correo[100];
    int dni;
    char contraseña[100];
    char codigo[100];

}adminNuevo;


int main(){

    printf ("Nombre:");
    scanf ("%s", adminNuevo.nombre);

    printf ("Apellido:");
    scanf ("%s", adminNuevo.apellido);

    printf("Correo:");
    scanf("%s", adminNuevo.correo);

    printf("dni:");
    scanf("%i", adminNuevo.dni);

    printf ("Codigo:");
    scanf ("%s", adminNuevo.codigo);

    printf("Contraseña:");
    scanf("%s", adminNuevo.contraseña);

    //hay que guardarlo en la base de datos 

    


}