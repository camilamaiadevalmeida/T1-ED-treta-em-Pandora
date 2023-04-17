#include "foto.h"
#include "objetos/formas.h"
#include "ed/lista.h"
#include "ed/fila.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

//PONTOS PRINCIPAIS QUE PRECISA MUDAR
// nome das funções
// todos os get retornam string ao invés do valor, então tem que converter sempre que usar get
// como é uma structzona nao vai ser getCirculo e tal vai ser só get
// tem que pegar uns negocios do clausura.c e map.c e check.c e enfiar no meio ao invés de ser um negocio separado
// é só copiar e colar tudo memo e fodase, só mudar o nome das funções e converter as coisas
// depois de fazer as coisas no foto.c e bomba.c, faz as coisas no qry.c usando essas funções. se baseia no meu leitura.c
// depois de tudo le meu main.c e adapta as coisas que eu fiz do qry

struct foto
{
    Lista lista;
    bool enviado;
    double xOffset, yOffset; // offset da foto em relação ao mapa, é usado para "desrelativizar" as formas clonadas
};

struct fotoClos
{

};

struct fotoClosTxt
{
    FILE *txt;
};

//isso aqui já não tá no txt, uai? sim.................
//nao tem leitura e a leitura kd a dona
// a foto já precisa estar com as posições relativas
void reportarFotoTirada(Item item, Clausura c)
{
    Item lista = item;
    struct fotoClosTxt *cFotoTxt = (struct fotoClosTxt *)c;
    FILE *txt = cFotoTxt->txt;
    switch (get_tipo(item)[0])
    {
    case 'c':
        fprintf(txt, "Círculo %d fotografado!\n\
        X relativo: %lf\n\
        Y relativo: %lf\n",
                get_id(lista),
                get_x(lista),
                get_y(lista));
        break;
    case  'r':
        fprintf(txt, "Retângulo %d fotografado!\n\
        X relativo: %lf\n\
        Y relativo: %lf\n",
                get_id(lista),
                get_x(lista),
                get_y(lista));
        break;
    case 'l':
        fprintf(txt, "Linha %d fotografada!\n\
        X1 relativo: %lf\n\
        Y1 relativo: %lf\n\
        X2 relativo: %lf\n\
        Y2 relativo: %lf\n",
                get_id(lista),
                get_x(lista),
                get_y(lista),
                get_x2(lista),
                get_y2(lista));              
        break;
    case 't':
        fprintf(txt, "Texto %d fotografado!\n\
        X relativo: %lf\n\
        Y relativo: %lf\n",
                getTextoId(lista),
                getTextoX(lista),
                getTextoY(lista));
        break;
    }
    fprintf(txt, "\n");
}

Foto takePic(Lista lista, FILE *svg, void* formato, FILE *txt, int i)
{
    retClos cRetangulo = criaretClos(getTextoX(balao) - getBalaoR(balao),
                                                         getTextoY(balao) + getBalaoP(balao),
                                                         2 * getBalaoR(balao),
                                                         getBalaoH(balao));
    svg_rect(svg, getTextoX(balao) - getBalaoR(balao),
             getTextoY(balao) + getBalaoP(balao),
             2 * getBalaoR(balao),
             getBalaoH(balao),
             0,
             "none",
             "red",
             "stroke-dasharray=\"5,3\"");
    struct foto *foto = malloc(sizeof(struct foto));
    Lista listatemp = filter(lista, checkInRect, cRetangulo); // elementos são uma cópia dos originais
    Lista listanova = map(listatemp, copiaItem, NULL);        // copia a lista para não alterar a original
    killLst(listatemp);
    foto->enviado = false;
    struct fotoClosTxt cFotoTxt;
    cFotoTxt.txt = txt;

    fotoClos cFoto = criafotoClos(getTextoX(balao),
                                          getTextoY(balao),
                                          getBalaoR(balao),
                                          getBalaoP(balao),
                                          getBalaoH(balao));
    fold(listanova, moveElementosFoto, cFoto); // move os elementos para o início do svg baseado nas posições relativas
    foto->xOffset = getTextoX(balao) - getBalaoR(balao);
    foto->yOffset = getTextoY(balao) + getBalaoP(balao);
    liberafotoClos(cFoto);
    Fila fila = getBalaoFilaI(balao, i);
    insereFila(fila, foto);
    reportarAtributos(balao, txt);
    fold(listanova, reportarFotoTirada, &cFotoTxt);
    foto->lista = listanova;
    return foto;
}

