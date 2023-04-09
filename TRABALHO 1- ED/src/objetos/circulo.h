#ifndef CIRCULO_H
#include "figuras.h"

/* Este módulo provê funções para criar e manipular um círculo.

Dado isso, temos que no contexto do programa, um círculo é uma forma geométrica que representa
algum edifício, instalação militar ou logística, etc. Além disso, como as outras formas geométricas
do programa, o círculo pode ser fotografado por um balão.
Assim, um círculo se caracteriza por possuir:
- um identificador único;
- uma âncora (centro do círculo);
- uma dimensão (raio do círculo);
- uma cor;
- uma cor de borda;
- uma coordenada x;
- uma coordenada y;
 */

//Função que seta o raio do circulo

void setRaioCirculo(Circulo* circulo, double raio);

//Função que retorna o raio do circulo
double getRaioCirculo(Circulo circulo);




#endif