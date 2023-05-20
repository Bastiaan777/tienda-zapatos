#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <time.h>
#include "sqlite3.h"
#include "crearUsuario.h"
#include "crearAdministrador.h"
#include "AnyadirZapatos.h"
#include "EliminarZapatos.h"
#include "UsuarioPrincipal.h"
#include "Metodosc++.h"
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;


#define MAX_USUARIOS 100
#define MAX_LEN 50
#define MAX_ADMINS 100

//FUNCION PARA IMPRIMIR TODOS LOS ZAPATOS DE LA BD EN ELIMINAR ZAPATO
int imprimirZapatos(void* data, int tamanyo, char** zapato, char** nombreColumna) {
    int i;
    for (i = 0; i < tamanyo; i++) {
        std::cout << nombreColumna[i] << " = " << zapato[i] << "  ";
    }
    std::cout << endl;
    return 0;
}

void UsuarioPrincipal(const std::string& username)
{
    std::cout << "Bienvenido, " << username << "! Eres un usuario principal." << std::endl;
}

void menuAdministrador(const std::string& username)
{
    std::cout << "Bienvenido, " << username << "! Eres un administrador." << std::endl;
}

int main(){

    std::ifstream archivo;
    char admins[MAX_ADMINS][3][MAX_LEN];
    char nombre[MAX_LEN], contrasena[MAX_LEN], codigo[MAX_LEN];
    int num_admins = 0;
    int i, encontrado = 0;
    char usuarios[MAX_USUARIOS][2][MAX_LEN];
    int num_usuarios = 0;
    std::string username;
    std::string contrasena1;

    int opcion;

    cout << "BIENVENIDO, ¿ERES ADMINISTRADOR O USUARIO?" << endl;

    cout << "1. Crear Usuario" << endl;
    cout << "2. Crear Administrador" << endl;
    cout << "3. Login de Usuario" << endl;
    cout << "4. Login de Administrador" << endl;

    cout << "Seleccione la opcion que desea: ";
    cin >> opcion;

    switch (opcion)
    {
        case 1:
        {
            read_users_file();
            cout << "Bienvenido al sistema de registro de usuarios" << endl;
            while (true)
            {
                cout << "¿Que deseas hacer?" << std::endl;
                cout << "1. Crear usuario" << std::endl;
                cout << "2. Salir" << std::endl;
                int choice;
                std::cin >> choice;
                switch (choice)
                {
                    case 1:
                        create_user();
                        break;
                    case 2:
                        std::cout << "Adiós!" << std::endl;
                        exit(0);
                    default:
                        std::cout << "Opción inválida" << std::endl;
                }
            }
            return 0;
        }
        break;

        case 2:
        {
            read_admins_file();
            std::cout << "Bienvenido al sistema de registro de administradores" << std::endl;
            while (true)
            {
                std::cout << "¿Que deseas hacer?" << std::endl;
                std::cout << "1. Crear administrador" << std::endl;
                std::cout << "2. Salir" << std::endl;
                int choice;
                std::cin >> choice;
                switch (choice)
                {
                    case 1:
                        create_admin();
                        break;
                    case 2:
                        std::cout << "Adios!" << std::endl;
                        exit(0);
                    default:
                        std::cout << "Opción inválida" << std::endl;
                }
            }
            return 0;
        }
        break;

        case 3:
        {
            std::cout << "Ingrese su nombre de usuario: ";
            std::cin >> username;
            std::cout << "Ingrese su contraseña: ";
            std::cin >> contrasena1;

            // Verificar si el usuario existe en el arreglo
            for (i = 0; i < num_usuarios; i++)
            {
                if (strcmp(usuarios[i][0], username.c_str()) == 0 && strcmp(usuarios[i][1], contrasena1.c_str()) == 0)
                {
                    encontrado = 1;
                    break;
                }
            }

            if (encontrado == 1)
            {
                std::cout << "Inicio de sesión exitoso como usuario" << std::endl;
                UsuarioPrincipal(username);
            }
            else
            {
                std::cout << "Inicio de sesión fallido. Usuario o contraseña incorrectos." << std::endl;
            }
        }
        break;

        case 4:
        {
            std::cout << "Ingrese su nombre de administrador: ";
            std::cin >> username;
            std::cout << "Ingrese su contraseña: ";
            std::cin >> contrasena1;

            // Verificar si el administrador existe en el arreglo
            for (i = 0; i < num_admins; i++)
            {
                if (strcmp(admins[i][0], username.c_str()) == 0 && strcmp(admins[i][1], contrasena1.c_str()) == 0)
                {
                    encontrado = 1;
                    break;
                }
            }

            if (encontrado == 1)
            {
                std::cout << "Inicio de sesión exitoso como administrador" << std::endl;
                menuAdministrador(username);
            }
            else
            {
                std::cout << "Inicio de sesión fallido. Usuario o contraseña incorrectos." << std::endl;
            }
        }
        break;

        default:
            std::cout << "Opción inválida" << std::endl;
            break;
    }

    return 0;
}
