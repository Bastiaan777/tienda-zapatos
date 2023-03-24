#include <stdio.h>


int main(){

int opcion;

printf("BIENVENIDO, ERES ADMINISTRADOR O USUARIO?\n");

printf("1. Soy un usuario\n");
printf("2. Soy un administrador\n");
printf("3. Quiero crearme una cuenta\n");
printf("4. Salir\n");

printf("Seleccione la opcion que desea");
scanf("%d", &opcion);

    switch(opcion){

        case 1:

            char Correo[50];

            printf("bienvenido usuario\n");
            printf("Introduce tu correo:\n");
            scanf("%s", Correo);
            //comprobar que el correo este en la base de datos, de ser asi, pediriamos su contraseña.
            break;

        case 2:

            int Codigo;

            printf("bienvenido administrador\n");
            printf("Introduce tu codigo de administrador:\n");
            scanf("%d", Codigo);
            //comprobar que el codigo este en la base de datos, de ser asi, le pedimos la contraseña.
            break;

        case 3:

            print("has decidido crearte una cuenta!\n");

            break;

        case 4:

            printf("adios!");
            break;
        
        default:
            printf("opcion invalida\n");
            break;


    }



return 0;

}