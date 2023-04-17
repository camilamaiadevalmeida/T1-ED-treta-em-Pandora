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

struct baloesAchados
{
    char baloesAchados[50];
    void *balaoEncontrado;
};

struct cacasAchados
{
    char cacasAchadas[50];
    void *cacaEncontrada;
};

void achaForma(Item item, Clausura c)
{
    struct idAchado *id = (struct idAchado *)c;
    if (strcmp(id->idProcurado, get_id(item)) == 0)
        id->formaAchada = item;
}

// funçao do fold tem que ver se o elemento atual é um balão
//Função que percorre a lista, encontra o tipo "b" e  depois reporta os dados dos balões
void reportaBaloes(Item item, Clausura c) {
    FILE *arq = (FILE*) c;
    //ler do começo da lista até o final

    if (strcmp(get_tipo(item), "b") == 0) {
        fprintf(arq, "ID=%s X=%s Y=%s W=%s H=%s CorB=%s CorP=%s Texto=%s\n",
            get_id(item), get_x(item), get_y(item), get_corb(item), get_corp(item), get_texto(item), get_familia(item), get_tamanho(item), get_peso(item), get_ancora(item), get_rota(item));
    }
}

void reportaCacas(Item item, Clausura c){
    FILE *arq = (FILE*) c;
    //ler do começo da lista até o final

    if (strcmp(get_tipo(item), "c") == 0) {
        fprintf(arq, "ID=%s X=%s Y=%s R=%s CorB=%s CorP=%s Texto=%s\n",
            get_id(item), get_x(item), get_y(item), get_corb(item), get_corp(item), get_texto(item), get_familia(item), get_tamanho(item), get_peso(item), get_ancora(item), get_rota(item));
    }
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
    struct baloesAchados baloesFound;
    struct cacasAchados cacasFound;
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
        /*  Envia fotos da lista l do balão i para a base.
            Base categoriza cada foto.
            TXT: para cada foto enviada, reportar
            identicador e atributos da foto e pontuação.6
            SVG: cria novo svg com mesmo nome do svg
            + sufixo sfx (ex. a1-q1-sfx.svg) mostrando as
            fotos baixadas em sequência
            */
        else if (strcmp(ponteiroPalavra, "df") == 0)
        {
        }
        
        else if (strcmp(ponteiroPalavra, "d") == 0)
        {
        }
        else if (strcmp(ponteiroPalavra, "b?") == 0)
        {
            fold(lst, reportaBaloes, &baloesFound);
            // + questão das fotos
        }
        //Reporta os dados de todos as caças existentes: seus atributos, a rotação corrente, quantos disparos já efetuou e os identificadores dos elementos que acertou até o momento.
        else if (strcmp(ponteiroPalavra, "c?") == 0)
        {
            fold(lst, reportaCacas, &cacasFound);
        }
    }
}