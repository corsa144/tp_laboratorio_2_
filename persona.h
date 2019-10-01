#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED

#define TEXT_SIZE 50

typedef struct
{
    int id;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    int sector;
    float salario;
    char apellido[TEXT_SIZE];

}eEmpleado;


#endif // ABM_H_INCLUDED

int eEmpleado_inicializar(eEmpleado persona[], int size);
int eEmpleado_buscarLibre(eEmpleado persona[], int size, int* posicion);
int eEmpleado_buscarID(eEmpleado persona[], int size, int valorBuscado, int* posicion);
int eEmpleado_buscarInt(eEmpleado persona[], int size, int valorBuscado, int* posicion);
int eEmpleado_buscarString(eEmpleado persona[], int size, char* valorBuscado, int* indice);
int eEmpleado_alta(eEmpleado persona[], int size, int* contadorID);
int eEmpleado_baja(eEmpleado persona[], int sizeArray);
int eEmpleado_bajaValorRepetidoInt(eEmpleado persona[], int sizeArray, int valorBuscado);
int eEmpleado_modificar(eEmpleado persona[], int sizeArray);
int eEmpleado_ordenarPorString(eEmpleado persona[],int size);
int eEmpleado_listar(eEmpleado persona[], int size);
