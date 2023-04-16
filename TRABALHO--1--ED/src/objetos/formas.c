#include "formas.h"
#include "../ed/lista.h"
#include "../ed/fila.h"
#include "../arqs/libsgerais.h"

typedef struct retangulo
{
    char w[50];
    char h[50];
} Rect;

typedef struct circulo
{
    char r[50];
} Circ;

typedef struct linha
{
    char x2[50];
    char y2[50];
} Linha;

typedef struct texto
{
    char txto[400];
    char ancora[50];
    char familia[50];
    char tamanho[50];
    char peso[50];
    char rota[50];
} Text;

typedef struct balao
{
    char tipo[50];
    char r[50];
    char h[50];
    char p[50];
    Fila *filaFotos[9];

} Balao;

//quando o caca dispara, as ids dos alvos acertados vão pra um vetorzão
typedef struct caca
{
    int disparos;
    int alvo[50];
    int tamanhoAtual;

} Caca;

typedef struct formato
{
    // coisas gerais
    char id[50];
    char tipo[50];
    char x[50];
    char y[50];
    char corb[50];
    char corp[50];
    char rota[50];

    // coisas especificas
    Rect retangulo;
    Circ circulo;
    Linha linha;
    Text texto;
    Balao balao;
    Caca caca;
} Forma;


void *cria_balao(char i[], char tipo[], char x[], char y[], char corb[], char corp[], char txto[], char familia[], char tamanho[], char peso[], char ancora[])
{
    Forma *balao = (Forma *)malloc(sizeof(Forma));

    set_tipo(balao, tipo);
    set_id(balao, i);
    set_tipo(balao, tipo);
    set_x(balao, x);
    set_y(balao, y);
    set_corb(balao, corb);
    set_corp(balao, corp);
    set_txto(balao, txto); 
    set_familia(balao, familia);
    set_tamanho(balao, tamanho);
    set_peso(balao, peso);
    set_ancora(balao, ancora);
    set_rota(balao, "0");

    return balao;
}

void *cria_caca(char i[], char tipo[], char x[], char y[], char corb[], char corp[], char txto[], char familia[], char tamanho[], char peso[], char ancora[])
{
    Forma *caca = (Forma *)malloc(sizeof(Forma));
    set_id(caca, i);
    set_tipo(caca, tipo);
    set_x(caca, x);
    set_y(caca, y);
    set_corb(caca, corb);
    set_corp(caca, corp);
    set_txto(caca, txto); 
    set_familia(caca, familia);
    set_tamanho(caca, tamanho);
    set_peso(caca, peso);
    set_ancora(caca, ancora);
    set_rota(caca, "0");

    return caca;
}


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

//cria_circulo(char i[], char tipo[], char r[], char x[], char y[], char corb[], char corp[])
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

char *get_tipo(void *formato)
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
    switch ((f->tipo)[0])
    {
        case 'c':
            strcpy(f->circulo.r, r);
            break;
        case 'b':
            strcpy(f->balao.r, r);
            break;
    }
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
    free(formato);
}
// Funções para a manipulação de caças e balões

void set_p(void *formato, char p[])
{
    Forma *f = (Forma *)formato;
    strcpy(f->balao.p, p);
}


char *get_p(void *formato)
{
    Forma *f = (Forma *)formato;
    return f->balao.p;
}

int get_disparos(void *formato)
{
    Forma *f = (Forma *)formato;
    return f->caca.disparos;
}

void set_disparos(void *formato, int disparos)
{
    Forma *f = (Forma *)formato;
    f->caca.disparos = disparos;
}

int *get_alvosAcertados(void *formato)
{
    Forma *f = (Forma *)formato;
    return f->caca.alvo;
}

void inserirAlvos(void *formato, int alvo)
{
    Forma *f = (Forma *)formato;
    f->caca.alvo[f->caca.tamanhoAtual] = alvo;
    f->caca.tamanhoAtual++;
    if(f->caca.tamanhoAtual >=50)
    {
        f->caca.tamanhoAtual = 0;
    }
}