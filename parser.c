 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "bicicletas.h"
#include "input.h"
#include "parser.h"


void parser_LoadFromText(LinkedList *list, char* path)
{
    FILE *pFile;
    char id[20];
    char nombre[51];
    char tipo[20];
    char tiempo[20];

    int quantityRead;
    pFile = fopen(path,"r");
    if(pFile != NULL)
    {
        /*fscanf Lee datos formateados desde fichero
        Parámetros: El identificador del fichero, la cadena de formato y la(s) variable(s) en que se guardarán los datos.
        Generalmente las variables deberán aparecer precedidas por "&" (excepto cadenas). Devuelve la cantidad de datos
         leídos (0 si ninguno, EOF en caso de error)

        Valor devuelto: La cantidad de datos leídos*/

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",id,nombre,tipo,tiempo);
        while(!feof(pFile))
        {
            quantityRead = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",id,nombre,tipo,tiempo);
            if(quantityRead == 0)
            {
                break;
            }
            eBicicleta *nuevaBicicleta = bicicleta_newParametros(id,nombre,tipo,tiempo);
            if(ll_add(list,nuevaBicicleta))
            {
                printf("\nError");
                continue;
            }
        }
        if(fclose(pFile))
        {
            printf("\nERROR AL CERRAR EL ARCHIVO");
        }
    }
    else
        printf("\nError al abrir el archivo");
}



void parser_SaveFromText(LinkedList *list, char* path)
{
    FILE *pFile;
    int len = ll_len(list);
    int i;
    int quantityWrite;
    pFile = fopen(path,"w");
    if(pFile != NULL)
    {
        fprintf(pFile,"ID_Bike,Nombre,Tipo,Tiempo\n");
        for(i=0;i<len;i++)
        {
            eBicicleta* bicicleta = ll_get(list,i);
            quantityWrite = fprintf(pFile,"%d,%s,%s,%d\n",
                                    bicicleta->id,
                                    bicicleta->nombre,
                                    bicicleta->tipo,
                                    bicicleta->tiempo);
            if(quantityWrite == 0)
            {
                break;
            }
        }
        if(fclose(pFile))
        {
            printf("\nERROR AL CERRAR EL ARCHIVO");
        }
    }
    else
        printf("\nError al abrir el archivo");
}

