#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EliminarZapatos.h"
#include "sqlite3.h"

// Definición de la estructura de datos para representar los zapatos


// Definición de la clase para eliminar zapatos de la base de datos


// Función para inicializar la base de datos
int Zapateria_init(Zapateria *zapateria, const char *db_filename)
{
    int rc = sqlite3_open(db_filename, &zapateria->db);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(zapateria->db));
        return 1;
    }
    return 0;
}

// Función para eliminar un zapato de la base de datos
int Zapateria_eliminar_zapato(Zapateria *zapateria, int id)
{
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(zapateria->db, "DELETE FROM zapatos WHERE id = ?;", -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Error al preparar la consulta: %s\n", sqlite3_errmsg(zapateria->db));
        return 1;
    }
    sqlite3_bind_int(stmt, 1, id);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        fprintf(stderr, "Error al ejecutar la consulta: %s\n", sqlite3_errmsg(zapateria->db));
        return 1;
    }
    sqlite3_finalize(stmt);
    return 0;
}

// Función para cerrar la base de datos
void Zapateria_close(Zapateria *zapateria)
{
    sqlite3_close(zapateria->db);
}

