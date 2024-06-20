#ifndef COLAESTATICA_H_INCLUDED
#define COLAESTATICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINIMO(X,Y) ((X < Y) ? X : Y)
#define TAM_COLA 1000

typedef struct
{
    char vec[TAM_COLA];
    unsigned pri,ult;
    size_t tam_disponible;
}t_cola;

void crear_cola(t_cola* pc);
int poner_en_cola(t_cola* pc,void* pd, size_t tamElem);
int sacar_de_cola(t_cola* pc, void* pd,size_t tamElem);
int cola_llena(t_cola* pc,void* pd,size_t tamElem);

#endif // COLAESTATICA_H_INCLUDED
