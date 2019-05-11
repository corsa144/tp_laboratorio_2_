typedef struct{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;
}eEmpleado;

void alta( eEmpleado pers[], int cantidad );

void mostrarUno( eEmpleado per );

void mostrarTodos( eEmpleado pers[], int cantidad );

void baja(eEmpleado pers[], int cantidad);

void modificacion (eEmpleado pers[], int cantidad);

void listarSalario(eEmpleado pers[],int cantidad);
