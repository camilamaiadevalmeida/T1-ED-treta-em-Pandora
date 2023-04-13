#include "formas.h"
#include "texto.h"
#include "tipos.h"
#include "../arqs/main.h"

typedef struct retangulo
{
    char w[20];
    char h[20];
} Rect;

typedef struct circulo
{
    char r[20];
} Circ;

typedef struct linha
{
    char x2[20];
    char y2[20];
} Linha;

typedef struct texto
{
    enum TipoForma tipo;
    enum TipoVeiculo tipoVeiculo;
    struct balao *balaoDados;
    struct caca *cacaDados;
    char txto[400];
    char ancora[20];
    char familia[20];
    char tamanho[20];
    char peso[20];
    char rota[20];
} Text;

struct balao
{
    double r;
    double p;
    double h;
    Fila *filaFotos[9];
};

struct caca
{
    int disparos;
    Lista *alvosAcertados;
};

typedef struct formato
{
    // coisas gerais
    char id[20];
    char tipo[20];
    char x[20];
    char y[20];
    char corb[20];
    char corp[20];
    char rota[20];

    // coisas especificas
    Rect retangulo;
    Circ circulo;
    Linha linha;
    Text texto;
} Forma;

void *cria_retangulo(char i[], char tipo[], char w[], char h[], char x[], char y[], char corb[], char corp[])
{
    Forma *retangulo = (Forma *)malloc(sizeof(Forma));

    set_id(retangulo, i);
    set_tipo(retangulo, tipo);
    set_x(retangulo, x);
    set_y(retangulo, y);
    set_corb(retangulo, corb);
    set_corp(retangulo, corp);
    set_w(retangulo, w);
    set_h(retangulo, h);

    set_rota(retangulo, "0");

    return retangulo;
}

void *cria_circulo(char i[], char tipo[], char r[], char x[], char y[], char corb[], char corp[])
{
    Forma *circulo = (Forma *)malloc(sizeof(Forma));

    set_id(circulo, i);
    set_tipo(circulo, tipo);
    set_x(circulo, x);
    set_y(circulo, y);
    set_corb(circulo, corb);
    set_corp(circulo, corp);
    set_r(circulo, r);

    set_rota(circulo, "0");

    return circulo;
}

void *cria_linha(char i[], char tipo[], char x[], char y[], char x2[], char y2[], char cor[])
{
    Forma *linha = (Forma *)malloc(sizeof(Forma));

    set_id(linha, i);
    set_tipo(linha, tipo);
    set_x(linha, x);
    set_y(linha, y);
    set_corb(linha, cor);
    set_corp(linha, cor);
    set_x2(linha, x2);
    set_y2(linha, y2);

    set_rota(linha, "0");

    return linha;
}

void *cria_texto(char i[], char tipo[], char x[], char y[], char corb[], char corp[], char txto[], char familia[], char tamanho[], char peso[], char ancora[])
{
    Forma *texto = (Forma *)malloc(sizeof(Forma));

    set_id(texto, i);
    set_tipo(texto, tipo);
    set_x(texto, x);
    set_y(texto, y);
    set_corb(texto, corb);
    set_corp(texto, corp);
    set_txto(texto, txto);
    set_familia(texto, familia);
    set_tamanho(texto, tamanho);
    set_peso(texto, peso);
    set_ancora(texto, ancora);
    set_rota(texto, "0");

    strncpy(t->texto, txto, 50);
    if (strlen(txto) > 50)
    {
        t->txto[49] = '\0';
    }
    if (strncmp(txto, "v_O_v", 5) == 0)
    {
        t->tipoVeiculo = BALAO;
        t->balaoDados = (struct balao *)malloc(sizeof(struct balao));
        t->balaoDados->r = 0;
        t->balaoDados->p = 0;
        t->balaoDados->h = 0;
        for (int i = 0; i < 10; i++)
        {
            t->balaoDados->filaFotos[i] = criaFila(15);
        }
    }
    else if (strncmp(txto, "|-T-|", 5) == 0)
    {
        t->tipoVeiculo = CACA;
        t->cacaDados = (struct caca *)malloc(sizeof(struct caca));
        t->cacaDados->disparosEfetuados = 0;
        t->cacaDados->idsAcertados = createLst(-1);
    }
    else
    {
        t->tipoVeiculo = NENHUM;
    }
    t->rotacao = 0;
    t->textoFamilia = familia;
    t->textoPeso = peso;
    t->textoTamanho = tamanho;

    return texto;
}

// Funções de set:

void set_id(void *formato, char id[])
{
    Forma *f = (Forma *)formato;
    strcpy(f->id, id);
}

void set_tipo(void *formato, char tipo[])
{
    Forma *f = (Forma *)formato;
    strcpy(f->tipo, tipo);
}

