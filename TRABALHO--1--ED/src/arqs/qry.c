#include "qry.h"

#include "../objetos/formas.h"
#include "../arqs/libsgerais.h"
#include "../ed/lista.h"

//função de receber forma e relatar ela

struct idAchado
{
    char idProcurado[50];
    void *formaAchada;
};

void achaForma(Item item, Clausura c)
{
    struct idAchado *id = (struct idAchado *)c;
    if (strcmp(id->idProcurado, get_id(item)) == 0)
        id->formaAchada = item;
}

// funçao do fold tem que ver se o elemento atual é um balão
void achaBalao(Item item, Clausura c)
{
    //aplica em cada elemento
    
}

void dealWithQry(FILE *qry, Lista lst)
{
    char tipo;
    void *retan;
    void *circ;
    void *lin;
    void *txt;
    char fim;
    char i[50];
    char dx[50];
    char dy[50];
    char grs[50];
    char r[50];
    char p[50];
    char h[50];
    int filaEscolhida;
    int filaAchada;
    struct idAchado idStruct;
    fseek(qry, 0, SEEK_SET);
    fim = 1; // para entrar no while
    char *linha = (char *)malloc(500 * sizeof(char));
    char *ponteiroPalavra;
    while (fim != EOF)
    {
        idStruct.formaAchada = NULL;
        fgets(linha, 500, qry);
        fim = getc(qry);
        fseek(qry, -1, SEEK_CUR);
        if (linha[0] == '\n')
        {
            continue;
        }
        ponteiroPalavra = strtok(linha, " ");
        tipo = ponteiroPalavra[0];
        // mv g ff tf df d b? c?
        if (strcmp(ponteiroPalavra, "mv") == 0)
        {
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(i, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(dx, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(dy, ponteiroPalavra);
            strcpy(idStruct.idProcurado, i);
            fold(lst, achaForma, &idStruct);
            if (idStruct.formaAchada != NULL)
            {
                double novoX = atof(get_x(idStruct.formaAchada)) + atof(dx);
                double novoY = atof(get_y(idStruct.formaAchada)) + atof(dy);
                char novoXStr[50];
                char novoYStr[50];
                sprintf(novoXStr, "%lf", novoX);
                sprintf(novoYStr, "%lf", novoY);
                set_x(idStruct.formaAchada, novoXStr);
                set_y(idStruct.formaAchada, novoYStr);
            }
        }
        else if (strcmp(ponteiroPalavra, "g") == 0)
        {
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(i, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(grs, ponteiroPalavra);
            strcpy(idStruct.idProcurado, i);
            fold(lst, achaForma, &idStruct);
            if(idStruct.formaAchada != NULL)
            {
                double novoGRS = atof(get_rota(idStruct.formaAchada)) + atof(grs);
                char novoGRSStr[50];
                sprintf(novoGRSStr, "%lf", novoGRS);
                set_rota(idStruct.formaAchada, novoGRSStr);
            }    
        }
        else if (strcmp(ponteiroPalavra, "ff") == 0)
        {
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(i, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(r, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(p, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(h, ponteiroPalavra);
            strcpy(idStruct.idProcurado, i);
            fold(lst, achaForma, &idStruct);
            if (idStruct.formaAchada != NULL)
            {
                set_r(idStruct.formaAchada, r);
                set_p(idStruct.formaAchada, p);
                set_h(idStruct.formaAchada, h);
            }
        }
        else if (strcmp(ponteiroPalavra, "tf") == 0)
        {
            ponteiroPalavra = strtok(NULL, " ");
            strcpy(i, ponteiroPalavra);
            ponteiroPalavra = strtok(NULL, " ");
            //escolher em qual fila a foto será inserida
            strcpy(filaEscolhida, ponteiroPalavra);
            strcpy(idStruct.idProcurado, i);
            fold(lst, achaForma, &idStruct);
            
        }
        else if (strcmp(ponteiroPalavra, "df") == 0)
        {
        }
        else if (strcmp(ponteiroPalavra, "d") == 0)
        {
        }
        else if (strcmp(ponteiroPalavra, "b?") == 0)
        {
            fold
            // funçao do fold tem que ver se o elemento atual é um balão


            // se for, escreve ele no txt
        }
        else if (strcmp(ponteiroPalavra, "c?") == 0)
        {
        }
    }
}