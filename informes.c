#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "input.h"
#include "LinkedList.h"
#include "bicicletas.h"
#include "parser.h"



void bicicleta_printHeader(void)
{
    printf("\n-------------------------------------------------------------------------------\n");
    printf("ID      NOMBRE        TIPO       TIEMPO");
    printf("\n-------------------------------------------------------------------------------\n");
}


void bicicleta_imprimirBicicleta(eBicicleta* nuevaBicicleta)
{
    if(nuevaBicicleta != NULL)
    {
        int id, tiempo;
        char nombre[128], tipo[128];

        bicicleta_getId(nuevaBicicleta, &id);
        bicicleta_getNombre(nuevaBicicleta, nombre);
        bicicleta_getTipo(nuevaBicicleta, tipo);
        bicicleta_getTiempo(nuevaBicicleta, &tiempo);

        printf("%d %12s %9s %16d\n", id, nombre, tipo, tiempo);
    }
}


void bicicleta_imprimirListaBicicletas(LinkedList* list)
{
    if(list != NULL)
    {
        int i;
        eBicicleta* nuevaBicicleta;

        bicicleta_printHeader();

        for(i=0; i<ll_len(list); i++)
        {
            nuevaBicicleta = ll_get(list, i);
            bicicleta_imprimirBicicleta(nuevaBicicleta);
        }
    }
}


int menu_Principal(char* msj )
{
    int aux;
    printf(msj);
    fflush(stdin);
    scanf("%d", &aux);
    return aux;
}


