#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "input.h"
#include "LinkedList.h"
#include "bicicletas.h"



static int proximoId();

eBicicleta* bicicleta_newParametros(char* idStr,char* nombreStr,char* tipoStr,char* tiempoStr)
{
    eBicicleta* this;
    this = bicicleta_new();

    char id; //si el id viene del archivo
    char nombre[128];
    char tipo[128];
    int tiempo;

    id = atoi(idStr);
    strcpy(nombre,nombreStr);
    strcpy(tipo,tipoStr);
    tiempo = atoi(tiempoStr);// convierte cadena a entero

    //bicicleta_setId(this,proximoId());
    bicicleta_setId(this,id);
    bicicleta_setNombre(this,nombre);
    bicicleta_setTipo(this,tipo);
    bicicleta_setTiempo(this,tiempo);

    return this;
}

eBicicleta* bicicleta_newParametros2(char* nombre,char* tipo,int tiempo){

    eBicicleta* this;
    this = bicicleta_new();

    if(     !bicicleta_setId(this, proximoId())
       &&   !bicicleta_setNombre(this, nombre)
       &&   !bicicleta_setTipo(this, tipo)
       &&   !bicicleta_setTiempo(this,tiempo))
    {
         return this;
    }
    bicicleta_delete(this);
    return NULL;
}
/*
eBicicleta* bicicleta_newParametros3(int id,char* nombre,int horasTrabajadas,int sueldo){

    eBicicleta* this;
    this = bicicleta_new();

    if(     !bicicleta_setId(this, id)
       &&   !bicicleta_setNombre(this, nombre)
       &&   !bicicleta_setHorasTrabajadas(this, horasTrabajadas)
       &&   !bicicleta_setSueldo(this,sueldo))
    {
         return this;
    }
    bicicleta_delete(this);
    return NULL;
}

eBicicleta* bicicleta_newParametros4(int id,char* nombre,int horasTrabajadas,int sueldo){

    eBicicleta* this;
    this = bicicleta_new();

    if(     !bicicleta_setId(this, proximoId())
       &&   !bicicleta_setNombre(this, nombre)
       &&   !bicicleta_setHorasTrabajadas(this, horasTrabajadas)
       &&   !bicicleta_setSueldo(this,sueldo))
    {
         return this;
    }
    bicicleta_delete(this);
    return NULL;
}*/

eBicicleta* bicicleta_new()
{
    return malloc(sizeof(eBicicleta));
}

void bicicleta_delete(eBicicleta* this)
{
    free(this);
}


int  bicicleta_setId(eBicicleta* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {

        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int bicicleta_getId(eBicicleta* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {

        *id = this->id;
         retorno = 0;
    }
    return retorno;
}


char  bicicleta_setNombre(eBicicleta* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {

        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}


char bicicleta_getNombre(eBicicleta* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {

        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;

}

//asd


char  bicicleta_setTipo(eBicicleta* this, char* tipo)
{
    int retorno = -1;
    if(this != NULL && tipo != NULL)
    {

        strcpy(this->tipo,tipo);
        retorno = 0;
    }
    return retorno;
}


char bicicleta_getTipo(eBicicleta* this, char* tipo)
{
    int retorno = -1;
    if(this != NULL && tipo != NULL)
    {

        strcpy(tipo,this->tipo);
        retorno = 0;
    }
    return retorno;

}


int bicicleta_setTiempo(eBicicleta* this,int tiempo)
{
    int retorno = -1;
    if(this != NULL && tiempo >= 0)
    {
        this->tiempo=tiempo;
        retorno = 0;
    }
    return retorno;
}

int bicicleta_getTiempo(eBicicleta* this , int* tiempo )
{
    int retorno = -1;

    if( (this != NULL) && (tiempo != NULL) )
    {
        *tiempo = this->tiempo;
        retorno = 0;
    }

    return retorno;
}

static int proximoId()
{
    static int ultimoId = 0;
    ultimoId++;
    return ultimoId;
}


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


