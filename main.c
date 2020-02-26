#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "bicicletas.h"
#include "input.h"
#include "parser.h"
#include "informes.h"


int main()
{
    LinkedList *list = ll_newLinkedList();

    //LinkedList* pArraySubList;
    LinkedList* listaPorTipo;

    int opcion;
    int opcion2;
    int flag=0;
    do
    {
        opcion = menu_Principal("\n\n1.Cargar archivo"
                                "\n2.Imprimir lista"
                                "\n3.Calcular velocidad promedio"
                                "\n4.Filtrar por tipo"
                                "\n5.Mostrar posiciones"
                                "\n6.SALIR\n"
                            "\nElegir opcion: ");

        switch(opcion )
        {
        case 1:
            parser_LoadFromText(list,"bicicletas_v3.csv");
            printf("\nDatos Cargados ...\n");
            break;
        case 2:
            if(ll_len(list))
            {printf("%d aca\n",flag);
                if(flag==0){
                    bicicleta_imprimirListaBicicletas(list,flag);
                }
                else{
                    bicicleta_imprimirListaBicicletas(list,flag);
                }
            }
            break;
        case 3:
            if(ll_len(list))
                {
                    ll_map(list, bicicleta_velocidadPromedio);
                    flag++;
                    printf("\nVelocidad Promedio Agregada...\n");
                }
                else
                    printf("\nEl archivo aun no ha sido cargado.\n");
                break;
        case 4:
            if(ll_len(list))
            {
                do{
                    opcion2 = menu_Principal("\n1.BMX"
                                              "\n2.PLAYERA"
                                              "\n3.MTB"
                                              "\n4.PASEO\n"
                                            "\nElegir opcion: ");

                    switch(opcion2)
                    {
                    case 1:
                        listaPorTipo = ll_filter(list,bicicleta_filterBMX);
                        break;
                    case 2:
                        listaPorTipo = ll_filter(list,bicicleta_filterPLAYERA);
                        break;
                    case 3:
                        listaPorTipo = ll_filter(list,bicicleta_filterMTB);
                        break;
                    case 4:
                        listaPorTipo = ll_filter(list,bicicleta_filterPASEO);
                        break;
                    }
                }while(opcion2<=1 && opcion2 >=4);

                parser_SaveFromText(listaPorTipo,"listaPorTipo.txt");
            }
                break;
        case 5:
            if(ll_len(list))
            {
              //  bicicleta_sortBicicletas(list);
               // bicicleta_sortByTiempo(list);
                //bicicleta_imprimirListaBicicletas(list);

            }
            break;


        }
    }while(opcion != 6);




    return 0;
}
