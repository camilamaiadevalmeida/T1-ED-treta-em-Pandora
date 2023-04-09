#include "figuras.h"

#include<stdio.h>
#include<stdlib.h>

struct Linha {
    double x2;
    double y2;
};

//Função que seta o x2 da linha
void setX2Linha(Linha* linha, double x2){
    ((struct Linha*) linha)-> x2 = x2;
}

//Função que retorna o x2 da linha
double getX2Linha(Linha linha){
    struct Linha* ptr = linha;
    return ptr-> x2;
}
//Função que seta o y2 da linha
void setY2Linha(Linha* linha, double y2){
    ((struct Linha*) linha)-> y2 = y2;
}

//Função que retorna o y2 da linha
double getY2Linha(Linha linha){
    struct Linha* ptr = linha;
    return ptr-> y2;
}
