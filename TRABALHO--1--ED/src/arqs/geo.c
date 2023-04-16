#include "geo.h"
#include "../objetos/formas.h"
#include "../arqs/libsgerais.h"
#include "../ed/lista.h"

void dealWithGeo(FILE *geo, Lista lst)
{
    char *x = (char *)malloc(50 * sizeof(char));
    char *y = (char *)malloc(50 * sizeof(char));
    char *corb = (char *)malloc(50 * sizeof(char));
    char *corp = (char *)malloc(50 * sizeof(char));
    char *i = (char *)malloc(50 * sizeof(char));
    char *r = (char *)malloc(50 * sizeof(char)); // c
    char *w = (char *)malloc(50 * sizeof(char));
    char *h = (char *)malloc(50 * sizeof(char)); // r
    char *x2 = (char *)malloc(50 * sizeof(char));
    char *y2 = (char *)malloc(50 * sizeof(char));
    char *cor = (char *)malloc(50 * sizeof(char));   // l
    char *txto = (char *)malloc(400 * sizeof(char)); // t
    char *ancora = (char *)malloc(50 * sizeof(char));
    char *familia = (char *)malloc(50 * sizeof(char));
    char *tamanho = (char *)malloc(50 * sizeof(char));
    char *peso = (char *)malloc(50 * sizeof(char));
    char tipo;
    void *retan;
    void *circ;
    void *lin;
    void *txt;
    char fim;

    fseek(geo, 0, SEEK_SET);
    fim = getc(geo);
    char *linha = (char *)malloc(500 * sizeof(char));
    char *ponteiroPalavra;
    while (fim != EOF)
    {
        fgets(linha, 500, geo);
        fim = getc(geo);
        fseek(geo, -1, SEEK_CUR);
        if (linha[0] == '\n')
        {
            continue;
        }
        ponteiroPalavra = strtok(linha, " ");
        tipo = ponteiroPalavra[0];
        switch (tipo)
        {
        case 'c':
            strcpy(i, ponteiroPalavra[1]);
            strcpy(x, ponteiroPalavra[2]);
            strcpy(y, ponteiroPalavra[3]);
            strcpy(r, ponteiroPalavra[4]);
            strcpy(corb, ponteiroPalavra[5]);
            strcpy(corp, ponteiroPalavra[6]);
            circ = cria_circulo("c", i, x, y, r, corb, corp);
            // inserir figura na lista
            insertLst(lst, circ);
            break;
        case 'r':
            strcpy(i, ponteiroPalavra[1]);
            strcpy(x, ponteiroPalavra[2]);
            strcpy(y, ponteiroPalavra);
            strcpy(w, ponteiroPalavra);
            strcpy(h, ponteiroPalavra);
            strcpy(corb, ponteiroPalavra);
            strcpy(corp, ponteiroPalavra);
            retan = cria_retangulo("r", i, x, y, w, h, corb, corp);
            // inserir figura na lista
            insertLst(lst, retan);
            break;
        case 't':
            strcpy(i, ponteiroPalavra);
            strcpy(x, ponteiroPalavra);
            strcpy(y, ponteiroPalavra);
            strcpy(corb, ponteiroPalavra);
            strcpy(corp, ponteiroPalavra);
            strcpy(ancora, ponteiroPalavra);
            strcpy(txto, ponteiroPalavra);
            txt = cria_texto("t", i, x, y, corb, corp, ancora, txto, tamanho, familia, peso);
            // inserir figura na lista
            insertLst(lst, txt);
            break;
        case 'l':
            strcpy(i, ponteiroPalavra);
            strcpy(x, ponteiroPalavra);
            strcpy(y, ponteiroPalavra);
            strcpy(x2, ponteiroPalavra);
            strcpy(y2, ponteiroPalavra);
            strcpy(cor, ponteiroPalavra);
            lin = cria_linha("l", i, x, y, x2, y2, cor);
            // inserir figura na lista
            insertLst(lst, lin);
            break;
        }
    }
}