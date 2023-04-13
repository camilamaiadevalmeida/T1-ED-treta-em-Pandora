#ifndef FOTO_H
#define FOTO_H

#include "headers.h"
#include "../arqs/main.h"

// Este módulo provê funções para manipular Fotos

// DEsscrever coisas de fotos piriripororo
// Explicar offset................

// COMENTÁRIO DO JEAN: as formas das fotos vão ter duas posições: a de verdade e a relativa à foto
// você que escolhe se as fotos vão guardar as formas com a posição de verdade ou ela já calculada pra fazer o svg de foto
// eu fiz do pior jeito que dava, que era guardar elas com a posição já calculada. daí o offset era pra "desrelativar" elas
// pra fazer as putaria de clonar
// esse é um dos motivos que eu peço pra não copiar as coisa. 60% é pura gambiarra
typedef void *Foto;

Foto tiraFoto(Lista lista, FILE *svg, Texto balao, FILE *txt, int i);

void printFoto(Foto f, FILE *svg, Texto balao, double *dx, double *pontuacao);

// True se a foto foi "enviada" corretamente
bool sentFoto(Foto f);
// COMENTÁRIO DO JEAN: também é desnecessário. ele falou que quando envia a foto ela é deletada.

Lista getFotoElem(Foto f);

double get_X_offsetFoto(Foto f);

double get_Y_offsetFoto(Foto f);

void killFoto(Foto f);

#endif