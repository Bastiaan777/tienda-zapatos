#include <stdio.h>
#include <stdlib.h>

struct Zapato
{
    int talla;
    char color[50];
    char nombre[50];
    float precio;
};

int main()
{
    struct Zapato zapato;

    printf("Introduzca la talla del zapato: "); // obtener talla, color,nombre, precio
    scanf("%d", &zapato.talla);

    printf("Introduzca el color del zapato: ");
    scanf("%s", zapato.color);

    printf("Introduzca el nombre del zapato: ");
    scanf("%s", zapato.nombre);

    printf("Introduzca el precio del zapato: ");
    scanf("%f", &zapato.precio);

    FILE *fptr;

    fptr = fopen("zapatos.dat", "ab"); // modo de escritura binaria
    if (fptr == NULL)
    {
        printf("Ha abido un eror cuando has intentado abrir el archivo");
        exit(1);
    }

    fwrite(&zapato, sizeof(struct Zapato), 1, fptr);

    printf("\nEl zapato se ha añadido");

    fclose(fptr);

    return 0;
}
