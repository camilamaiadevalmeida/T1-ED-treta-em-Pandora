#ifndef _SVG_H
#define _SVG_H
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
//#include <graphics.h>

/*
Este módulo contém funções que fazem a inicialização, leitura e finalização de um arquivo SVG.

Tem-se que um arquivo SVG (Scalable Vector Graphics) é um formato de arquivo de imagem que usa 
texto para descrever gráficos vetoriais. Neste caso, o arquivo SVG é um arquivo de texto que contém
instruções para desenhar formas geométricas, como retângulos, círculos, linhas e texto.
*/

//Função que inicializa o arquivo SVG
void initSvg(FILE *svg, int w, int h);

//Função que finaliza o arquivo SVG
void endSvg(FILE *svg);

//Função que escreve no arquivo SVG
//void writeSvg(FILE *svg, char *str);

//Função que escreve um retângulo no arquivo SVG
void writeRectSvg(FILE *svg, char *id, int x, int y, int w, int h, char *fill, char *stroke);

//Função que escreve um círculo no arquivo SVG
void writeCircleSvg(FILE *svg, char *id, int cx, int cy, int r, char *fill, char *stroke);

//Função que escreve um texto no arquivo SVG
void writeTextSvg(FILE *svg, char *id, int x, int y, char *fill, char *stroke, char *style);

//Função que escreve uma linha no arquivo SVG
void writeLineSvg(FILE *svg, char *id, int x1, int y1, int x2, int y2, char *fill, char *stroke);































#endif