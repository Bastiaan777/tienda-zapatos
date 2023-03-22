#include <stdio.h>
#include <stdlib.h>

typedef struct{

    char nombre[15];
    char correo[15];
    int dni;
    char contraseña[15];

}usuarioNuevo;


int main(){

    printf ("Nombre:");
    scanf ("%s", usuarioNuevo.nombre);

    printf("Correo:");
    scanf("%s", usuarioNuevo.correo);

    printf("dni:");
    scanf("%i", usuarioNuevo.dni);

    printf("Contraseña:");
    scanf("%s", usuarioNuevo.contraseña);

    //hay que guardarlo en la base de datos pero no está creada todavía

    FILE *usuariofile;

    usuariofile = fopen("usuarios.txt", "a");  

    fprintf(usuariofile, "%s %s %i %s\n", usuarioNuevo.nombre, usuarioNuevo.correo, usuarioNuevo.dni,usuarioNuevo.contraseña);

    fclose(usuariofile); 


}