void printPic(Foto f, FILE *svg, void* formato, double *dx, double *pontuacao)
{
    struct foto *fotoDereferenciada = (struct foto *)f;
    Lista lista = map(fotoDereferenciada->lista, copiaItem, NULL); // copia a lista para não alterar a original

    ClausuraDeslocaDireita cDesloca = criaClausuraDeslocaDireita(*dx);
    fold(lista, deslocaDireita, cDesloca); // desloca os elementos para a direita pra caber no svg
    liberaClausuraDeslocaDireita(cDesloca);

    ClausuraSvg cSvg = criaClausuraSvg(svg);
    fold(lista, escreveSvg, cSvg); // insere os elementos no svg
    liberaClausuraSvg(cSvg);

    char id[20];
    sprintf(id, "Balão: %d", getTextoId(balao));

    ClausuraPontuacao cPontuacao = criaClausuraPontuacao(0);
    fold(lista, calculaPontuacao, cPontuacao);
    char pontuacaoString[20];
    sprintf(pontuacaoString, "Pontuação: %.2lf", getClausuraPontuacao(cPontuacao));
    *pontuacao = getClausuraPontuacao(cPontuacao);
    liberaClausuraPontuacao(cPontuacao);

    char r[20];
    sprintf(r, "r: %lf", getBalaoR(balao));

    char h[20];
    sprintf(h, "h: %lf", getBalaoH(balao));

    char p[20];
    sprintf(p, "p: %lf", getBalaoP(balao));

    int distancia = 15; // distancia entre as linhas de texto

    // id do balao, pontuação, r, h, p
    svg_text(svg, *dx, getBalaoH(balao) + distancia, id, "black", "none", 0, "sans (sans-serif)", "normal", "15px", "start", NULL);
    svg_text(svg, *dx, getBalaoH(balao) + 2 * distancia, pontuacaoString, "black", "none", 0, "sans (sans-serif)", "normal", "15px", "start", NULL);
    svg_text(svg, *dx, getBalaoH(balao) + 3 * distancia, r, "black", "none", 0, "sans (sans-serif)", "normal", "15px", "start", NULL);
    svg_text(svg, *dx, getBalaoH(balao) + 4 * distancia, h, "black", "none", 0, "sans (sans-serif)", "normal", "15px", "start", NULL);
    svg_text(svg, *dx, getBalaoH(balao) + 5 * distancia, p, "black", "none", 0, "sans (sans-serif)", "normal", "15px", "start", NULL);

    // desenha o retangulo da foto
    svg_rect(svg,
             *dx,
             0,
             getBalaoR(balao) * 2,
             getBalaoH(balao),
             0,
             "none",
             "black",
             NULL);

    ClausuraMaiorX cMaiorX = criaClausuraMaiorX();
    fold(lista, achaMaiorX, cMaiorX);
    double raioBalao = getBalaoR(balao);
    *dx += raioBalao * 2;
    *dx = getClausuraMaiorX(cMaiorX) > *dx ? getClausuraMaiorX(cMaiorX) : *dx; // se alguma forma extrapolar o retangulo, atualiza a posição do retangulo
    liberaClausuraMaiorX(cMaiorX);
    fotoDereferenciada->enviado = true; // marca a foto como enviada
    killLst(lista);
}

bool sentPic(Foto f)
{
    struct foto *fotoDereferenciada = (struct foto *)f;
    return fotoDereferenciada->enviado;
}

Lista get_elementosF(Foto f)
{
    struct foto *fotoDereferenciada = (struct foto *)f;
    return fotoDereferenciada->lista;
}

void fotoOff(Foto f)
{
    struct foto *fotoDereferenciada = (struct foto *)f;
    free(fotoDereferenciada);
}

// Retorna o xOffset da foto
double get_XOffsetF(Foto f)
{
    struct foto *fotoDereferenciada = (struct foto *)f;
    return fotoDereferenciada->xOffset;
}

// Retorna o yOffset da foto
double get_YOffsetF(Foto f)
{
    struct foto *fotoDereferenciada = (struct foto *)f;
    return fotoDereferenciada->yOffset;
}