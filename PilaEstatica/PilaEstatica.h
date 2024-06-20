#ifndef PILAESTATICA_H_INCLUDED
#define PILAESTATICA_H_INCLUDED

#include <string.h>
#define TAM_PILA 1000
#define minimo(x,y) ((x) < (y)?(x):(y))
typedef struct
{
  char pila[TAM_PILA];
  unsigned tope;
}tPila;

void crearPila(tPila *p);
int pilaLlena(const tPila *p,unsigned cantBytes);
int pilaVacia(const tPila *p);
void vaciarPila(tPila *p);
int ponerEnPila(tPila *p,const void *dato, unsigned cantBytes);
int verTope(const tPila *p,void *dato, unsigned cantBytes);
int sacarDePila(tPila *p, void *dato ,unsigned cantBytes);



#endif // PILAESTATICA_H_INCLUDED
