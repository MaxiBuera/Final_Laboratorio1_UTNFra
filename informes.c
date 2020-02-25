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
    printf("ID      NOMBRE        TIPO       TIEMPO       ");
    printf("\n-------------------------------------------------------------------------------\n");
}

void bicicleta_printHeader2(void)
{
    printf("\n-------------------------------------------------------------------------------\n");
    printf("ID      NOMBRE        TIPO       TIEMPO       V.PROMEDIO");
    printf("\n-------------------------------------------------------------------------------\n");
}


void bicicleta_imprimirBicicleta(eBicicleta* nuevaBicicleta,int flag)
{
    if(nuevaBicicleta != NULL)
    {
        int id, tiempo;
        char nombre[128], tipo[128];
        float velocidadPromedio;

        bicicleta_getId(nuevaBicicleta, &id);
        bicicleta_getNombre(nuevaBicicleta, nombre);
        bicicleta_getTipo(nuevaBicicleta, tipo);
        bicicleta_getTiempo(nuevaBicicleta, &tiempo);

        if(flag == 0){

            printf("%d %12s %12s %9d\n", id, nombre, tipo, tiempo);
        }
        else{
            bicicleta_getVelocidadPromedio(nuevaBicicleta, &velocidadPromedio);
            printf("%d %12s %12s %9d %14.2f\n", id, nombre, tipo, tiempo,velocidadPromedio);
        }

    }
}

void bicicleta_imprimirListaBicicletas(LinkedList* list,int flag)
{
    if(list != NULL)
    {
        int i;
        eBicicleta* nuevaBicicleta;

        if(flag == 0 ){

            bicicleta_printHeader();
            for(i=0; i<ll_len(list); i++)
            {
                nuevaBicicleta = ll_get(list, i);
                bicicleta_imprimirBicicleta(nuevaBicicleta,flag);
            }
        }
        else{

            bicicleta_printHeader2();
            for(i=0; i<ll_len(list); i++)
            {
                nuevaBicicleta = ll_get(list, i);
                bicicleta_imprimirBicicleta(nuevaBicicleta,flag);
            }
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


