#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char getChar(char mensaje[]){

    char letra;

    printf("%s",mensaje);
    scanf("%c",&letra);

    return letra;
}

int getInt(char mensaje[]){

    int entero;

    printf("%s",mensaje);
    scanf("%d",&entero);

    return entero;
}

float getFloat(char mensaje[]){

    float numero;

    printf("%s",mensaje);
    scanf("%f",&numero);

    return numero;
}

char* getString(char mensaje[]){

    char texto[101];

    printf("%s",mensaje);
    fgets(texto,sizeof(texto)-2,stdin);

    return texto;
}
