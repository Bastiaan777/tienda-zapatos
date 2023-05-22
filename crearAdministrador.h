#pragma once 

#define MAX_ADMIN 100

typedef struct admin {
    char username[50];
    char password[50];
    char codigo [20];
} Admin;

void read_admins_file();

void write_admins_file();

void create_admin();

