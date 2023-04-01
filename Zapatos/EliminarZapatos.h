#include "sqlite3.h"
#ifndef EliminarZapatos_h
#define ElimiarZaparos_h

typedef struct
{
     char tipo[50];
    char nombre[50];
    char color[50];
    float talla;
    float precio;
} Zapato;

typedef struct
{
    sqlite3 *db;
} Zapateria;

int Zapateria_init(Zapateria *zapateria, const char *db_filename);

int Zapateria_eliminar_zapato(Zapateria *zapateria, int id);

void Zapateria_close(Zapateria *zapateria);









 #endif






