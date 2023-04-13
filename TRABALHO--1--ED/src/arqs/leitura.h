#ifndef LEITURA_H_
#define LEITURA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"
#include "../ed/lista.h"
#include "../ed/fila.h"

/*Este módulo provê funções para a leitura de arquivos.
 + infos de arquivos !!!
*/

// Função que lê uma linha de um arquivo e separa as informações da linha em tokens
void lerLinha(FILE *arq, char *palavras[], int *n);

// Função que lê o arquivo geo e armazena os elementos na lista
void lerGeo(FILE *geo, Lista *lista);

// Função que lê o arquivo QRY e chama as funções de remoção e alteração de elementos na lista
void lerQry(FILE *qry, FILE *svg, FILE *txt, Lista *lista, char *nomeSvg);

#endif
