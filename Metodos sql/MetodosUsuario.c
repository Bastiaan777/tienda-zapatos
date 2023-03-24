#include <stdio.h>
#include "sqlite3.h"
#include <string.h>

int mostrarUsuarios(sqlite3 *tiendaBD) {  //este metodo es para que el administrador tenga la opcion de ver todos los usuarios registrados
	sqlite3_stmt *stmt;

	int id;

	char sql[] = "select dni, nombre, apellido, correo, contrasena from usuario";

	int result = sqlite3_prepare_v2(tiendaBD, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(tiendaBD));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	int dni;
	char nombre[100];
	char apellido[100];
    char correo [100];
    char contraseña[100];

	printf("\n");
	printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
	printf("Mostrando usuarios:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			id = sqlite3_column_int(stmt, 0);
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
			strcpy(apellido, (char *) sqlite3_column_text(stmt, 2));
			strcpy(correo, (char *) sqlite3_column_text(stmt, 3));
			strcpy(contraseña, (char *) sqlite3_column_text(stmt, 4));
            printf("Nombre: %s\n Apellido:%s\n Correo: %s\n dni: %d Contraseña", nombre, apellido, correo, dni, contraseña);
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(tiendaBD));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;
}

int insertarUsuario(sqlite3 *tiendaBD, int dni, char nombre[], char apellido[], char correo[], char contraseña[]) { //este metodo es para crear un usuario nuevo
	sqlite3_stmt *stmt;

	char sql[] = "insert into usuario (nombre, apellido, correo, dni, contrasena) values (?,?,?,?,?)";
	int result = sqlite3_prepare_v2(tiendaBD, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(tiendaBD));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	sqlite3_bind_text(stmt, 1, dni, -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, nombre, -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, apellido, -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, correo, -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, contraseña, -1, SQLITE_TRANSIENT);

	

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into country table\n");
		return result;
	}

	printf("Cliente insertado correctamente\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(tiendaBD));
		return result;
	}


	return SQLITE_OK;

}