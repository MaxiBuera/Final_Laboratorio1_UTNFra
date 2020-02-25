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


    LinkedList* pArraySubList;
    //LinkedList* listaProblemaExpecifico;
    int opcion;
    /*int opcion2;*/
    do
    {
        opcion = menu_Principal("\n1.Cargar archivo"
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
            {
               bicicleta_imprimirListaBicicletas(list);
            }
            break;
        case 3:
            if(ll_len(list))
                {
                  //  ll_map(list, bicicleta_velocidadPromedio);
                    //printf("\n");
                }
                else
                    printf("\nEl archivo aun no ha sido cargado.\n");
                break;
        case 4:
            if(ll_len(list))
            {
               pArraySubList = ll_filter(list, bicicleta_filterType);
               bicicleta_imprimirListaBicicletas(pArraySubList);
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


