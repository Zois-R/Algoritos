#include "PilaEstatica.h"

void crearPila(tPila *p)
{
  p->tope = TAM_PILA;
}

int pilaLlena(const tPila *p, unsigned cantBytes)
{
  /**
  Ejemplo:
  [1][2][3][5][9]
               ^
               tope
  si tope < dato + lo que pesa el dato
  quiere decir que ya no puedo ingresar un elemento con su peso
  */
  return p->tope < cantBytes + sizeof(unsigned); /// porque unsigned?
}



int pilaVacia(const tPila *p)
{
  return p->tope == TAM_PILA;
}

void vaciarPila(tPila *p)
{
  p->tope = TAM_PILA;
}


int ponerEnPila(tPila *p, const void *dato, unsigned cantBytes)
{
  if(p->tope < cantBytes +sizeof(unsigned)) /// condicion de pila llena
    return 0;

  /// primero le resto el dato y lo copio
  p->tope -= cantBytes;
  memcpy(p->pila+p->tope,dato,sizeof(unsigned));
  /// despues le resto lo que pesa o el minimo peso posible y lo copio
  p->tope -= sizeof(unsigned);
  memcpy(p->pila + p->tope, &cantBytes, sizeof(unsigned));

  return 1;
}



int verTope(const tPila *p,void *dato, unsigned cantBytes)
{
  unsigned tamInfo; /// PARA QUE ESTE AUX?
  /// pila vacia?
  if(p->tope == TAM_PILA)
    return 0;

  /**
  El propósito de tamInfo es almacenar temporalmente el tamaño de los datos
   en la cima de la pila, y el propósito del primer memcpy es copiar este tamaño de la pila a tamInfo.
    Esto se hace para garantizar que la función copie solo la
     cantidad correcta de datos en el segundo memcpy, evitando así leer o escribir fuera
      de los límites de la memoria asignada a la pila.
  */
  memcpy(&tamInfo,p->pila + p->tope, sizeof(unsigned));
  memcpy(dato, p->pila + p->tope + sizeof(unsigned), minimo(cantBytes,tamInfo));
  return 1;

}


int sacarDePila(tPila *p, void *dato ,unsigned cantBytes)
{
  unsigned tamInfo;

  /// La pila está vacia?
  if(p->tope >= TAM_PILA)
    return 0;

  /// Copio en la variable creada tamInfo el tam del elemento que voy a sacar
  memcpy(&tamInfo,p->pila + p->tope, sizeof(unsigned));
  p->tope += sizeof(unsigned);
  /// Le saco el tamDato
  ///Copio en d, el dato que está en pila y que tiene la cant de Bytes que saca minimo
  /// Para que estaba minimo?

  memcpy(dato,p->pila + p->tope,minimo(cantBytes,tamInfo));
  p->tope += tamInfo;
  /// Le saco el dato
  return 1;

}
