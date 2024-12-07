#include <stdio.h>
#define MAX_PRODUCTOS 10

void dar_servicio(int opcion, int max_cantidades[MAX_PRODUCTOS],int pedido[MAX_PRODUCTOS])
{
    int cantidad,i;
    if (opcion >= 1 && opcion <= 4) {
            printf("Ingrese la cantidad de tabletas: ");
            scanf("%d", &cantidad);

            printf("Hay %d tabletas %c disponibles.\n", max_cantidades[opcion - 1], 'A' + opcion - 1);

            if (cantidad > 0) {
                if (cantidad <= max_cantidades[opcion - 1]) {
                    pedido[opcion - 1] += cantidad;
                    i++;
                    printf("Se han agregado %d unidades al pedido. Quedan %d unidades disponibles.\n", cantidad, max_cantidades[opcion - 1] - cantidad);
                    max_cantidades[opcion - 1] -= cantidad; 
                } else {
                    printf("No hay suficiente stock de esta tableta. Quedan %d unidades disponibles.\n", max_cantidades[opcion - 1]);
                }
            } else {
                printf("La cantidad debe ser positiva.\n");
            }
        } else if (opcion == 5) {
            printf("Pedido finalizado.\n");
        } else {
            printf("Opción inválida.\n");
        }
}


void menu(float precios[MAX_PRODUCTOS])
{
     printf("\nSeleccione el tipo de tableta:\n");
    printf("1. Tableta A (%.2f $)\n", precios[0]);
    printf("2. Tableta B (%.2f $)\n", precios[1]);
    printf("3. Tableta C (%.2f $)\n", precios[2]);
    printf("4. Tableta D (%.2f $)\n", precios[3]);
    printf("5. Finalizar pedido\n");
    printf("6. Salir\n");
}






