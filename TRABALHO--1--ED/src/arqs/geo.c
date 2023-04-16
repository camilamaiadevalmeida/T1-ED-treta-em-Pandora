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
    fim = 1; // para entrar no while
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
            circ = cria_circulo(i, "c", r, x, y, corb, corp);
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
            retan = cria_retangulo(i, "r", w, h, x, y, corb, corp);
            // inserir figura na lista
            insertLst(lst, retan);
            break;
        case 't':
            if (ponteiroPalavra[1] == 's')
            {
                ponteiroPalavra = strtok(NULL, " ");
                strcpy(familia, ponteiroPalavra);
                ponteiroPalavra = strtok(NULL, " ");
                if (strcmp(ponteiroPalavra, "n"))
                {
                    strcpy(peso, "normal");
                }
                else if (strcmp(ponteiroPalavra, "b"))
                {
                    strcpy(peso, "bold");
                }
                else if (strcmp(ponteiroPalavra, "b+"))
                {
                    strcpy(peso, "bolder");
                }
                else if (strcmp(ponteiroPalavra, "l"))
                {
                    strcpy(peso, "lighter");
                }
                else
                {
                    strcpy(peso, ponteiroPalavra);
                }
                ponteiroPalavra = strtok(NULL, " ");
                strcpy(tamanho, ponteiroPalavra);
                continue;
            }
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
            if (strcmp(ponteiroPalavra, "i"))
            {
                strcpy(ancora, "start");
            }
            else if (strcmp(ponteiroPalavra, "m"))
            {
                strcpy(ancora, "middle");
            }
            else if (strcmp(ponteiroPalavra, "f"))
            {
                strcpy(ancora, "end");
            }
            else
            {
                strcpy(ancora, ponteiroPalavra);
            }
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(txto, ponteiroPalavra);
            if (strcmp(txto, "v_O_v") == 0)
            {
                txt = cria_balao(i, "b", x, y, corb, corp, txto, familia, tamanho, peso, ancora);
            }
            else if (strcmp(txto, "|_T_|") == 0)
            {
                txt = cria_caca(i, "a", x, y, corb, corp, txto, familia, tamanho, peso, ancora);
            }
            else
            {
                txt = cria_texto(i, "t", x, y, corb, corp, txto, familia, tamanho, peso, ancora);
            }
            // a de avião, tá?
            //  inserir figura na lista
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
            lin = cria_linha(i, "l", x, y, x2, y2, cor);
            // inserir figura na lista
            insertLst(lst, lin);
            break;
        }
    }
}