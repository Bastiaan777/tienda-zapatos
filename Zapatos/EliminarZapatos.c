#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Zapato
{
    int talla;
    char color[50];
    char nombre[50];
    float precio;
};

int main()
{
    FILE *fptr, *temp;
    struct Zapato zapato;
    int encontrado = 0, talla;

    printf("Introduzca la talla del zapato que quiere eliminar: ");
    scanf("%d", &talla);

    fptr = fopen("zapatos.dat", "rb");
    if (fptr == NULL)
    {
        printf("Ha habido un error cuando has intentado abrir el archivo");
        exit(1);
    }

    temp = fopen("temp.dat", "wb");
    if (temp == NULL)
    {
        printf("Ha habido un error al crear el archivo temporal");
        exit(1);
    }

    while (fread(&zapato, sizeof(struct Zapato), 1, fptr))
    {
        if (zapato.talla != talla)
        {
            fwrite(&zapato, sizeof(struct Zapato), 1, temp);
        }
        else
        {
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        printf("No se ha encontrado ningún zapato con esa talla");
    }
    else
    {
        printf("El zapato se ha eliminado correctamente");
    }

    fclose(fptr);
    fclose(temp);

    remove("zapatos.dat");
    rename("temp.dat", "zapatos.dat");

    return 0;
}