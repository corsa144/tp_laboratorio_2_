#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../librerias/persona.h"

#define CANT 3

int main(){
    int opcion;
    eEmpleado pers[CANT];
    do{
        printf("ingrese:\n1.Altas:\n2.Modificacion:\n3.Bajas:\n4.Listar:\n5.Listar salarios:\n6.Salir:");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                alta( pers,CANT);
                break;
            case 2:
                modificacion(pers,CANT);
                break;
            case 3:
                baja(pers,CANT);
                break;
            case 4:
                system("cls");
                mostrarTodos(pers,CANT);
                system("pause");
                break;
            case 5:
                system("cls");
                listarSalario(pers,CANT);
                system("pause");
                break;
        }


    }while(opcion>=1&&opcion<=5);

    return 0;
}
