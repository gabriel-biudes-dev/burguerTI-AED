#include <stdio.h>
#include <stdlib.h>
#include "hamburguer.h"

ListaH* insertH(ListaH* hlist, Hamburguer h){//insert hamburger
    ListaH* aux = (ListaH*) malloc(sizeof(ListaH));
    aux->h = h;
    aux->prox = hlist;
    return aux;
}
