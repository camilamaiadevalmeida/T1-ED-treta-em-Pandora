#include"figuras.h"

#include<stdio.h>
#include<stdlib.h>

struct Retangulo {
    int w;
    int h;
};

void setWRetangulo(Retangulo* retangulo, double w)
{
    ((struct Retangulo*) retangulo)-> w = w;
}

void setHRetangulo(Retangulo* retangulo, double h)
{
    ((struct Retangulo*) retangulo)-> h = h;
}

double getWRetangulo(Retangulo retangulo)
{
    struct Retangulo* ptr = retangulo;
    return ptr-> w;
}

double getHRetangulo(Retangulo retangulo)
{
    struct Retangulo* ptr = retangulo;
    return ptr-> h;
}

