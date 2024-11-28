/******************************************************************************
Inventario Pastillas Efervescentes
Samantha Henry y Walter Silva
*******************************************************************************/
#include <stdio.h>
#include "libreria.h"

int main() {
    int opcion, cantidad, i = 0;
    int pedido[MAX_PRODUCTOS] = {0}; 
    float precios[MAX_PRODUCTOS] = {10.99, 15.49, 12.99, 18.99}; 
    int max_cantidades[MAX_PRODUCTOS] = {10, 15, 8, 20};
    do {
        menu(precios);
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        dar_servicio(opcion, max_cantidades,pedido);
        
    } while (opcion != 5 && i < MAX_PRODUCTOS);

    printf("\nResumen del pedido:\n");
    float total = 0.0;
    for (int j = 0; j < 4; j++) {
        if (pedido[j] > 0) {
            printf("Tableta %c: %d unidades (%.2f $)\n", 'A' + j, pedido[j], precios[j] * pedido[j]);
            total += precios[j] * pedido[j];
           
        }
    }

    printf("Total del pedido: %.2f $\n", total);
    printf("Inventario final:\n");
    for (int j = 0; j < 4; j++){
        printf("Tableta %d = %d\n", j+1, max_cantidades[j]);
    }
    
    char nota[100]="tu compra es de %d";
    FILE *f;
    printf("Gracias por tu pedido");
    //printf("Tableta %c: %d unidades\n", cantidad);
    //printf("Total del pedido: %.2f $\n", total);
    
    
    f=fopen("nota1.txt","wt"); 
    if (f != NULL)
    {
        fprintf(f,"Recibo de nota del pedido");
        fprintf(f,"Total del pedido: %.2f $\n", total);
        fprintf(f,"Inventario final:\n");
        for (int j = 0; j < 4; j++)
        {
             fprintf(f,"Tableta %d = %d\n", j+1, max_cantidades[j]);
        }
    
    }
    fclose(f);
    return 0;
}

