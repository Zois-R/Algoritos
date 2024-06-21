#include "ListaDoble.h"


void crearListaD(tListaD *pl)
{
  *pl = NULL;
}


int listaDobleVacia(const tListaD *pl)
{
  return *pl == NULL;
}


int listaDobleLlena(const tListaD *pl, unsigned cantBytes)
{
  tNodo *nue = (tNodo*)malloc(sizeof(tNodo));
  void *info = malloc(cantBytes);
  if(!nue || !info)
    {
      return 0;
    }
  free(nue);
  free(info);
  return 1;
}

int vaciarListaDoble(tListaD *pl)
{
  int cont = 0;
  tNodo *act = *pl;
  if(act)
  {

    while(act->ant)
        act = act->ant;
  while(act)
    {
      tNodo *aux = act->sig;
      free(aux->info);
      free(aux);
      act = aux;
      cont++;
    }
    *pl = NULL;
  }
  return cont;
}

int insertarAlFinalListaDoble(tListaD *pl, const void *d, unsigned cantBytes)
{
  tNodo *act = *pl;

  if(act)
    while(act->sig)
      act = act->sig;

  tNodo *nue;
  if( (nue = (tNodo*)malloc(sizeof(tNodo))) == NULL || (nue->info = malloc(cantBytes))== NULL)
  {
    free(nue);
    return 0;
  }
  memcpy(nue->info,d,cantBytes);
  nue->tamInfo = cantBytes;

  nue->sig = NULL;
  nue->ant = act;
  if(act)
  {
    act->sig = nue;
  }
  *pl =nue;
  return 1;
}

int mostrarIzqADerListaD(const tListaD *pl, void (*mostrar)(const void*))
{
  tNodo *mue = *pl;
  int cant = 0;

  if(mue)
    {
      while(mue->ant)
      {
        mue = mue->ant;
      }

      while(mue)
        {
          mostrar(mue->info);
          mue = mue->sig;
          cant++;
        }

    }
    return cant;

}


int mostrarDerAIzqListaD(const tListaD *pl, void (*mostrar)(const void*))
{
  tNodo *act = *pl;
  int cont = 0;
  if(act)
  {
    while(act->sig)
      act = act->sig;

    while(act)
      {
        mostrar(act->info);
        act = act->ant;
        cont++;
      }
  }
  return cont;
}



void mostrarEntero(const void *d)
{
  const int *a = (const int*)d;
  printf("[%d] ",*a);
}




int insertarEnOrdenListaDoble(tListaD *pl, const void *d,unsigned cantBytes,
                              int (*cmp)(const void *,const void *),
                              int (*acumular)(void**,unsigned *,const void *,unsigned))
{
  tNodo *act = *pl,
        *sig,
        *ant,
        *nue;

  if(act == NULL) /// si la lista está vacía
  {
      ant = NULL;
      sig = NULL;
  }
  else
  {
    int aux;
    while(act->sig && cmp(act->info,d) < 0) /// mientras haya siguiente y el dato es mayor a lo que tengo en lista
      act = act->sig; // me muevo para la derecha
    while(act->ant && cmp(act->info,d) >0) /// mientras haya anterior y el dato es menor a lo que tengo en lista
      act = act->ant; /// me muevo para la izq
    aux = cmp(act->info,d); /// PARA QUE CREAMOS AUX? le asigno el valor de la comparación
    if(aux == 0) /// si aux es 0 quiere decir que el valor que queremos insertar ya está en la lista
      {
        *pl = act; /// posicionamos el puntero a lista en la dirección del nodo actual
        if(acumular) /// si llamamos a la función acumular
          if(acumular(&act->info,&act->tamInfo,d,cantBytes) == 0) ///si acumular falla
            return SIN_MEM;
        return CLA_DUPL; /// duplicado

      }
    if(aux < 0) // si lo que tengo en lista es menor al dato que quiero ingresar ponele que tengo un [5] e ingreso un [8] despues
    {
      ant = act; /// el puntero ant que no tiene nada va a puntar al 5 que es el nodo actual
      sig = act->sig; /// el puntero sig va a apuntar a lo que apunte 5->sig
    }
    else
    {/// si lo que tengo en lista es mayor al dato a ingresar, suponiendo que  tengo un [5] que es el primero y quiero ingresar un [3] a la izq
      ant = act->ant;  /// el puntero ant va a guardar [5]->ant que sería NULL en este caso, podría aputnar a otro nodo
      sig = act; /// y sig va a guardar la dirección de [5]
    }

  }
  if ((nue = (tNodo*)malloc(sizeof(tNodo)))== NULL || (nue->info = malloc(cantBytes)) == NULL)
  {
    free(nue);
    return SIN_MEM;
  }
  memcpy(nue->info,d,cantBytes);
  nue->tamInfo = cantBytes;
  nue->sig = sig;
  nue->ant = ant;
  if(sig)
    sig->ant = nue;

  if(ant)
    ant->sig = nue;
  *pl = nue;
  return TODO_BIEN;

}

int eliminarPorClaveListaDoble(tListaD *pl,  void *d,unsigned cantBytes,int (*cmp)(const void*,const void*))
{ //// SOLO PARA LISTA DOBLE ORDENADA, SI ESTÁ DESORDENADA NOS VAMOS A LA IZQUIERDA Y COMPARAMOS
  tNodo *act = *pl;
  int comp;
  while(act->sig && cmp(act->info,d)<0)
    act = act->sig;

   while(act->ant && cmp(act->info,d)>0)
    act = act->ant;

  comp = cmp(act->info,d);
  if(comp == 0)
    {
      tNodo *ant = act->ant,
            *sig = act->sig;

      if(ant)
        ant->sig = sig;

      if(sig)
      {
        sig->ant = ant;
        *pl = sig;
      }
      else
        {
          *pl = ant;
        }
      memcpy(act->info,d,cantBytes);
      free(act->info);
      free(act);
      return 1;
    }

    return 0;
}


int compararEntero(const void *a, const void *b)
{
  const int *n1 = (const int*)a;
  const int *n2 = (const int*)b;
  return *n1 - *n2;
}


FALTA ORDENAR LISTA QUE ESTA EN DISCORD
