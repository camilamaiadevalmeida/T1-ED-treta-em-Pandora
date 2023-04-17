#ifndef BOMBA_H
#define BOMBA_H

#include "../ed/lista.h"
#include "../objetos/formas.h"


/*
Este módulo provê funções para 'lidar' com as bombas, objetos lançados pelos caças.

Todas as funções, bem como a implementação seguem a descrição a seguir:

Um caça tenta derrubar um balão disparando uma bomba de detonação por afastamento.
Existem bombas de diferentes capacidades: A, B e C. 
Antes do lançamento o piloto define a capacidade da bomba e a distância que a bomba d
eve percorrer antes de explodir...
Quando a bomba atinge tal distância, ela detona-se e atinge qualquer elemento que estiver 
no raio de 10 unidades (para bombas do tipo A), 15 unidades (tipo B) ou 30 unidades (tipo C) 
do ponto da explosão, destruindo-o.

Além disso, tem-se que o objeto bomba também está "envolvido" com os comandos 'd' e 'c?' do arquivo QRY.
*/

// Enum com o objetivo de enumerar os três tipos existentes de bombas. 
enum bombaTipo
{
    A = 10,
    B = 15,
    C = 30,
};

// Calcula a posição da bomba
void bombaPosic(double xcaca, double ycaca, double rotacao, double distancia,
                  double *xbomba, double *ybomba);

// Explode a bomba
// dx é a distância que os elementos clonados devem ser transladados
void explodeBomba(Lista db, double xbomba, double ybomba, enum bombaTipo, double dx, void* formato, int j, FILE *txt, FILE *svg);
//TExto caca é pq primeiro acessa texto pra dps acessar caca ne...
#endif