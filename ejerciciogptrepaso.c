#include <stdio.h>
#include <string.h>
#include "inventario.h"

void listarProductos(char productos[][3][40], double precio[], int indice[]) {
    printf("Número\tNombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t%s\t\t%s\t\t%s\t\t%.2f\n", indice[i], productos[i][0], productos[i][1], productos[i][2], precio[i]);
    }
}

void buscarXMarca(char productos[][3][40], double precio[]) {
    char marca[40];
    printf("Ingrese la marca a buscar: ");
    scanf("%s", marca);

    printf("Número\tNombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i < 10; i++) {
        if (strcmp(productos[i][2], marca) == 0) {
            printf("%d\t%s\t\t%s\t\t%s\t\t%.2f\n", i + 1, productos[i][0], productos[i][1], productos[i][2], precio[i]);
        }
    }
}

void buscarXCategoria(char productos[][3][40], double precio[]) {
    char categoria[40];
    printf("Ingrese la categoria a buscar: ");
    scanf("%s", categoria);

    printf("Número\tNombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i < 10; i++) {
        if (strcmp(productos[i][1], categoria) == 0) {
            printf("%d\t%s\t\t%s\t\t%s\t\t%.2f\n", i + 1, productos[i][0], productos[i][1], productos[i][2], precio[i]);
        }
    }
}

void buscarXPrecioMenor(char productos[][3][40], double precio[]) {
    double precioLimite;
    printf("Ingrese el precio límite: ");
    scanf("%lf", &precioLimite);

    printf("Número\tNombre\t\tCategoria\tMarca\t\tPrecio\n");
    for (int i = 0; i < 10; i++) {
        if (precio[i] < precioLimite) {
            printf("%d\t%s\t\t%s\t\t%s\t\t%.2f\n", i + 1, productos[i][0], productos[i][1], productos[i][2], precio[i]);
        }
    }
}

void editarProducto(char productos[][3][40], double precio[], int indice[]) {
    int numProducto;
    printf("Ingrese el número del producto a editar: ");
    scanf("%d", &numProducto);
    numProducto--; // Para ajustarlo al índice del array

    if (numProducto >= 0 && numProducto < 10) {
        printf("Editar Nombre (actual: %s): ", productos[numProducto][0]);
        scanf("%s", productos[numProducto][0]);
        printf("Editar Categoria (actual: %s): ", productos[numProducto][1]);
        scanf("%s", productos[numProducto][1]);
        printf("Editar Marca (actual: %s): ", productos[numProducto][2]);
        scanf("%s", productos[numProducto][2]);
        printf("Editar Precio (actual: %.2f): ", precio[numProducto]);
        scanf("%lf", &precio[numProducto]);
        printf("Producto actualizado con éxito.\n");
    } else {
        printf("Número de producto no válido.\n");
    }
}