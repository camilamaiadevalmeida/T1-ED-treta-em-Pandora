#ifndef GEO_H
#define GEO_H

#include "libsgerais.h"
#include "../ed/lista.h"
#include "../ed/fila.h"
#include "../objetos/formas.h"

//Este módulo provê ferramentas para manipular um arquivo.geo
//Para isto, utiliza-se a função dealWithGeo, que lê as linhas do arquivo, tokeniza e armazena na Lista
void dealWithGeo(FILE *geo, Lista lst);

#endif