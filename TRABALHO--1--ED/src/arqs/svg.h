#ifndef SVG_H
#define SVG_H
#include "libsgerais.h"
#include "../ed/lista.h"
#include "../objetos/formas.h"

/*
Este módulo contém funções que fazem a inicialização, leitura e finalização de um arquivo SVG.

Tem-se que um arquivo SVG (Scalable Vector Graphics) é um formato de arquivo de imagem que usa
texto para descrever gráficos vetoriais. Neste caso, o arquivo SVG é um arquivo de texto que contém
instruções para desenhar formas geométricas, como retângulos, círculos, linhas e texto.
*/

//Inicia um arquivo SVG//
void svg_init(FILE *svg);

//Finaliza um arquivo SVG//
void svg_finalize(FILE *svg);

//Fecha o arquivo SVG//
void svg_close(FILE *file);

void desenhaItemSVG(Item item, void *closure, const char *filename);

//Escreve no arquivo svg (clausura) o item atual//
void escreveSvg(Item item, Clausura c);

//Definição de clausura usada na função ApplyClosure escreveSvg//
typedef void *clausuraSvg;

//Cria uma clausura que guarda o arquivo svg//
clausuraSvg criaClausuraSvg(FILE *svg);

//Libera a memória alocada para a clausura//
void liberaClausuraSvg(Clausura c);

#endif