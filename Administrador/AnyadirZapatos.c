#include <stdio.h>
#include <stdlib.h>

struct Zapato {
    int talla;
    char color[50];
    char nombre[50];
    float precio;
};

int main() {
    struct Zapato zapato;
    printf("Introduzca el nombre del zapato: ");
    scanf("%s", zapato.nombre);

    printf("Introduzca el color del zapato: ");
    scanf("%s", zapato.color);

    printf("Introduzca la talla del zapato: ");
    scanf("%d", &zapato.talla);

    printf("Introduzca el precio del zapato: ");
    scanf("%f", &zapato.precio);

    FILE *fp;

    fp = fopen("zapatos.txt", "a");// modo de escritura en texto
    if (fp == NULL) {
        printf("Ha habido un error cuando has intentado abrir el archivo");
        exit(1);
    }

    
    fprintf(fp, "Nombre: %s\n", zapato.nombre);
    fprintf(fp, "Color: %s\n", zapato.color);
    fprintf(fp, "Talla: %d\n", zapato.talla);
    fprintf(fp, "Precio: %.2f\n", zapato.precio);
    fprintf(fp, "\n");

    printf("\nEl zapato se ha anyadido");

    fclose(fp);

    return 0;
}