#include "Cola Dinamica.h"


void crearCola(tCola *pc)
{
  pc->pri = NULL;
  pc->ult = NULL;
}


int colaLlena(const tCola *pc, unsigned cantBytes)
{
  tNodo *aux = (tNodo*)malloc(sizeof(tNodo));
  void *info = malloc(cantBytes);
  free(aux);
  free(info);
  return aux == NULL || info == NULL;
}

int ponerEnCola(tCola *pc, const void *dato, unsigned cantBytes)
{
  tNodo *nue = (tNodo*)malloc(sizeof(tNodo));

  if( nue == NULL || (nue->dato = malloc(cantBytes)) == NULL)
  {
    free(nue);
    return 0;
  }
  memcpy(nue->dato, dato, cantBytes);
  nue->tamDato = cantBytes;
  nue->sig = NULL;
  if(pc->ult)
    pc->ult->sig = nue;
  else
    pc->pri = nue;
  pc->ult = nue;
  return 1;
}


void vaciarCola(tCola *pc)
{
  while(pc->pri)
    {
      tNodo *aux = pc->pri;
      pc->pri = aux->sig;
      free(aux->dato);
      free(aux);
    }

  pc->ult = NULL;
}


int colaVacia(const tCola *pc)
{
  return pc->pri == NULL;
}


int sacarDeCola(tCola *pc, void *dato, unsigned cantBytes)
{
  tNodo *aux = pc->pri;

  if(aux == NULL)
    return 0;

  pc->pri = aux->sig;
  memcpy(dato, aux->dato,minimo(aux->tamDato,cantBytes));
  free(aux->dato);
  free(aux);
  if(pc->pri == NULL)
    pc->ult = NULL;
  return 1;
}


int verPrimero(const tCola *pc, void *dato, unsigned cantBytes)
{
  if(pc->pri == NULL)
    return 0;

  memcpy(dato,pc->pri->dato,minimo(pc->pri->tamDato,cantBytes));

  return 1;
}
