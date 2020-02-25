#ifndef bicicleta_H_INCLUDED
#define bicicleta_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    char tipo[128];
    int tiempo;
}eBicicleta;

#endif // bicicleta_H_INCLUDED
eBicicleta* bicicleta_newParametros(char* idStr,char* nombreStr,char* tipoStr,char* tiempoStr);
eBicicleta* bicicleta_newParametros2(char* nombre,char* tipo,int tiempo);/*
eBicicleta* bicicleta_newParametros3(int id,char* nombre,int horasTrabajadas,int sueldo);
eBicicleta* bicicleta_newParametros4(int id,char* nombre,int horasTrabajadas,int sueldo);*/
eBicicleta* bicicleta_new();
void bicicleta_delete(eBicicleta* this);

int bicicleta_setId(eBicicleta* this,int id);
int bicicleta_getId(eBicicleta* this,int* id);

char bicicleta_setNombre(eBicicleta* this,char* nombre);
char bicicleta_getNombre(eBicicleta* this,char* nombre);

char bicicleta_setTipo(eBicicleta* this,char* tipo);
char bicicleta_getTipo(eBicicleta* this,char* tipo);

int bicicleta_setTiempo(eBicicleta* this,int tiempo);
int bicicleta_getTiempo(eBicicleta* this,int* tiempo);

int bicicleta_filter(void* nuevaBicicleta)
