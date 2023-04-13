#ifndef TXT_H
#define TXT_H

#include "headers.h"
#include "../arqs/main.h"

//Este módulo provê funções para gerar o arquivo QRY

void reportaAtr(void* forma, FILE *txt);

void reportaAtrFold(Item item, Clausura c);

void reportaAtrElem(void* elemento, FILE *txt);

void reportaAtrElemFold(Item item, Clausura c);















#endif