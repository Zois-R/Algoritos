#ifndef COLA_DINAMICA_H_INCLUDED
#define COLA_DINAMICA_H_INCLUDED

#define minimo(X,Y) ( (X) < (Y) ? (X) : (Y))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sNodo
{
  void *dato;
  unsigned tamDato;
  struct sNodo *sig;
}tNodo;

typedef struct
{
  tNodo *ult,
        *pri;
}tCola;

void crearCola(tCola *pc);
void vaciarCola(tCola *pc);
int colaVacia(const tCola *pc);
int colaLlena(const tCola *pc, unsigned cantBytes);
int ponerEnCola(tCola *pc, const void *dato, unsigned cantBytes);
int sacarDeCola(tCola *pc, void *dato, unsigned cantBytes);
int verPrimero(const tCola *pc, void *dato, unsigned cantBytes);
#endif // COLA_DINAMICA_H_INCLUDED
