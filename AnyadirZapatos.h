
#ifndef AnyadirZapatos_h
#define AnyadirZapatos_h
#include "sqlite3.h"

typedef struct
{
    int id;
    char tipo[50];
    char nombre[50];
    char color[50];
    float talla;
    float precio;
} Zapato;

// Definición de la clase para añadir zapatos y guardarlos en una base de datos
typedef struct
{
    sqlite3 *db;
} Zapateria;

// Función para inicializar la base de datos y crear la tabla de zapatos
int Zapateria_init(Zapateria *zapateria, const char *db_filename);

// Función para añadir un zapato a la base de datos
int Zapateria_add_zapato(Zapateria *zapateria, Zapato *zapato);

// Función para cerrar la base de datos
void Zapateria_close(Zapateria *zapateria);

#endif