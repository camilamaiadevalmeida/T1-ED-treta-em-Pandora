#ifndef TEXTO_H
#include "figuras.h"

/* Este módulo provê funções para criar e manipular um texto.

Dado isso, temos que no contexto do programa, um texto é uma forma geométrica que representa
algum edifício, instalação militar ou logística, etc. Além disso, como as outras formas geométricas
do programa o texto pode ser fotografado por um balão. 
Assim, um texto se caracteriza por possuir:
- um conteúdo;
- um estilo;
*/


//Função que seta o conteúdo do texto
void setConteudoTexto(Texto* texto, char* conteudo);

//Função que retorna o conteúdo do texto
char* getConteudoTexto(Texto texto);

//Função que seta o estilo do texto
void setEstiloTexto(Texto* texto, char estilo);

//Função que retorna o estilo do texto
char getEstiloTexto(Texto texto);

//Função que seta a coordenada x2 do texto
void setX2Texto(Texto* texto, double x2);

//Função que retorna a coordenada x2 do texto
double getX2Texto(Texto texto);

//Função que seta a coordenada y2 do texto
void setY2Texto(Texto* texto, double y2);

//Função que retorna a coordenada y2 do texto
double getY2Texto(Texto texto);






























#endif