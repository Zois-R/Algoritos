#include <stdio.h>
#include <stdlib.h>
#include "ListaDoble.h"
int main()
{
    int n1 = 2, n2 = 4, n3 = 99,n4 =0;
    tListaD newListD;
    crearListaD(&newListD);
    insertarAlFinalListaDoble(&newListD,&n4,sizeof(int));
    insertarAlFinalListaDoble(&newListD,&n1,sizeof(int));
    insertarAlFinalListaDoble(&newListD,&n2,sizeof(int));
    insertarAlFinalListaDoble(&newListD,&n3,sizeof(int));
//    mostrarDerAIzqListaD(&newListD,mostrarEntero);
//    printf("\n");
//    mostrarIzqADerListaD(&newListD,mostrarEntero);
    eliminarPorClaveListaDoble(&newListD,&n2,sizeof(int),compararEntero);
     mostrarDerAIzqListaD(&newListD,mostrarEntero);
    return 0;
}
