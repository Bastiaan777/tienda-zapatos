#include <stdio.h>
#include "sqlite3.h"


int main(){

int opcion;



printf("BIENVENIDO ADMINISTRADOR, QUE DESEAS HACER?\n");

printf("1. Añadir y eliminar zapatos\n");
printf("2. Visualizar clientes\n");
printf("3. Visualizar pedidos\n");
printf("4. Crear administrador\n");
printf("5. Salir\n");

printf("Seleccione la opcion que desea");
scanf("%d", &opcion);

    switch(opcion){

        case 1:

            printf("Has elegido la opcion de añadir o eliminar usuarios\n");

            //int result = sqlite3_open("test.sqlite", &tiendaBD);
                //if (result != SQLITE_OK) {
                //printf("Error opening database\n");
               // return result;
	        //}

            printf("base de datos abierta/n");

            //result = insertarUsuario();
	        //if (result != SQLITE_OK) {
		    //printf("Error inserting new data\n");
		    //printf("%s\n", sqlite3_errmsg(tiendaBD));
		    //return result;
	        //}
            
            
            break;

        case 2:

            printf("Has elegido ver clientes\n");
            sqlite3 *db;

            //int result = sqlite3_open("test.sqlite", &tiendaBD);
                //if (result != SQLITE_OK) {
                //printf("Error opening database\n");
               // return result;
	        //}

            printf("base de datos abierta/n");

            //result = showAllCountries(tiendaBD);
                //if (result != SQLITE_OK) {
                //printf("Error obteniendo los clientes\n");
                //printf("%s\n", sqlite3_errmsg(db));
                //return result;
	        //}

            break;

        case 3:

            printf("Has elegido ver los pedidos\n");
            break;

        case 4:

            printf("Has elegido crear un administrador\n");
            break;

        case 5:

            printf("Salir\n");
            break;

        
        default:
            printf("opcion invalida\n");
            break;


    }



return 0;

}