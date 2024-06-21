#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TODO_BIEN 1
#define SIN_MEM -3
#define CLA_DUPL -2
typedef struct sNodo
{
  void *info;
  struct sNodo *sig,
               *ant;
  unsigned tamInfo;
}tNodo;

typedef tNodo *tListaD;

void crearListaD(tListaD *pl);
int listaDobleVacia(const tListaD *pl);
int listaDobleLlena(const tListaD *pl, unsigned cantBytes);
int vaciarListaDoble(tListaD *pl);
int insertarAlFinalListaDoble(tListaD *pl, const void *d, unsigned cantBytes);
int mostrarIzqADerListaD(const tListaD *pl, void (*mostrar)(const void*));
int mostrarDerAIzqListaD(const tListaD *pl,void (*mostrar)(const void*));
void mostrarEntero(const void *d);
int eliminarPorClaveListaDoble(tListaD *pl,  void *d,unsigned cantBytes,int (*cmp)(const void*,const void*));
int compararEntero(const void *a, const void *b);
#endif // LISTADOBLE_H_INCLUDED
