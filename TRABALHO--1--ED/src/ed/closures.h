#ifndef CLOSURE_H
#define CLOSURE_H

#include "lista.h"
#include "../arqs/main.h"
#include "../objetos/formas.h"
#include "../objetos/texto.h"

// Este módulo provê funções que operam como Closure no programa
//(mesmo C não sendo uma linguagem que dá suporte a isto).

/* Closure é um conceito em programação que se refere à habilidade de uma função
de referenciar variáveis de uma função externa que já foi encerrada.
Em outras palavras, um closure é uma função que pode "lembrar" do ambiente
em que ela foi criada, mesmo quando é executada em um contexto diferente.
*/
c
    // Aquela ideia de acessar a struct "sem roupa" no escuro,
    // mas confiar que está acessando mesmo não vendo diretamente.

    // Closure é sempre um ponteiro para void, ou seja, um ponteiro genérico.

    // Closures para lidar com o SVG:
    typedef void *ClosureSvg;
ClosureSvg criaClosureSvg(FILE *svg);
void escreveSvg(Item item, Clausura c);
void freeClosureSvg(Clausura c);

// Closures para lidar com o Id do Item:
typedef void *ClosureId;
ClosureId criaClosureId(int id);
void findId(Item item, Clausura c);
Item getClosureItem(Clausura c);
void freeClosureId(Clausura c);

// Closures pra lidar com TXT:
typedef void *ClosureTxt;
ClosureTxt criaClosureTxt(FILE *txt);
void escreveTxt(Item item, Clausura c);
void freeClosureTxt(Clausura c);

// Closures pra lidar com a pontuação das fotos:

typedef void *ClosurePontuacao;
ClosurePontuacao criaClosurePontuacao(double pontuacao);
double getClosurePontuacao(Clausura c);
void calculaPontuacao(Item item, Clausura c);
void freeClosurePontuacao(Clausura c);

// Closures para manipular o maior X encontrado entre as formas da lista:

typedef void *ClosureMaiorX;
ClosureMaiorX criaClosureMaiorX();
double getClosureMaiorX(Clausura c);
void findMaiorX(Item item, Clausura c);
void freeClosureMaiorX(Clausura c);

// Closures para lidar com o deslocamento do item para a direita (útil para encaixar no svg):

typedef void *ClosureDeslocaDireita;
ClosureDeslocaDireita criaClosureDeslocaDireita(double deslocamento);
void deslocaDireita(Item item, Clausura c);
void freeClosureDeslocaDireita(Clausura c);

// Closures para lidar com os parâmetros de foto:

typedef void *ClosureFoto;
ClosureFoto criaClosureFoto(double xbalao, double ybalao, double r, double p, double h);
void moveElementosFoto(Item item, Clausura c);
void freeClosureFoto(Clausura c);

#endif