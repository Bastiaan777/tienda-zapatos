#ifndef CREARUSUARIO_H_INCLUDED
#define CREARUSUARIO_H_INCLUDED

typedef struct {
    char username[50];
    char password[50];
} User;

void read_users_file();

void write_users_file();

void create_user();

#endif 
