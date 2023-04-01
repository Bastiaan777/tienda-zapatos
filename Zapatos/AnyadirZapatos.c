#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AnyadirZapatos.h"





// Función para inicializar la base de datos y crear la tabla de zapatos
int Zapateria_init(Zapateria *zapateria, const char *db_filename)
{
    int rc = sqlite3_open(db_filename, &zapateria->db);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(zapateria->db));
        return 1;
    }
    rc = sqlite3_exec(zapateria->db, "CREATE TABLE IF NOT EXISTS zapatos (id INTEGER PRIMARY KEY, marca TEXT, modelo TEXT, precio REAL);", NULL, 0, NULL);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Error al crear la tabla de zapatos: %s\n", sqlite3_errmsg(zapateria->db));
        sqlite3_close(zapateria->db);
        return 1;
    }
    return 0;
}

// Función para añadir un zapato a la base de datos
int Zapateria_add_zapato(Zapateria *zapateria, Zapato *zapato)
{
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(zapateria->db, "INSERT INTO zapatos (marca, modelo, precio) VALUES (?, ?, ?);", -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Error al preparar la consulta: %s\n", sqlite3_errmsg(zapateria->db));
        return 1;
    }
    sqlite3_bind_text(stmt, 1, zapato->marca, strlen(zapato->marca), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, zapato->modelo, strlen(zapato->modelo), SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt, 3, zapato->precio);
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

// Ejemplo de uso --> Poner en main
int main()
{
    Zapateria zapateria;
    Zapateria_init(&zapateria, "zapateria.db");
    Zapato zapato = {0, "Adidas", "Superstar", 100.0};
    Zapateria_add_zapato(&zapateria, &zapato);
    Zapateria_close(&zapateria);
    return 0;
}