#pragma once 

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "sqlite3.h"


typedef struct
{
    char tipo[50];
    char nombre[50];
    char color[20];
    int talla;
    double precio;
    
} Pedido;

static Pedido cesta[100];
static int cantidad_pedidos = 0;

int mostrar_tipos(void *data, int argc, char **argv, char **azColName);

int mostrar_zapatos_tipo(void *data, int argc, char **argv, char **azColName);

int mostrar_opciones_zapato(void *data, int argc, char **argv, char **azColName);

void ver_tipos(sqlite3 *db);

void ver_zapatos_tipo(sqlite3 *db, char *tipo);

void ver_opciones_zapato(sqlite3 *db, char *nombre);

void agregar_a_cesta(sqlite3 *db, char *nombre, char *color, int talla, double precio);

void ver_cesta();

void obtener_precio(sqlite3 *db, char *nombre, char *color, int talla, double *precio);

void mostrar_usuario(const char *username);

void comprar_cesta(sqlite3 *db, char *username);


