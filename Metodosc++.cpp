#include <iostream>
#include <iomanip>
#include <fstream>
#include "Metodosc++.h"
#include "UsuarioPrincipal.h"
#include "crearUsuario.h"



void metodospp :: ver_zapatos_tipo(sqlite3 *db, const std::string& tipo)
{
    std::cout << "\nZapatos del tipo " << tipo << ":\n";
    char *zErrMsg = 0;
    int rc;
    const char *data = "llamada a la funcion retorno";
    std::string sql = "SELECT nombre FROM zapatos WHERE tipo = '" + tipo + "';";

    rc = sqlite3_exec(db, sql.c_str(), mostrar_zapatos_tipo, (void *)data, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << zErrMsg << "\n";
        sqlite3_free(zErrMsg);
    }
    std::cout << "\n";
}

void metodospp :: ver_opciones_zapato(sqlite3 *db, const std::string& nombre)
{
    char *zErrMsg = 0;
    int rc;
    const char *data = "llamada a la funcion retorno";
    std::string sql = "SELECT color, talla, precio FROM zapatos WHERE nombre = '" + nombre + "';";

    rc = sqlite3_exec(db, sql.c_str(), mostrar_opciones_zapato, (void *)data, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << zErrMsg << "\n";
        sqlite3_free(zErrMsg);
    }
    std::cout << "\n";
}

void metodospp :: agregar_a_cesta(sqlite3 *db, const std::string& nombre, const std::string& color, int talla, double precio)
{
    char *zErrMsg = 0;
    int rc;
    sqlite3_stmt *stmt;
    std::string sql = "SELECT precio FROM zapatos WHERE nombre = '" + nombre + 
                      "' AND color = '" + color + 
                      "' AND talla = " + std::to_string(talla) +
                      " AND precio = " + std::to_string(precio) + ";";

    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Cannot prepare statement: " << sqlite3_errmsg(db) << "\n";
        return;
    }

    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW)
    {
        double precio = sqlite3_column_double(stmt, 0);
        strncpy(cesta[cantidad_pedidos].nombre , nombre.c_str(), sizeof(nombre));
        strncpy (cesta[cantidad_pedidos].color , color.c_str(), sizeof(color));
        cesta[cantidad_pedidos].talla = talla;
        cesta[cantidad_pedidos].precio = precio;
        cantidad_pedidos++;
        std::cout << "\nPedido añadido a la cesta.\n\n";
    }
    else
    {
        std::cout << "\nError al añadir el pedido a la cesta.\n\n";
    }

    sqlite3_finalize(stmt);
}


void metodospp :: ver_cesta()
{
    for (int i = 0; i < cantidad_pedidos; i++)
    {
        std::cout << "Pedido " << i + 1 << ":\n";
        std::cout << "  Nombre: " << cesta[i].nombre << "\n";
        std::cout << "  Color: " << cesta[i].color << "\n";
        std::cout << "  Talla: " << cesta[i].talla << "\n";
        std::cout << "  Precio: $" << std::fixed << std::setprecision(2) << cesta[i].precio << "\n";
    }
}

void metodospp :: obtener_precio(sqlite3 *db, const std::string& nombre, const std::string& color, int talla, double *precio)
{
    sqlite3_stmt *stmt;
    std::string sql = "SELECT precio FROM zapatos WHERE nombre = ? AND color = ? AND talla = ?;";

    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Cannot prepare statement: " << sqlite3_errmsg(db) << "\n";
        return;
    }

    sqlite3_bind_text(stmt, 1, nombre.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, color.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, talla);

    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW)
    {
        *precio = sqlite3_column_double(stmt, 0);
    }
    else
    {
        std::cerr << "Error al obtener el precio: " << sqlite3_errmsg(db) << "\n";
    }

    sqlite3_finalize(stmt);
}

void metodospp :: mostrar_usuario(const std::string& username)
{
    std::ifstream file("users.txt");
    if (!file)
    {
        std::cout << "Error al abrir el archivo users.txt.\n";
        return;
    }

    std::string user;
    std::string password;

    while (file >> user >> password)
    {
        if (user == username)
        {
            std::cout << "Usuario: " << user << "\n";
            std::cout << "Contraseña: " << password << "\n";
            file.close();
            return;
        }
    }

    std::cout << "Usuario no encontrado.\n";
    file.close();
}

void metodospp :: comprar_cesta(sqlite3 *db, const std::string& username)
{
    char *zErrMsg = 0;
    int rc;
    std::string sql;

    for (int i = 0; i < cantidad_pedidos; i++)
    {
        sql = "INSERT INTO compras (username, nombre, color, talla, precio) VALUES ('" + username + "', '" +
              cesta[i].nombre + "', '" + cesta[i].color + "', " + std::to_string(cesta[i].talla) + ", " +
              std::to_string(cesta[i].precio) + ");";

        rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
        if (rc != SQLITE_OK)
        {
            std::cerr << "SQL error: " << zErrMsg << "\n";
            sqlite3_free(zErrMsg);
        }
    }

    cantidad_pedidos = 0;
    std::cout << "\nCompra realizada con éxito.\n\n";
}

void metodospp :: create_user() {
    std::string username;
    std::string password;
    std::cout << "Ingresa el nombre de usuario: ";
    std::cin >> username;
    std::cout << "Ingresa la contraseña: ";
    std::cin >> password;
    if (num_users >= MAX_USERS) {
        std::cout << "No se pueden crear más usuarios\n";
        return;
    }
    strncpy(users[num_users].username , username.c_str(), sizeof(username));
    strncpy(users[num_users].password, password.c_str(), sizeof(password));
    num_users++;
    write_users_file();
    std::cout << "Usuario creado exitosamente\n";
}








