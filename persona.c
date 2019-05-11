#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../librerias/persona.h"

void alta( eEmpleado pers[], int cantidad ){
    int i=0;
    char rta;

        do{
            pers[i].id=i+1;

            printf("Apellido:\n");
            fflush(stdin);
            scanf("%s", pers[i].apellido);

            printf("Nombre:\n");
            fflush(stdin);
            scanf("%s", pers[i].nombre);

            printf("Salario:\n");
            fflush(stdin);
            scanf("%f", &pers[i].salario);

            printf("Sector:\n");
            fflush(stdin);
            scanf("%d",&pers[i].sector);

            pers[i].isEmpty = 0;

            i++;

            if (i<cantidad) {
                printf("Desea seguir?[S/N]");
                fflush(stdin);
                scanf("%c",&rta);
                rta=toupper(rta);
            }

        }while(rta=='S'&&i<cantidad);

}

void mostrarTodos( eEmpleado pers[], int cantidad ){
    int i;

    for( i = 0; i < cantidad; i++ ){
        if (pers[i].isEmpty==0){
            mostrarUno(pers[i]);
        }

    }

}

void mostrarUno( eEmpleado per ){
        printf("%d\t%s\t%s\t%.2f\t%d\t%d\t\n",per.id, per.apellido, per.nombre, per.salario, per.sector,per.isEmpty);
}

void baja( eEmpleado pers[], int cantidad){

    int idAux,i;

    printf("Ingrese id a dar de baja:\n");
    scanf("%d",&idAux);

    for (i=0;i<cantidad;i++){

            if (idAux==pers[i].id){

                pers[i].isEmpty=1;
                break;
            }
    }
}

void modificacion (eEmpleado pers[],int cantidad){

    int idAux,i,flag=0;

    printf("Ingrese el id a modificar:\n");
    scanf("%d",&idAux);

    for(i=0;i<cantidad;i++){

        if (idAux==pers[i].id&&pers[i].isEmpty==0){

            mostrarUno(pers[i]);

            printf("Apellido:\n");
            fflush(stdin);
            scanf("%s", pers[i].apellido);

            printf("Nombre:\n");
            fflush(stdin);
            scanf("%s", pers[i].nombre);

            printf("Salario:\n");
            scanf("%2f", &pers[i].salario);

            flag=1;
        }
    }
    if (flag==0){

        printf("No se encontro el id\n");
        system("pause");
    }
}

void listarSalario(eEmpleado pers[],int cantidad){
    int i,j=0;
    float sumaAux=0,totalSalarios;

    for(i=0;i<cantidad;i++)
    {
        sumaAux=pers[i].salario+sumaAux;

        if((sumaAux/i)<pers[i].salario)
        {
            j++;
        }
    }
    printf("El total de los salarios son: %.2f\n",&sumaAux);

    totalSalarios=sumaAux/i;
    printf("El promedio de los salarios es: %.2f\n",&(totalSalarios));

    printf("El total de salarios que superan el promedio es: %d",&j);
}
