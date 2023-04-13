#include "txt.h"

// seguir mesma estrutura dql??????m
void reportarFigura(void *forma, FILE *txt)
{
    // pra todos os tipos de figura + balao + caca +
}

// COMENTÁRIO DO JEAN: esse de printar lista int eu usei pro seguinte (gambiarra):
// eu guardo os ids dos negocios atingidos numa lista dentro de um caça
// isso é pra printar uma lista que eu SEI que vai ter só int, no caso essa
void printListaInt(Lista lista, FILE *txt)
{
    Iterador iterador = createIterador(lista, false);
    int *valor;
    while (!isIteratorEmpty(iterador))
    {
        valor = (int *)getIteratorNext(iterador);
        fprintf(txt, "%d ", *valor);
    }
}

void reportaAtrElem(void *elemento, FILE *txt)
{
    reportaAtr(getLst(elemento), txt);
}

void reportaAtrFold(Item item, Clausura c)
{
    reportaAtr(item, c);
}

void reportaAtrElemFold(Item item, Clausura c)
{
    reportaAtrElem(item, c);
}