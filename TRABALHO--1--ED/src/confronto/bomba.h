#ifndef _BOMBA_H
#define _BOMBA_H

#include "../ed/lista.h"
#include "headers.h"
#include "../arqs/main.h"
#include "txt.h"

// Este módulo provê funções para a manipulação de Bombas


/*As bombas são disparadas por caças e funcionam através de detonação por afastamento.
Existem bombas de diferentes capacidades: A, B e C. Antes do lançamento o piloto define a
capacidade da bomba e a distância que a bomba deve percorrer antes de explodir. Quando a bomba
atinge tal distância, ela detona-se e atinge qualquer elemento que estiver no raio de 10 unidades
(para bombas do tipo A), 15 unidades (tipo B) ou 30 unidades (tipo C) do ponto da explosão,
destruindo-o.
*/

// Tipos de bombas com seus respectivos raios
enum tipoBomba
{
    A = 10,
    B = 15,
    C = 30,
};
// Função que calcula a posição da bomba
void posicBomba(double xcaca, double ycaca, double rotacao, double distancia,
                  double *xbomba, double *ybomba);
// Função que explode a bomba
void explodeBomba(Lista db, double xbomba, double ybomba, enum tipoBomba tipo, double dx, Texto caca, int j, FILE *txt, FILE *svg);

#endif
