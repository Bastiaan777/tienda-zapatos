#pragma once 
#include "sqlite3.h"
#include "AnyadirZapatos.h"


int Zapateria_init_Elm(Zapateria *zapateria, const char *db_filename);

int Zapateria_eliminar_zapato_Elm(Zapateria *zapateria, int id);

void Zapateria_close_Elm(Zapateria *zapateria);

 






