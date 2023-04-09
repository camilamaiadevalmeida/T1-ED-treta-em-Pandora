#ifndef LINHA_H
#include "figuras.h"

/* Este módulo provê funções para criar e manipular uma linha.

Dado isso, temos que no contexto do programa, uma linha é uma forma geométrica que representa
algum edifício, instalação militar ou logística, etc. Além disso, como as outras formas geométricas
do programa, a linha pode ser fotografada por um balão.
Assim, uma linha se caracteriza por possuir:
- um identificador único;
- duas âncoras (extremidades da linha);
- uma dimensão (?);
- uma cor;
- uma cor de borda;
- uma coordenada x;
- uma coordenada x1;
- uma coordenada y;
- uma coordenada y1;
 */
 
 //Função que seta o x2 da linha;
void setLinhaX2(Linha linha, double x2);

//Função que seta o y2 da linha;
void setLinhaY2(Linha linha, double y2);

//Função que retorna o x2 da linha;
double getLinhaX2(Linha linha);

//Função que retorna o y2 da linha;
double getLinhaY2(Linha linha);

#endif