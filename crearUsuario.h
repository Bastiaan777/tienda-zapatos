#ifndef CREARUSUARIO_H_INCLUDED
#define CREARUSUARIO_H_INCLUDED
#define MAX_USERS 100 // máximo número de usuarios que podemos tener

typedef struct {
    char username[50];
    char password[50];
} User;

static User users[MAX_USERS]; // arreglo para almacenar todos los usuarios

static int num_users = 0; // contador de usuarios actuales



void read_users_file();

void write_users_file();

void create_user();

#endif 
