#include "fila.h"
#include<stdio.h>
#include<stdlib.h>

//Implementação das funções da Fila Circular Estática

struct fila{
    int size;
    int quantidade;
    int inicio;
    int fim;
    Item *elementos;
};

Fila criaFila(int size){
    struct fila *f = malloc(sizeof(Fila));
    f->size = size;
    f->inicio = 0;
    f->fim = 0;
    f->elementos = malloc(size * sizeof(Item));
    return f;
}

bool insereFila(Fila fila, Item elemento) {
    struct fila *f = (struct fila *) fila;
    if (isCheiaFila(f)) {
        return false;
    }
    f->elementos[f->fim] = elemento;
    f->fim = (f->fim + 1) % f->size;
    f->quantidade++;
    return true;
}

bool removeElemFila(Fila fila) {
    struct fila *f = (struct fila *) fila;
    if (isVaziaFila(f)) {
        return false;
    }
    f->inicio = (f->inicio + 1) % f->size;
    f->quantidade--;
    return true;
}

Item getInicioFila(Fila fila) {
    struct fila *f = (struct fila *) fila;
    if (isVaziaFila(f)) {
        return NULL;
    }
    return f->elementos[f->inicio];
}

Item getFimFila(Fila fila) {
    struct fila *f = (struct fila *) fila;
    if (isVaziaFila(f)) {
        return NULL;
    }
    return f->elementos[f->fim];
}

int getSizeFila(Fila fila) {
    struct fila *f = (struct fila *) fila;
    return f->size;
}

int getQtdFila(Fila fila) {
    struct fila *f = (struct fila *) fila;
    return f->quantidade;
}

bool isVaziaFila(Fila fila) {
    struct fila *f = (struct fila *) fila;
    return f->quantidade == 0;
}

bool isCheiaFila(Fila fila) {
    struct fila *f = (struct fila *) fila;
    return f->quantidade == f->size;
}

void killFila(Fila fila) {
    struct fila *f = (struct fila *) fila;
    free(f->elementos);
    free(f);
}

