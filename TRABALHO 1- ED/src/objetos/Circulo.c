#include "circulo.h"
#include "figuras.h"
#include<stdio.h>
#include<stdlib.h>

struct Circulo {
    int raio;
};

//Função que seta o raio
void setRaioCirculo(Circulo* circulo, double raio){
    //circulo-> raio = raio;
    ((struct Circulo*) circulo)-> raio = raio;
}

//Função que retorna o raio
double getRaioCirculo(Circulo circulo){
    struct Circulo* ptr = circulo;
    return ptr-> raio;
}