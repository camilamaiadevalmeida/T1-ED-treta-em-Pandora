#ifndef TEXTO_H_
#define TEXTO_H_

#include "tipos.h"
#include "formas.h"
#include "../arqs/main.h"
#include "../ed/lista.h"
#include "../ed/fila.h"

/*Como já tem todas as funções gerais de manipulação de formas e o void* formatoambém
está bem inserido nessa brincadeira, aqui vai ser o módulo que define os casos
especiais de texto (v_0_v e |_T_|). Esses casos bemm especiais definem a base
para as funções mais complicadas de manipulação dos confrontos entre as bombas
e as fotos.
*/

//Penso em meter uma Closure pra pegar info de formas e implementar num texto.c ou só implementar no formas.c mesmo

/** Define os parâmetros de foco de um balão*/
bool setBalaoParametros(void* formato, double r, double p, double h);

/** Retorna o raio de foco de um balão*/
double getBalaoR(void* formato);

/** Retorna a profundidade de um balão*/
double getBalaoP(void* formato);

/** Retorna o alcance da nitidez de um balão*/
double getBalaoH(void* formato);

/** Retorna a fila i de um balão*/
Fila getBalaoFilaI(void* formato, int i);



/** Atualiza a lista de alvos acertados de um caça com um novo elemento. */
bool cacaAcertou(void* formato, int i);

/** Aumenta a quantidade de disparos de um caça em 1*/
bool cacaDisparou(void* formato);

/** Retorna a quantidade de disparos e a lista de acertos de um caça*/
bool getCacaInfo(void* formato, int *disparos, Lista *acertos);




#endif