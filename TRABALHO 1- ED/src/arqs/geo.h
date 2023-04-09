#define _GEO_H
#include<stdio.h>
#include<stdlib.h>
#include"../ed/lista.h"
#ifndef _GEO_H

/* Este arquivo provê funções para a criação de arquivos .geo.
Ou seja, arquivos de entrada que contém os comandos que especificam 
os dados que serão manipulados pelo programa.

O objetivo deste programa é ler um arquivo .geo e 
dar uma saída em arquivo .svg.

O arquivo .geo fica (replicado) da seguinte maneira (exemplo da Descrição Geral):

|c 1 50.00 50.0 30.00 grey magenta     |
|r 6 121.0 46.0 100.0 30.0 cyan yellow |
|c 2 120.0 45.0 15.0 grey magenta      |
|r 4 10.0 150.0 90.0 40.0 cyan yellow  |
|c 5 230.0 180.0 13.0 grey magenta     |

Onde:
    c = circulo
    r = retangulo
    1, 2, 3, 4, 5 = id
    50.00, 50.0, 30.00 = x, y, r
    grey, magenta = cor de preenchimento, cor de borda
    121.0, 46.0, 100.0, 30.0 = x, y, w, h
    cyan, yellow = cor de preenchimento, cor de borda

O arquivo .geo é lido e as informações são armazenadas em uma lista duplamente encadeada.
A lista encadeada é percorrida e as informações são escritas em um arquivo .svg.
*/

/* 
    Função que lê o arquivo .geo e armazena as informações em uma lista duplamente encadeada.
*/
void lerGeo(FILE *geo, Lista *lista);


/* 
    Função que escreve as informações do arquivo .geo em um arquivo .svg.
    Parâmetros:
        - char *nomeArquivo: nome do arquivo .svg
        - Lista *lista: lista duplamente encadeada que armazenará as informações do arquivo .geo
    Retorno:
        - void
*/
//void escreverSvg(char *nomeArquivo, Lista *lista);

#endif
