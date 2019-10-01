#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_validar.h"
#include "persona.h"


/** \brief  para indicar que todas las posiciones del vector estan vacias,
*          esta funcion pone la bandera isEmpty en verdadero en cada
*          posicion del vector
* \param estructura eEmpleado
* \param tamaño del vector
* \return retorna (-1) si da error [tamaño invalido o puntero a NULL] - (0) si esta bien
*
*/
int eEmpleado_inicializar(eEmpleado persona[], int size)
{
    int retorno=-1;
    if(persona!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            persona[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param estructura eEmpleado
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int eEmpleado_buscarLibre(eEmpleado persona[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(persona!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(persona[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param estructura eEmpleado
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int eEmpleado_buscarID(eEmpleado persona[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(persona!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(persona[i].isEmpty==1)
            {
                continue;
            }
            else if(persona[i].id==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param estructura eEmpleado
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int eEmpleado_buscarInt(eEmpleado persona[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(persona!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(persona[i].isEmpty==1)
            {
                continue;
            }
            else if(persona[i].sector==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param estructura eEmpleado
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int eEmpleado_buscarString(eEmpleado persona[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(persona!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(persona[i].isEmpty==1)
            {
                continue;
            }
            else if(strncmp(persona[i].nombre,valorBuscado,sizeof(persona[i].nombre))==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param estructura eEmpleado
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int eEmpleado_alta(eEmpleado persona[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(persona!=NULL && size>0 && contadorID!=NULL)
    {
        if(eEmpleado_buscarLibre(persona,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            persona[posicion].id=*contadorID;
            persona[posicion].isEmpty=0;
            utn_getUnsignedInt("\ningrese sector: ","\nError",0,sizeof(int),1,2,2,&persona[posicion].sector);
            utn_getFloat("\ningrese salario: ","\nError",0,sizeof(double),1,20,2,&persona[posicion].salario);
            utn_getName("\ningrese nombre: ","\nError",1,TEXT_SIZE,1,persona[posicion].nombre);
            utn_getTexto("\ningrese apellido: ","\nError",1,TEXT_SIZE,1,persona[posicion].apellido);
            printf("\n Posicion: %d\n ID: %d\n sector: %d\n salario: %.2f\n nombre: %s\n apellido: %s",
                   posicion, persona[posicion].id,persona[posicion].sector,persona[posicion].salario,persona[posicion].nombre,persona[posicion].apellido);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param estructura empleado
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int eEmpleado_baja(eEmpleado persona[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(persona!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(eEmpleado_buscarID(persona,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            persona[posicion].isEmpty=1;
            persona[posicion].id=0;
            persona[posicion].sector=0;
            persona[posicion].salario=0;
            strncpy(persona[posicion].nombre,"",sizeof(persona[posicion].nombre));
            strncpy(persona[posicion].apellido,"",sizeof(persona[posicion].apellido));
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param estructura persona
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int eEmpleado_bajaValorRepetidoInt(eEmpleado persona[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(persona!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(persona[i].id==valorBuscado)
            {
                persona[i].isEmpty=1;
                persona[i].id=0;
                persona[i].sector=0;
                persona[i].salario=0;
                strncpy(persona[i].nombre,"",sizeof(persona[i].nombre));
                strncpy(persona[i].apellido,"",sizeof(persona[i].apellido));
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param estructura persona
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int eEmpleado_modificar(eEmpleado persona[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(persona!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(eEmpleado_buscarID(persona,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n A-sector: %d\n B-salario: %.2f\n C-nombre: %s\n D-apellido: %s",
                       posicion, persona[posicion].id,persona[posicion].sector,persona[posicion].salario,persona[posicion].nombre,persona[posicion].apellido);
                utn_getChar("\nModificar: A B C D S(salir)","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",0,sizeof(int),1,2,2,&persona[posicion].sector);
                        break;
                    case 'B':
                        utn_getFloat("\n: ","\nError",1,sizeof(double),0,1,1,&persona[posicion].salario);
                        break;
                    case 'C':
                        utn_getName("\n: ","\nError",1,TEXT_SIZE,1,persona[posicion].nombre);
                        break;
                    case 'D':
                        utn_getTexto("\n: ","\nError",1,TEXT_SIZE,1,persona[posicion].apellido);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array
* \param estructura persona
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int eEmpleado_ordenarPorString(eEmpleado persona[],int size)
{
    int retorno=-1;
    int i, j;
    char bufferNombre[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;

    int bufferSector;
    float bufferSalario;
    char bufferApellido[TEXT_SIZE];

    if(persona!=NULL && size>=0)
    {
        for (i = 1; i < size; i++)
        {
            strncpy(bufferNombre,persona[i].nombre,sizeof(bufferNombre));
            bufferId=persona[i].id;
            bufferIsEmpty=persona[i].isEmpty;

            bufferSector=persona[i].sector;
            bufferSalario=persona[i].salario;
            strncpy(bufferApellido,persona[i].apellido,sizeof(bufferApellido));


            j = i - 1;
            while ((j >= 0) && strncmp(bufferNombre,persona[j].nombre,sizeof(bufferNombre))<0)          //Si tiene mas de un criterio se lo agrego, Ej. bufferInt<array[j].varInt
            {                                                                   //buffer < campo ascendente   buffer > campo descendente
                strncpy(persona[j + 1].nombre,persona[j].nombre,sizeof(persona[j].nombre));
                persona[j + 1].id=persona[j].id;                                //cambiar campo id
                persona[j + 1].isEmpty=persona[j].isEmpty;

                persona[j + 1].sector=persona[j].sector;
                persona[j + 1].salario=persona[j].salario;
                strncpy(persona[j + 1].apellido,persona[j].apellido,sizeof(persona[j].apellido));

                j--;
            }
            strncpy(persona[j + 1].nombre,bufferNombre,sizeof(bufferNombre));
            persona[j + 1].id=bufferId;                                        //cambiar campo id
            persona[j + 1].isEmpty=bufferIsEmpty;

            persona[j + 1].sector=bufferSector;
            persona[j + 1].salario=bufferSalario;
            strncpy(persona[j + 1].apellido,bufferApellido,sizeof(bufferApellido));
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param estructura persona
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int eEmpleado_listar(eEmpleado persona[], int size)
{
    int retorno=-1;
    int i;
    if(persona!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(persona[i].isEmpty==1)
            {
                continue;
            }
            else{
                printf("\n ID: %d\n sector: %d\n salario: %.2f\n nombre: %s\n apellido: %s",
                       persona[i].id,persona[i].sector,persona[i].salario,persona[i].nombre,persona[i].apellido);
            }
        }
        retorno=0;
    }
    return retorno;
}
