#include <stdio.h>
#include <string.h>

struct User
{
    char username[20];
    char password[20];
    int is_admin;
};

int main()
{
    struct User users[2];
    strcpy(users[0].username, "user");
    strcpy(users[0].password, "password");
    users[0].is_admin = 0;
    strcpy(users[1].username, "admin");
    strcpy(users[1].password, "admin_password");
    users[1].is_admin = 1;

    char username[20];
    char password[20];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    int user_index = -1;
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0)
        {
            user_index = i;
            break;
        }
    }

    if (user_index == -1)
    {
        printf("Invalid username or password.\n");
        return 1;
    }

    if (users[user_index].is_admin)
    {
        printf("Welcome, admin %s!\n", username);
        // Administrador
    }
    else
    {
        printf("Welcome, user %s!\n", username);
        // Usuario normal
    }

    return 0;
}