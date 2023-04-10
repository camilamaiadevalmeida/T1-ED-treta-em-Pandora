#include"figuras.h"
#include "circulo.h"
#include "Circulo.c"
#include "retangulo.h"
#include "Retangulo.c"
#include "linha.h"
#include "Linha.c"
#include "texto.h"
#include "Texto.c"

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>


// Path: src/objetos/Formas.c

// Definição das structs Retangulo, Circulo, Texto e Linha
/*struct Retangulo {
    int w;
    int h;
};
struct Circulo {
    int raio;
};
struct Texto {
    char* conteudo;
    double x2;
    double y2;
    char* estilo;
    double rotacao;
    void* balaoDados;
    void* cacaDados;
};
struct Linha {
    double x2;
    double y2;
};
*/

// Definição da struct Figura
struct Figura {
    int id;
    char tipo;
    char corb;
    char corp;
    double x;
    double y;

    union tipoFig {
        struct Retangulo retangulo;
        struct Circulo circulo;
        struct Texto texto;
        struct Linha linha;
    } tipoFigura;
};

struct Figura figura, *ptr;


// Função que cria uma nova figura com os parâmetros especificados
Figura criaFigura(char tipo, char id, double x, double y, double x2, double y2, int w, int h, double raio, char* corb, char* corp){
    //figura;
    figura.id = id;
    figura.tipo = tipo;
    figura.corb = corb;
    figura.corp = corp;
    figura.x = x;
    figura.y = y;
    switch(tipo){
        case 'r':
            figura.tipoFigura.retangulo.w = 0;
            figura.tipoFigura.retangulo.h = 0;
            break;
        case 'c':
            figura.tipoFigura.circulo.raio = 0;
            break;
        case 't':
            strcpy(figura.tipoFigura.texto.conteudo, " ");
            figura.tipoFigura.texto.x2 = 0;
            figura.tipoFigura.texto.y2 = 0;
            //figura.tipoFigura.texto.estilo = "";
            //figura.tipoFigura.texto.rotacao = 0;
            //figura.tipoFigura.texto.balaoDados = NULL;
            //figura.tipoFigura.texto.cacaDados = NULL;
            break;
        case 'l':
            figura.tipoFigura.linha.x2 = 0;
            figura.tipoFigura.linha.y2 = 0;
            break;
    }
    return 0;
}

//os parametros nao podem ter o mesmo nome do tipo de retorno kk
// que erro sem sentido jesuss????????????


//Função que cria uma figura


// Função que seta as informações de uma figura
void setFigura(Figura figura, char tipo, int id, double x, double y, char* corb, char* corp) {
   struct Figura* ptr = figura;
   ptr-> tipo = tipo;
   ptr-> id = id;
   ptr-> corb = corb;
   ptr-> corp = corp;
   ptr-> x = x;
   ptr-> y = y;
}

// Função que seta o tipo de uma figura
void setTipo(Figura figura, char tipo) {
    //struct Figura* ptr = figura;
    ((struct Figura*) figura)-> tipo = tipo;
}

// Função que retorna o tipo de uma figura
char getTipo(Figura figura) {
    struct Figura* ptr = figura;
    return ptr-> tipo;
}

// Função que seta o id de uma figura
void setId(Figura figura, int id) {
    //struct Figura* ptr = figura;
    ((struct Figura*) figura)-> id = id;
}

// Função que retorna o id de uma figura
int getId(Figura figura) {
    struct Figura* ptr = figura;
    return ptr-> id;
}

// Função que seta a cor de borda de uma figura
void setCorb(Figura figura, char* corb) {
    //struct Figura* ptr = figura;
    ((struct Figura*) figura)-> corb = corb;
    
}

// Função que retorna a cor de borda de uma figura
char getCorb(Figura figura) {
    struct Figura* ptr = figura;
    return ptr-> corb;
}

// Função que seta a cor de preenchimento de uma figura
void setCorp(Figura figura, char* corp) {
    //struct Figura* ptr = figura;
    ((struct Figura*) figura)-> corp = corp;
    
}

// Função que retorna a cor de preenchimento de uma figura
char getCorp(Figura figura) {
    struct Figura* ptr = figura;
    return ptr-> corp;
}

// Função que seta a coordenada x de uma figura
void setX(Figura figura, double x) {
    //struct Figura* ptr = figura;
    ((struct Figura*) figura)-> x = x;
    
}

// Função que retorna a coordenada x de uma figura
double getX(Figura figura) {
    struct Figura* ptr = figura;
    return ptr-> x;
}

// Função que seta a coordenada y de uma figura
void setY(Figura figura, double y) {
    //struct Figura* ptr = figura;
    ((struct Figura*) figura)-> y = y;
}

// Função que retorna a coordenada y de uma figura
double getY(Figura figura) {
    struct Figura* ptr = figura;
    return ptr-> y;
}


//funcao de rodar figura e etc































