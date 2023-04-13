#ifndef FOTO_H
#define FOTO_H

#include "headers.h"
#include "../arqs/main.h"

// Este módulo provê funções para manipular Fotos

// DEsscrever coisas de fotos piriripororo
// Explicar offset................

typedef void *Foto;

Foto tiraFoto(Lista lista, FILE *svg, Texto balao, FILE *txt, int i);

void printFoto(Foto f, FILE *svg, Texto balao, double *dx, double *pontuacao);

// True se a foto foi "enviada" corretamente
bool sentFoto(Foto f);

Lista getFotoElem(Foto f);

double get_X_offsetFoto(Foto f);

double get_Y_offsetFoto(Foto f);

void killFoto(Foto f);

#endif