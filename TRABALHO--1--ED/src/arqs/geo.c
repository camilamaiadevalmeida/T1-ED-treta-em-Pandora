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
            strcpy(i, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(x, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(y, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(r, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(corb, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(corp, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            circ = cria_circulo("c", i, x, y, r, corb, corp);
            // inserir figura na lista
            insertLst(lst, circ);
            break;
        case 'r':
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(i, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(x, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(y, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(w, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(h, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(corb, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(corp, ponteiroPalavra);
            retan = cria_retangulo("r", i, x, y, w, h, corb, corp);
            // inserir figura na lista
            insertLst(lst, retan);
            break;
        case 't':
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(i, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(x, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(y, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(corb, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(corp, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(ancora, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(txto, ponteiroPalavra);
            txt = cria_texto("t", i, x, y, corb, corp, ancora, txto, tamanho, familia, peso);
            // inserir figura na lista
            insertLst(lst, txt);
            break;
        case 'l':
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(i, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(x, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(y, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(x2, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(y2, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(cor, ponteiroPalavra);
            lin = cria_linha("l", i, x, y, x2, y2, cor);
            // inserir figura na lista
            insertLst(lst, lin);
            break;
        }
    }
}