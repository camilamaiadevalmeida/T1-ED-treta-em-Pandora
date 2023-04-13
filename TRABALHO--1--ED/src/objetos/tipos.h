#ifndef TIPOS_H_
#define TIPOS_H_

#include "../arqs/main.h"

// Este módulo provê funções que definem tipos de informações que deverão ser cessadas em determinadas partes do programa.

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