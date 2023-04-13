#include "foto.h"
#include "headers.h"
#include "../arqs/main.h"

//Implementação de fotos

struct foto
{
    Lista lista;
    double x_offset;
    double y_offset;
    bool sent;
};

struct clausuraFotoTxt
{
    FILE *txt;
    int i;
};

//reporta, tira foto e imprime tem que ver com calma pq depende um teco da forma como eu fiz as formas

Lista getFotoElem(Foto f)
{
    struct foto *fotoDereferenciada = (struct foto *)f;
    return fotoDereferenciada->lista;
}

double get_X_offsetFoto(Foto f)
{
    struct foto *fotoDereferenciada = (struct foto *)f;
    return fotoDereferenciada->x_offset;
}

double get_Y_offsetFoto(Foto f)
{
    struct foto *fotoDereferenciada = (struct foto *)f;
    return fotoDereferenciada->y_offset;
}

bool sentFoto(Foto f)
{
    struct foto *fotoDereferenciada = (struct foto *)f;
    return fotoDereferenciada->sent;
}

void killFoto(Foto f)
{
    struct foto *fotoDereferenciada = (struct foto *)f;
    free(fotoDereferenciada);
}

