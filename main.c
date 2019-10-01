#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "utn_validar.h"
#include "informes.h"

#define CANTIDAD_EMPLEADOS 1000

int main(){
    int opcion;
    int* contadorID=0;
    eEmpleado persona[CANTIDAD_EMPLEADOS];
    eEmpleado_inicializar(persona,CANTIDAD_EMPLEADOS);

    do{
        utn_getUnsignedInt("\n1-Alta:\n2-modificacion:\n3-baja:\n4-mostrar:\n5-mostrar por apellido y sector:\n6.mostrar salarios:\n7.salir:","\nError",0,sizeof(int),1,6,2,&opcion);
        switch(opcion){
            case 1:
                eEmpleado_alta( persona,CANTIDAD_EMPLEADOS,&contadorID);
                break;
            case 2:
                if(contadorID>0){
                eEmpleado_modificar(persona,CANTIDAD_EMPLEADOS);
                }else{
                    printf("\nNo se hizo ningun alta");
                }
                break;
            case 3:
                if(contadorID>0){
                eEmpleado_baja(persona,CANTIDAD_EMPLEADOS);
                }else{
                    printf("\nNo se hizo ningun alta");
                }
                break;
            case 4:
                if(contadorID>0){
                eEmpleado_listar(persona,CANTIDAD_EMPLEADOS);
                }else{
                    printf("\nNo se hizo ningun alta");
                }
                break;
            case 5:
                if(contadorID>0){
                 ordenarPorApellidoYSector( persona,CANTIDAD_EMPLEADOS);
                }else{
                    printf("\nNo se hizo ningun alta");
                }
                break;
            case 6:
            if(contadorID>0){
                 mostrarSalarios( persona,CANTIDAD_EMPLEADOS, contadorID);
            }else{
                printf("\nNo se hizo ningun alta");
            }
                break;
            case 7:
                break;
            default:
            printf("\nopcion incorrecta!!!");
        }


    }while(opcion!=7);

    return 0;
}
