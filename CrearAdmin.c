#include <stdio.h>
#include <stdlib.h>

typedef struct{

    char nombre[15];
    char correo[15];
    int dni;
    char contraseña[15];
    char codigo[15];

}adminNuevo;


int main(){

    printf ("Nombre:");
    scanf ("%s", adminNuevo.nombre);

    printf("Correo:");
    scanf("%s", adminNuevo.correo);

    printf("dni:");
    scanf("%i", adminNuevo.dni);

    printf ("Codigo:");
    scanf ("%s", adminNuevo.codigo);

    printf("Contraseña:");
    scanf("%s", adminNuevo.contraseña);

    //hay que guardarlo en la base de datos pero no está creada todavía

    FILE *adminfile;

    adminfile = fopen("admins.txt", "ad");  

    fprintf(adminfile, "%s %s %i %s\n", adminNuevo.nombre, adminNuevo.correo, adminNuevo.dni, adminNuevo.codigo, adminNuevo.contraseña);

    fclose(adminfile); 


}