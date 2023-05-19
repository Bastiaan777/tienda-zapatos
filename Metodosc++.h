#pragma once 

#include <string>
#include <stdio.h>
#include "sqlite3.h"

namespace metodospp{

    void ver_zapatos_tipo(sqlite3 *db, const std::string& tipo);
    void ver_opciones_zapato(sqlite3 *db, const std::string& nombre);
    void agregar_a_cesta(sqlite3 *db, const std::string& nombre, const std::string& color, int talla, double precio);
    void ver_cesta();
    void obtener_precio(sqlite3 *db, const std::string& nombre, const std::string& color, int talla, double *precio);
    void mostrar_usuario(const std::string& username);
    void comprar_cesta(sqlite3 *db, const std::string& username);
    void create_user();


}


