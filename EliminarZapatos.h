#include "sqlite3.h"
#ifndef EliminarZapatos_h
#define ElimiarZaparos_h

typedef struct
{
    int id;
    char tipo[50];
    char nombre[50];
    char color[50];
    float talla;
    float precio;
    
} ZapatoElm;

typedef struct
{
    sqlite3 *db;
} ZapateriaElm;

int Zapateria_init_Elm(ZapateriaElm *zapateria, const char *db_filename);

int Zapateria_eliminar_zapato_Elm(ZapateriaElm *zapateria, int id);

void Zapateria_close_Elm(ZapateriaElm *zapateria);









 #endif






