#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define minimo(x,y) ( x < y ? x:y)

typedef struct sNodo
{
  void *dato;
  unsigned tamDato;
  struct sNodo *sig;

}tNodo;

typedef tNodo *tLista;

void crearLista(tLista *pl);
int listaLlena(const tLista *pl, unsigned cantBytes);
int listaVacia(const tLista *pl);
int ponerAlComienzoListaSimple(tLista *pl, const void *dato, unsigned cantBytes);
int ponerAlFinalListaSimple(tLista *pl, const void *dato, unsigned cantBytes);

int sacarPrimeroLista(tLista *pl, void *dato, unsigned cantBytes);
int sacarDelFinalLista(tLista *pl, void *dato, unsigned cantBytes);
int verPrimeroLista(const tLista *pl, void *dato, unsigned cantBytes);
int verUltimoLista(const tLista *pl, void *dato, unsigned cantBytes);
void vaciarLista(tLista *pl);


//typedef struct sNodo
//{
//  void *info;
//  struct sNodo *sig;
//  size_t tamInfo;
//}tNodo;
//
//typedef tNodo *tLista;
//
//void crearLista(tLista *pl);


#endif // LISTA_H_INCLUDED
