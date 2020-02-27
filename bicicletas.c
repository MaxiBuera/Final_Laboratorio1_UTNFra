#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "input.h"
#include "LinkedList.h"
#include "bicicletas.h"
#include "parser.h"
#include "informes.h"


static int proximoId();

eBicicleta* bicicleta_newParametros(char* idStr,char* nombreStr,char* tipoStr,char* tiempoStr)
{
    eBicicleta* this;
    this = bicicleta_new();

    char id; //si el id viene del archivo
    char nombre[128];
    char tipo[128];
    int tiempo;
    //float velocidadPromedio;

    id = atoi(idStr);
    strcpy(nombre,nombreStr);
    strcpy(tipo,tipoStr);
    tiempo = atoi(tiempoStr);// convierte cadena a entero


    //bicicleta_setId(this,proximoId());
    bicicleta_setId(this,id);
    bicicleta_setNombre(this,nombre);
    bicicleta_setTipo(this,tipo);
    bicicleta_setTiempo(this,tiempo);
    //bicicleta_setVelocidadPromedio(this,velocidadPromedio);

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
//

float bicicleta_setVelocidadPromedio(eBicicleta* this,float velocidadPromedio)
{
    int retorno = -1;
    if(this != NULL && velocidadPromedio >= 0)
    {
        this->velocidadPromedio=velocidadPromedio;
        retorno = 0;
    }
    return retorno;
}

float bicicleta_getVelocidadPromedio(eBicicleta* this , float* velocidadPromedio )
{
    int retorno = -1;

    if( (this != NULL) && (velocidadPromedio != NULL) )
    {
        *velocidadPromedio = this->velocidadPromedio;
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


int bicicleta_velocidadPromedio(void* auxBicicleta){

    int retorno = -1;

    if(auxBicicleta != NULL){

        int tiempo;
        float tiempoHora;
        float t;
        float velocidadPromedio;
        auxBicicleta = (eBicicleta*)auxBicicleta;

        bicicleta_getTiempo(auxBicicleta, &tiempo);

        t = (float)tiempo;

        tiempoHora = t*0.01666666666;

        velocidadPromedio = 10/tiempoHora;
        bicicleta_setVelocidadPromedio(auxBicicleta,velocidadPromedio);


        retorno = 0;
    }
    return retorno;
}

int bicicleta_filterBMX(void* nuevaBicicleta)
{
    int retorno = 0;

    if( strcmp("BMX",((eBicicleta*)nuevaBicicleta)->tipo) == 0 )
    {
        retorno = 1;
    }
    return retorno;
}

int bicicleta_filterPASEO(void* nuevaBicicleta)
{
    int retorno = 0;

    if( strcmp("PASEO",((eBicicleta*)nuevaBicicleta)->tipo) == 0 )
    {
        retorno = 1;
    }
    return retorno;
}

int bicicleta_filterMTB(void* nuevaBicicleta)
{
    int retorno = 0;

    if( strcmp("MTB",((eBicicleta*)nuevaBicicleta)->tipo) == 0 )
    {
        retorno = 1;
    }
    return retorno;
}

int bicicleta_filterPLAYERA(void* nuevaBicicleta)
{
    int retorno = 0;

    if( strcmp("PLAYERA",((eBicicleta*)nuevaBicicleta)->tipo) == 0)
    {
        retorno = 1;
    }
    return retorno;
}

int bicicleta_sortByTipo(void* aux1,void* aux2)
{
    int retorno = 0;

    if( (aux1 != NULL) && (aux2 != NULL) )
    {
        char tipo1[128];
        char tipo2[128];

        bicicleta_getTipo(aux1, tipo1);
        bicicleta_getTipo(aux2, tipo2);

        if(hours1 > hours2)
            retorno = 1;
        else
        {
            if(hours1 < hours2)
                retorno = -1;
        }
    }

    return retorno;
}

