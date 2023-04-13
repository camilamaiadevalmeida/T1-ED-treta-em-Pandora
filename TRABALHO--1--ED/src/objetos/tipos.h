#ifndef TIPOS_H_
#define TIPOS_H_

#include "../arqs/main.h"

// Este módulo provê funções que definem tipos de informações que deverão ser cessadas em determinadas partes do programa.

// COMENTÁRIO DO JEAN: nada disso precisa existir por causa do jeito que você fez.
// o jeito que você lida com as formas é ter uma structzona só. o meu jeito é essa
// doideira de enum. além do mais aquela história de todos os campos serem string 
// vai de ralo enfiando esse enum no meio.

enum TipoForma
{
    CIRCULO,
    RETANGULO,
    TEXTO,
    LINHA
};
enum TipoVeiculo
{
    BALAO,
    CACA,
    NENHUM = -1
};
enum TipoForma getTipoForma(void *forma);
enum TipoVeiculo getTipoVeiculo(void *forma);

#endif