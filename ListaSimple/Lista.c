#include "Lista.h"




void crearLista(tLista *pl)
{
  *pl = NULL;
}


int ponerAlComienzoListaSimple(tLista *pl, const void *dato, unsigned cantBytes)
{
  tNodo *nue;
  if( (nue = (tNodo*)malloc(sizeof(tNodo))) == NULL || (nue->dato = malloc(cantBytes) )== NULL)
    {
      free(nue);
      return 0;
    }

  memcpy(nue->dato,dato,cantBytes);
  nue->tamDato = cantBytes;

  nue->sig = *pl;
  *pl = nue;
  return 1;
}




int ponerAlFinalListaSimple(tLista *pl, const void *dato, unsigned cantBytes)
{
  tNodo *nue;
    while(*pl)
    {
      pl = &(*pl)->sig;

    }

  if( (nue = (tNodo*)malloc(sizeof(tNodo))) == NULL || (nue->dato = malloc(cantBytes)) == NULL )
    {
      free(nue);
      return 0;
    }

  memcpy(nue->dato,dato,cantBytes);
  nue->tamDato = cantBytes;
  nue->sig = NULL;
  *pl = nue;
  return 1;
}


int listaLlena(const tLista *pl, unsigned cantBytes)
{
  tNodo *nue = (tNodo*)malloc(sizeof(tNodo));
  void *info = malloc(cantBytes);

  free(nue);
  free(info);
  return nue == NULL || info == NULL;
}


int listaVacia(const tLista *pl)
{
    return *pl == NULL;
}



int sacarPrimeroLista(tLista *pl, void *d, unsigned cantBytes)
{
  tNodo *elim = *pl;

  if(elim == NULL)
  {
    return 0;
  }

  *pl = elim->sig;
  memcpy(d,elim->dato, minimo(cantBytes,elim->tamDato));
  free(elim->dato);
  free(elim);
  return 1;
}


void vaciarLista(tLista *pl)
{

  while(*pl)
    {
       tNodo *elim = *pl;
      *pl = elim->sig;
      free(elim->dato);
      free(elim);
    }

}

int sacarDelFinalLista(tLista *pl, void *d, unsigned cantBytes)
{

  if(*pl == NULL)
    return 0;

  while((*pl)->sig)
    {
      pl = &(*pl)->sig;
    }
  memcpy(d,(*pl)->dato,minimo(cantBytes,(*pl)->tamDato));
  free((*pl)->dato);
  free(*pl);
  *pl = NULL;
  return 1;

}


int verUltimoLista(const tLista *pl, void *dato, unsigned cantBytes)
{
  if(*pl == NULL)
    return 0;

  while((*pl)->sig)
    pl = &(*pl)->sig;

  memcpy(dato,(*pl)->dato,minimo(cantBytes,(*pl)->tamDato));

  return 1;
}


int verPrimeroLista(const tLista *pl, void *dato, unsigned cantBytes)
{
  if(*pl == NULL)
    return 0;

  memcpy(dato, (*pl)->dato,minimo(cantBytes,(*pl)->tamDato));
  return 1;
}







//
//void crearLista(tLista *pl)
//{
//  *pl = NULL; /// ES EL TOPE DE LISTA(puntero) QUE APUNTE A NULL
//  /// TOPE LISTA ->NULL
//}
//
//
//int ponerEnLista(tLista *pl, const void *dato, unsigned tam)
//{
//  tNodo *nue = (tNodo*)malloc(sizeof(tNodo));
//
//  /// pregunto por si hay espacio para nue y para tamInfo de nue
//
//  if(!nue)
//    {
//      return 0;
//    }
//
//  nue->info = malloc(tam);
//
//  if(!nue->info)
//  {
//    free(nue);
//    return 0;
//  }
//  /// sino es lista llena entonces:
//  nue->tamInfo = tam; // asigno el tamaño del dato
//  memcpy(nue->info,dato,tam); /// copio el dato para nue->info
//
//  nue->sig = *pl;
//  *pl = nue;
//  /// memcpys de todo
//  return 1;
//}
//
//
//void ordenarSelLista(tLista *pl, int (*cmp)(const void*, const void *))
//{
//  if(!*pl)
//    return; /// no hay lista
//
//  while((*pl)->sig) //mientras haya lista
//    {
//      tNodo **men = buscar_menor_nodo_lista(pl,cmp);  /// ** men es lo mismo que tLista *pl asi que es un puntero a lista, osea (tLista *men)
//      if(pl != men) /// si son distintos significa que encontré el menor
//      {
//        intercambio_info_nodos(pl, men);
//        // reinsertar_nodo_menor(pl,men)
//      }
//      pl = &(*pl)->sig; /// me muevo a la siguiente sublista.
//    }
//}
//
//
//void reinsertar_nodo_menor(tLista *pl, tLista * men)
//{
//  tNodo *aux = *men;
//  *men = aux->sig;
//
//  aux->sig = *pl;
//  *pl = aux;
//}
//
//tNodo **buscarMenorNodoLista(const tLista *pl, int (*cmp)(const void *, const void*))
//{
//  const tLista *men = pl; ///Nodo*
//  if(!*pl)
//  {
//    return NULL;
//  }
//  pl = &(*pl)->sig; /// me paro en el siguiente nodo
//  while(*pl) /// mientras haya lista
//    {
//      if(cmp((*pl)->info, (*men)->info)<0) ///en men tengo el primero de la lista
//      {
//        men = pl;
//      }
//      pl = &(*pl)->sig;
//    }
//    return (tNodo **)men;
//}
//
//void intercambioInfoNodos(tLista *n1, tLista *n2)
//{
//  unsigned aux_tam;
//  void *aux = (*n1)->info; /// porque no se que dato es lo guardo en void, el contenido del nodo 1 lo guardo en el aux
//  (*n1)->info = (*n2)->info;
//  (*n2)->info = aux;
//
//
//  aux_tam = (*n1)->tamInfo; /// pueden ser 2 tipos de datos distintos, no tiene mucho sentido en una lista de mismos elementos pero puede pasar
//  (*n1)->tamInfo = (*n2)->tamInfo; /// que uno sea int y otro char o algo así
//  (*n2)->tamInfo = aux_tam;
//}
//
//
//
//int eliminarDeListaOrdDuplicados(Lista *pl, Cmp cmp,Actualizar actualizar) /// Elimina los duplicados y me quedo con el primero. Compara el "primer" nodo con el siguiente y si sigue encontrando ( en lista ordenada
//                                                                          /// los eleimina.
//{
//  tLista *pl2; /// lista auxiliar
//  tNodo *nae;
//  int cantElim = 0;
//
//  while(*pl)
//    {
//      pl2 = &(*pl)->sig; /// Me guardo el enlace, para no perder el puntero al tope de la lista , esto siempre pasa.
//
//      while(*pl2 && cmp((*pl)->elem,(*pl2)->elem) ==0)
//        {
//          actualizar((*pl)->elem,(*pl2)->elem); /// ni la profe sabe que hace
//          nae = *pl2;   ///1 aca hago el cambiazo legendario
//          *pl2 = nae->sig;///2
//          free(nae->info);
//          free(nae);
//          cantElim++;
//        }
//
//        pl = &(*pl)->sig;
//    }
//
//    return cantElim;
//}
