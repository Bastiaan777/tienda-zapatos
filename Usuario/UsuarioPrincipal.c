#include <stdio.h>



int main(){

int opcion;



printf("BIENVENIDO USUARIO, QUE DESEAS HACER?\n");

printf("1. Mi perfil\n");
printf("2. Menu\n");
printf("3. Mi cesta\n");
printf("4. Salir\n");

printf("Seleccione la opcion que desea");
scanf("%d", &opcion);

    switch(opcion){

        case 1:

            printf("Estos son los datos de tu perfil\n");
            
            break;

        case 2:

            printf("Bienvenido al menu de zapatos, que zapatos desea?\n");
            
            break;

        case 3:

            printf("Estos son los productos que tienes en tu cesta\n");
            break;

        case 4:

            printf("adios!\n");
            break;
        
        default:
            printf("opcion invalida\n");
            break;


    }



return 0;

}