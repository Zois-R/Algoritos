#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

#define minimo(x,y) ((x) <= (y) ? (x):(y))
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct sNodo
{
  void *dato;
  unsigned tamDato;
  struct sNodo *sig;
}tNodo;

typedef tNodo *tPila;

void crearPila(tPila *p);
int ponerEnPila(tPila *p, const void *dato, unsigned cantBytes);
int pilaLlena(const tPila *p, unsigned cantBytes);
int pilaVacia(const tPila*p);
int sacarDePila(tPila *p, void *dato, unsigned cantBytes);
void vaciarPila(tPila *p);
int verTope(const tPila *p, void *dato, unsigned cantBytes);

#endif // PILADINAMICA_H_INCLUDED
