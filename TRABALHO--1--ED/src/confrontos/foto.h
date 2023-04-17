#ifndef FOTOS_H
#define FOTOS_H

#include "objetos/formas.h"
#include <stdio.h>
#include <stdlib.h>


typedef void* Foto;

Foto takePic(Lista lista, FILE *svg, void* formato /*balao*/, FILE *txt, int i);
//meter balao no meio depois

void printPic(Foto f, FILE *svg, void* formato /*balao*/, double *dx, double *pontuacao);
//meter balao no meio depois

bool sentPic(Foto f);

Lista get_elementosF(Foto f);

double get_XOffsetF(Foto f);

double get_YOffsetF(Foto f);

void fotoOff(Foto f);


typedef void *retClos;

retClos criaretClos(double x, double y, double w, double h);

void liberaretClos(retClos c);

bool checkInRect(Item item, Clausura c);

typedef void *circClos;

circClos criacircClos(double x, double y, double r);

void liberacircClos(circClos c);

bool checkInCircle(Item item, Clausura c);

#endif