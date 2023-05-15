#include <stdio.h>
#include "sqlite3.h"
#include <string.h>
#include "UsuarioPrincipal.h"
#include <time.h>

Pedido cesta[100];
int cantidad_pedidos = 0;

static int mostrar_tipos(void *data, int argc, char **argv, char **azColName)
{
    printf("%s\n", argv[0]);
    return 0;
}

static int mostrar_zapatos_tipo(void *data, int argc, char **argv, char **azColName)
{
    printf("%s - %s\n", argv[0], argv[1]);
    return 0;
}

static int mostrar_opciones_zapato(void *data, int argc, char **argv, char **azColName)
{
    printf("Color: %s\n", argv[0]);
    printf("Talla: %s\n", argv[1]);
    printf("Precio: $%s\n", argv[2]);
    return 0;
}

void ver_tipos(sqlite3 *db)
{
    printf("\nTipos de zapatos disponibles:\n");
    char *zErrMsg = 0;
    int rc;
    const char *data = "Callback function called";
    char *sql = "SELECT DISTINCT tipo FROM zapatos;";

    rc = sqlite3_exec(db, sql, mostrar_tipos, (void *)data, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    printf("\n");
}

void ver_zapatos_tipo(sqlite3 *db, char *tipo)
{
    printf("\nZapatos del tipo %s:\n", tipo);
    char *zErrMsg = 0;
    int rc;
    const char *data = "Callback function called";
    char sql[100];
    snprintf(sql, sizeof(sql), "SELECT nombre FROM zapatos WHERE tipo = '%s';", tipo);

    rc = sqlite3_exec(db, sql, mostrar_zapatos_tipo, (void *)data, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    printf("\n");
}

void ver_opciones_zapato(sqlite3 *db, char *nombre)
{
    char *zErrMsg = 0;
    int rc;
    const char *data = "Callback function called";
    char sql[100];
    snprintf(sql, sizeof(sql), "SELECT color, talla, precio FROM zapatos WHERE nombre = '%s';", nombre);

    rc = sqlite3_exec(db, sql, mostrar_opciones_zapato, (void *)data, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    printf("\n");
}

void agregar_a_cesta(sqlite3 *db, char *nombre, char *color, int talla, double precio)
{
    char *zErrMsg = 0;
    int rc;
    sqlite3_stmt *stmt;
    char sql[100];
    snprintf(sql, sizeof(sql), "SELECT precio FROM zapatos WHERE nombre = '%s' AND color = '%s' AND talla = %d; AND precio = %f", nombre, color, talla, precio);

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW)
    {
        double precio = sqlite3_column_double(stmt, 0);
        strcpy(cesta[cantidad_pedidos].nombre, nombre);
        strcpy(cesta[cantidad_pedidos].color, color);
        cesta[cantidad_pedidos].talla = talla;
        cesta[cantidad_pedidos].precio = precio;
        cantidad_pedidos++;
        printf("\nPedido añadido a la cesta.\n\n");
    }
    else
    {
        printf("\nError al añadir el pedido a la cesta.\n\n");
    }

    sqlite3_finalize(stmt);
}

void ver_cesta()
{
    for (int i = 0; i < cantidad_pedidos; i++)
    {
        printf("Pedido %d:\n", i + 1);
        printf("  Nombre: %s\n", cesta[i].nombre);
        printf("  Color: %s\n", cesta[i].color);
        printf("  Talla: %d\n", cesta[i].talla);
        printf("  Precio: $%.2f\n", cesta[i].precio);
    }
}

void obtener_precio(sqlite3 *db, char *nombre, char *color, int talla, double *precio)
{
    sqlite3_stmt *stmt;
    char sql[] = "SELECT precio FROM zapatos WHERE nombre = ? AND color = ? AND talla = ?;";

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_text(stmt, 1, nombre, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, color, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, talla);

    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW)
    {
        *precio = sqlite3_column_double(stmt, 0);
    }
    else
    {
        fprintf(stderr, "Error al obtener el precio: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
}

void mostrar_usuario(const char *username)
{ 
    FILE *file = fopen("users.txt", "r");
    if (file == NULL)
    {
        printf("Error al abrir el archivo users.txt.\n");
        return;
    }

    char user[50];
    char password[50];

    while (fscanf(file, "%s %s", user, password) == 2)
    {
        if (strcmp(user, username) == 0)
        {
            printf("Usuario: %s\n", user);
            printf("Contraseña: %s\n", password);
            fclose(file);
            return;
        }
    }

    printf("Usuario no encontrado.\n");
    fclose(file);
}

void comprar_cesta(sqlite3 *db, char *username) {
    char *zErrMsg = 0;
    int rc;
    char sql[200];

    for (int i = 0; i < cantidad_pedidos; i++) {
        snprintf(sql, sizeof(sql), "INSERT INTO compras (username, nombre, color, talla, precio) VALUES ('%s', '%s', '%s', %d, %f);",
                 username, cesta[i].nombre, cesta[i].color, cesta[i].talla, cesta[i].precio);

        rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
    }

    cantidad_pedidos = 0;
    printf("\nCompra realizada con éxito.\n\n");
}