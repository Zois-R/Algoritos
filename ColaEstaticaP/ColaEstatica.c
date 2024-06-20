#include "ColaEstatica.h"


void crear_cola(t_cola* pc)
{
    pc->tam_disponible=TAM_COLA;
    pc->pri = pc->ult = 0;
}
  int poner_en_cola(t_cola* pc,void* pd, size_t tamElem)
  {
      int ini,fin;
      ///INI es el principio del dato que tiene que ir al final del vector/ FIN es el final del dato que tiene que ir al principio del vector
      if(pc->tam_disponible < (sizeof(size_t)+tamElem))
         return 0; ///COLA LLENA
      ini = MINIMO(sizeof(tamElem),TAM_COLA - pc->ult);///TAM_COLA - pc->ult Es la cantidad de bytes que nos quedan al final del vector
      if(ini)
          memcpy(pc->vec + pc->ult,&tamElem,ini);///pc->vec + pc->ult Hace que le vector se desplace 70 bytes, porque es un vector de chars

        if(fin = sizeof(size_t) - ini)///Evalua si FIN != 0
            memcpy(pc->vec,(char*)&tamElem+ini,fin);
          ///pc->vec tiene la direccion de inicio del vector, nunca la modificamos
          ///(char*)&tamElem+ini Si no lo casteamos suma ini veces size_t Bytes

      pc->ult = fin ? fin : pc->ult + ini; /// Se suma FIN bytes desde el 0, no es una direccion de memoria; Si hay FIN devuelve FIN, si no, suma ini

        //// DATO
      if(ini=MINIMO(tamElem,TAM_COLA - pc->ult))
          memcpy(pc->vec+pc->ult,pd,ini);
      if(fin= tamElem-ini) /// si esto es distinto de cero
          memcpy(pc->vec,(char*)pd+ini,fin);


      pc->ult = fin ? fin: pc->ult+tamElem;

      pc->tam_disponible-=tamElem+sizeof(tamElem);


      return 1;
  }
int sacar_de_cola(t_cola* pc, void* pd,size_t tamElem)
{
    int ini, fin;
    size_t tdc;///Tamaño del dato en la cola
    if(pc->tam_disponible == TAM_COLA)
        return 0; ///Cola Vacia


    if(ini = MINIMO(sizeof(size_t),TAM_COLA - pc->pri)) /// si da menos de 4 está partida
        memcpy(&tdc,pc->vec + pc->pri,ini);

    if(fin = sizeof(size_t) - ini)
        memcpy(((char*)&tdc)+ini,pc->vec,fin);

    pc->pri = fin ? fin : pc->pri + sizeof(size_t);


    if(ini = MINIMO(tdc,TAM_COLA - pc->pri)) /// si da menos de 4 está partida
        memcpy(pd,pc->vec + pc->pri,MINIMO(tamElem,ini)); ///Por mas que el dato este partido por el medio, el tamElem que nos da el usuario puede ser menor que ini

    if((fin = tdc - ini) && (tamElem-ini) > 0 ) /// tamElem-ini Puede significar que el usuario no tenga el espacio necesario para copiar el dato
        memcpy(((char*)&pd)+ini,pc->vec,MINIMO(fin,tamElem-ini);///tamElem-ini es lo que ya copiamos del dato

    pc->pri = fin ? fin : pc->pri + tdc;



    pc->tam_disponible += sizeof(size_t) + tdc;


    return 1;

}



int cola_vacia(t_cola* pc)
{
    return pc->tam_disponible == TAM_COLA;
}

int cola_llena(t_cola* pc,void* pd,size_t tamElem)
{
    return pc->tam_disponible < (sizeof(size_t)+tamElem);
}