void set_x(void *formato, char x[])
{
    Forma *f = (Forma *)formato;
    strcpy(f->x, x);
}

void set_y(void *formato, char y[])
{
    Forma *f = (Forma *)formato;
    strcpy(f->y, y);
}

void set_corb(void *formato, char corb[])
{
    Forma *f = (Forma *)formato;
    strcpy(f->corb, corb);
}

void set_corp(void *formato, char corp[])
{
    Forma *f = (Forma *)formato;
    strcpy(f->corp, corp);
}

void set_rota(void *formato, char rota[])
{
    Forma *f = (Forma *)formato;
    strcpy(f->rota, rota);
}

// Funções de get:

char *get_id(void *formato)
{
    Forma *f = (Forma *)formato;
    return f->id;
}

char get_tipo(void *formato)
{
    Forma *f = (Forma *)formato;
    return f->tipo;
}

char *get_x(void *formato)
{
    Forma *f = (Forma *)formato;
    return f->x;
}

char *get_y(void *formato)
{
    Forma *f = (Forma *)formato;
    return f->y;
}

char *get_corb(void *formato)
{
    Forma *f = (Forma *)formato;
    return f->corb;
}

char *get_corp(void *formato)
{
    Forma *f = (Forma *)formato;
    return f->corp;
}

char *get_rota(void *formato)
{
    Forma *f = (Forma *)formato;
    return f->rota;
}

// Funções de get específicas:

char *get_w(void *formato)
{
    Forma *f = (Forma *)formato;
    return f->retangulo.w;
}

char *get_h(void *formato)
{
    Forma *f = (Forma *)formato;
    return f->retangulo.h;
}

char *get_r(void *formato)
{
    Forma *f = (Forma *)formato;
    return f->circulo.r;
}

char *get_x2(void *formato)
{
    Forma *f = (Forma *)formato;
    return f->linha.x2;
}

char *get_y2(void *formato)
{
    Forma *f = (Forma *)formato;
    return f->linha.y2;
}

char *get_txto(void *formato)
{
    Forma *f = (Forma *)formato;
    return f->texto.txto;
}

char *get_familia(void *formato)
{
    Forma *f = (Forma *)formato;
    return f->texto.familia;
}

char *get_tamanho(void *formato)
{
    Forma *f = (Forma *)formato;
    return f->texto.tamanho;
}

char *get_peso(void *formato)
{
    Forma *f = (Forma *)formato;
    return f->texto.peso;
}

char *get_ancora(void *formato)
{
    Forma *f = (Forma *)formato;
    return f->texto.ancora;
}

// Funções de set específicas:

void set_w(void *formato, char w[])
{
    Forma *f = (Forma *)formato;
    strcpy(f->retangulo.w, w);
}

void set_h(void *formato, char h[])
{
    Forma *f = (Forma *)formato;
    strcpy(f->retangulo.h, h);
}

void set_r(void *formato, char r[])
{
    Forma *f = (Forma *)formato;
    strcpy(f->circulo.r, r);
}

void set_x2(void *formato, char x2[])
{
    Forma *f = (Forma *)formato;
    strcpy(f->linha.x2, x2);
}

void set_y2(void *formato, char y2[])
{
    Forma *f = (Forma *)formato;
    strcpy(f->linha.y2, y2);
}

void set_txto(void *formato, char txto[])
{
    Forma *f = (Forma *)formato;
    strcpy(f->texto.txto, txto);
}

void set_familia(void *formato, char familia[])
{
    Forma *f = (Forma *)formato;
    strcpy(f->texto.familia, familia);
}

void set_tamanho(void *formato, char tamanho[])
{
    Forma *f = (Forma *)formato;
    strcpy(f->texto.tamanho, tamanho);
}

void set_peso(void *formato, char peso[])
{
    Forma *f = (Forma *)formato;
    strcpy(f->texto.peso, peso);
}

void set_ancora(void *formato, char ancora[])
{
    Forma *f = (Forma *)formato;
    strcpy(f->texto.ancora, ancora);
}

void killForma(void *formato)
{
    Forma *f = (Forma *)formato;
    switch ()
    {
    case 'r':
        free(f->retangulo);
        break;
    case 'c':
        free(f->circulo);
        break;
    case 'l':
        free(f->linha);
        break;
    case 't':
        struct texto *texto = (struct texto *)t;
        free(f->texto);
        if (texto->tipoVeiculo == BALAO)
        {
            for (int i = 0; i < 9; i++)
            {
                destroiFila(texto->balaoDados->filaFotos[i]);
            }
            free(texto->balaoDados);
        }
        else if (texto->tipoVeiculo == CACA)
        {
            killLst(texto->cacaDados->alvosAcertados);
            free(texto->cacaDados);
        }
        break;
    }
}

// faz sentido eu precisar receber o tipo antes

// rotacionar e etc tbm

// ideia: