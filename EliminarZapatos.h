
#ifndef EliminarZapatos_h
#define ElimiarZaparos_h
#include "sqlite3.h"
#include "AnyadirZapatos.h"


int Zapateria_init(Zapateria *zapateria, const char *db_filename);

int Zapateria_eliminar_zapato(Zapateria *zapateria, int id);

void Zapateria_close(Zapateria *zapateria);

 #endif






