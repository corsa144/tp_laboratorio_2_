#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_validar.h"
#include "persona.h"
#include "informes.h"

/**brief ordena por apellido y sector
*param estructura persona
*param tamaño del array
*return retorna 0 en caso de que este correcto y -1 en caso de error
*/
int ordenarPorApellidoYSector(eEmpleado persona[],int size)
{
    int i;
    int retorno=-1;
    int NoEstaOrdenado=1;
    eEmpleado personaAux;
    if(persona != NULL && size>0){
    retorno=0;
    while(NoEstaOrdenado==1)
    {
        NoEstaOrdenado=0;

            for(i=1;i<size;i++)
            {

                if(strncmp(persona[i].apellido,persona[i-1].apellido,sizeof(persona[i].apellido))<0)
                {
                    personaAux=persona[i];
                    persona[i]=persona[i-1];
                    persona[i-1]=personaAux;
                    NoEstaOrdenado=1;


                }else if(strncmp(persona[i].apellido,persona[i-1].apellido,sizeof(persona[i].apellido))==0 && persona[i].sector<persona[i-1].sector)
                {
                    personaAux=persona[i];
                    persona[i]=persona[i-1];
                    persona[i-1]=personaAux;
                    NoEstaOrdenado=1;

                }

            }

    }
    }
    return retorno;
}

/**brief muestra total, promedio y cantidad que supera el promedio de salarios
*param estructura empleado
*param tamaño del array
*param contadorID
*return retorna 0 en caso de que este correcto y -1 en caso de error
*/
int mostrarSalarios(eEmpleado persona[],int size,int* contadorID)
{
    int i;
    int contadorSuperaSalario=0;
    float acumulador=0;
    float salarioValido=0;
    float salarioPromedio;
    int retorno=-1;

    if(persona != NULL && size > 0)
    {
        retorno=0;
        for(i=0;i<size;i++)
        {
            if(persona[i].isEmpty==0)
            {
                acumulador+=persona[i].salario;
                salarioValido++;
            }

        }
    }
    printf("\nel total de los salarios suma: %.2f",acumulador);
    salarioPromedio=acumulador/salarioValido;
    printf("\nel salario promedio es: %.2f",salarioPromedio);

    for(i=0;i<size;i++)
    {
        if(persona[i].isEmpty==0&&persona[i].salario>salarioPromedio)
        {
            contadorSuperaSalario++;
        }
    }
    printf("\nlos salarios que superan el promedio son: %d",contadorSuperaSalario);
    return retorno;
}
