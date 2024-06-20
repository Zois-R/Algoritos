#include "PilaDinamica.h"


void crearPila(tPila *p)
{
  *p = NULL;
}

int pilaLlena(const tPila *p, unsigned cantBytes)
{
  tNodo *aux = (tNodo*)malloc(sizeof(tNodo));
  void *info = malloc(cantBytes);

  free(aux);
  free(info);
  return aux == NULL || info == NULL;
}

int pilaVacia(const tPila *p)
{
  return *p == NULL;
}

int ponerEnPila(tPila *p,const void *dato, unsigned cantBytes)
{
  tNodo *nue;
  /// VERIFICO QUE NO SEA PILLA LLENA
  if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL ||
      (nue->dato = malloc(cantBytes)) == NULL)
  {
    free(nue);
    return 0;
  }
  /// meto el dato en la pila
  memcpy(nue->dato,dato,cantBytes);
  /// le asigno cantidad de bytes al tam del dato
  nue->tamDato = cantBytes;
  ///
  nue->sig = *p;
  *p = nue;
  return 1;
}


int verTope(const tPila *p, void *d, unsigned cantBytes)
{
  if(*p == NULL)
    return 0;
  memcpy(d, (*p)->dato,minimo(cantBytes,(*p)->tamDato));
  return 1;
}

int sacarDePila(tPila *p, void *d,unsigned cantBytes)
{
  tNodo *aux = *p;

  if(aux == NULL)
    return 0;
  *p = aux->sig;
  memcpy(d,aux->dato,minimo(cantBytes,aux->tamDato));
  free(aux->dato);
  free(aux);
  return 1;

}
void vaciarPila(tPila *p)
{
  while(*p)
    {
      tNodo *aux = *p;
      *p = aux->sig;
      free(aux->dato);
      free(aux);
    }
}
