#include "texto.h"
#include "figuras.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Texto {
    char conteudo[50];
    double x2;
    double y2;
    //char* estilo;
    //double rotacao;
    //void* balaoDados;
    //void* cacaDados;
};

//struct Texto *texto;

void setConteudoTexto(Texto* texto, char *conteudo){
    strncpy(((struct Texto*)texto)->conteudo, conteudo, 50);
}

char* getConteudoTexto(Texto texto){
    struct Texto* ptr = texto;
    return ptr -> conteudo;
}

void setX2Texto(Texto* texto, double x2){
    ((struct Texto*) texto)-> x2 = x2;
}

double getX2Texto(Texto texto){
    struct Texto* ptr = texto;
    return ptr-> x2;
}

void setY2Texto(Texto* texto, double y2){
    ((struct Texto*) texto)-> y2 = y2;
}

double getY2Texto(Texto texto){
    struct Texto* ptr = texto;
    return ptr-> y2;
}
