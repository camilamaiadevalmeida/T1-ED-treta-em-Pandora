#ifndef SVG_H
#define SVG_H
#include "main.h"
#include "../ed/lista.h"
#include "../objetos/formas.h"


/*
Este módulo contém funções que fazem a inicialização, leitura e finalização de um arquivo SVG.

Tem-se que um arquivo SVG (Scalable Vector Graphics) é um formato de arquivo de imagem que usa 
texto para descrever gráficos vetoriais. Neste caso, o arquivo SVG é um arquivo de texto que contém
instruções para desenhar formas geométricas, como retângulos, círculos, linhas e texto.
*/

FILE* cria_path_SVG_geo (void* parametros);
//void desenhaNoSVG (Lista* li, FILE* file);
void desenhaItemFoldSVG (Lista lst, ApplyClosure f, Clausura c);
#endif