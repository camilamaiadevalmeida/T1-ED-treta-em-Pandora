#ifndef FIGURAS_H
#define FIGURAS_H

/*A ideia deste módulo é promover a reutilização de código para manipulação das FIGURAS. Isso porque existem
funções em comum entre as FIGURAS e facilita muito não precisar repetir funções para cada forma.

Uma forma consiste em qualquer representação gráfica dentro do plano cartesiano. Assim, uma forma pode ser um
retângulo, um círculo, um texto ou uma linha. Todos esses tipos de forma dividem características em comum, sendo
estas: tipo, identificador, cor de borda, cor de preenchimento, coordenada x e coordenada y. 
Para além destas informações, cada forma possui também suas características particulares. Assim, um retângulo possui
também as informações largura (w) e altura (h), enquanto um círculo possui o raio (r). Da mesma maneira, um texto
possui também informações d eestilo de formatação e uma segunda âncora (x2 e y2). Por fim, uma linha possui também
uma segunda âncora (x2 e y2).

Assim sendo, para saber o tipo de uma figura, isto é, se é um retângulo, um círculo, um texto ou uma linha, basta
acessar o campo tipo da estrutura Forma. Para acessar as informações particulares de cada forma, basta acessar os


*/

//Função que define o tipo de forma
//typedef enum {CIRCULO, RETANGULO, TEXTO, LINHA} Figura;

typedef void *Figura;

typedef void *Circulo;

typedef void *Retangulo;

typedef void *Texto;

typedef void *Linha;

typedef void *Tipo;


//Função que cria uma figura
Figura criaFigura(char tipo, char id, double x, double y, double x2, double y2, int w, int h, double raio, char* corb, char* corp);

//Função que seta uma figura
void setFigura(Figura figura, char tipo, int id, double x, double y, char* corb, char* corp);

//Função que retorna o tipo de uma figura
char getTipo(Figura figura);

void setTipo(Figura figura, char tipo);

//Função que seta o id de uma figura
void setId(Figura figura, int id);

//Função que retorna o id de uma figura
int getId(Figura figura);

//Função que seta a cor de borda de uma figura
void setCorb(Figura figura, char* corb);

//Função que retorna a cor de borda de uma figura
char getCorb(Figura figura);

//Função que seta a cor de preenchimento de uma figura
void setCorp(Figura figura, char* corp);

//Função que retorna a cor de preenchimento de uma figura
char getCorp(Figura figura);

//Função que seta a coordenada x de uma figura
void setX(Figura figura, double x);

//Função que retorna a coordenada x de uma figura
double getX(Figura figura);

//Função que seta a coordenada y de uma figura
void setY(Figura figura, double y);

//Função que retorna a coordenada y de uma figura
double getY(Figura figura);

//movimentos com um switch né


#endif