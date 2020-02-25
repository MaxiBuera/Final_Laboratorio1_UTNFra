#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "input.h"
#include "LinkedList.h"
#include "bicicletas.h"
#include "parser.h"



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

int bicicleta_filter(void* nuevaBicicleta)
{
    int returnAux = 0;

    if(nuevaBicicleta != NULL)
    {
        char *tipo;
        nuevaBicicleta = (eBicicleta*)nuevaBicicleta;

        bicicleta_getTipo(nuevaBicicleta, tipo);

        if(strcmp("BMX",tipo))
            returnAux = 1;
    }

    return returnAux;
}
