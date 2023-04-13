#ifndef _FILA_H
#define _FILA_H

#include "../arqs/main.h"
#include "lista.h"
/*
Este módulo provê funções para manipular filas circulares estáticas.

Uma fila circular é uma estrutura de dados que permite inserir e
remover elementos de uma lista de forma eficiente. A inserção e
remoção são feitas no mesmo extremo da lista, o que permite que
elementos sejam inseridos e removidos em tempo constante. A
estrutura de dados é circular, o que significa que o último elemento
aponta para o primeiro, e o primeiro aponta para o último. 
A estrutura de dados é estática, o que significa que o tamanho da
lista é definido no momento da criação da lista.

No contexto do programa, uma fila é o método de armazenamento das
fotos que um balão pode tirar. Assim, tem-se que podem exisitr até 10
filas de fotos para cada balão e que cada uma dessas filas pode ter até
15 elementos(fotos).
*/

typedef void *Fila;
Fila criaFila(int size);
bool insereFila(Fila fila, Item elemento);
bool removeElemFila(Fila fila);

Item getInicioFila(Fila fila);
Item getFimFila(Fila fila);
int getMaxSizeFila(Fila fila);
int getQtdFila(Fila fila);

Item setInicioFila(Fila fila);
Item setFimFila(Fila fila);
int setSizeFila(Fila fila);
int setQtdFila(Fila fila);

bool isVaziaFila(Fila fila);
bool isCheiaFila(Fila fila);
void killFila(Fila fila);
























#endif