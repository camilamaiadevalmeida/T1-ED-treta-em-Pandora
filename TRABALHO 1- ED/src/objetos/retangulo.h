#ifndef RETANGULO_H
#include "figuras.h"

/* Este módulo provê funções para criar e manipular um retângulo.

Dado isso, temos que no contexto do programa, um retângulo é uma forma geométrica que representa
algum edifício, instalação militar ou logística, etc. Além disso, como as outras formas geométricas
do programa o retângulo pode ser fotografado por um balão. 
Assim, um retângulo se caracteriza por possuir:
- um identificador único;
- uma âncora (canto inferior esquerdo do retângulo);
- uma dimensão (largura e altura);
- uma largura (w);
- uma altura (h);
- uma cor;
- uma cor de borda;
- uma coordenada x;
- uma coordenada y;
 */

//Função que seta a largura do retângulo
void setWRetangulo(Retangulo* retangulo, double w);

//Função que retorna a largura do retângulo
double getWRetangulo(Retangulo retangulo);

//Função que seta a altura do retângulo 
void setHRetangulo(Retangulo* retangulo, double h);

//Função que retorna a altura do retângulo
double getHRetangulo(Retangulo retangulo);





#endif