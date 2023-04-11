#include "formas.h"
#include "../arqs/main.h"


typedef struct retangulo
{
    char x[20];
    char tipo[20];
    char y[20];
    char corb[20];
    char corp[20];
    char id[20];
    char w[20];
    char h[20];
    char rota[20];
}Rect;

typedef struct circulo {

    char id[20];
    char tipo[20];
    char r[20];
    char x[20];
    char y[20];
    char corb[20];
    char corp[20];
    char rota[20];
}Circ;

typedef struct linha{

    char id[20];
    char tipo[20];
    char x[20];
    char y[20];
    char x2[20];
    char y2[20];
    char cor[20];
    char rota[20];
}Linha;

typedef struct texto
{
    char id[20];
    char tipo[20];
    char x[20];
    char y[20];
    char corb[20];
    char corp[20];
    char txto[400];
    char rota[20];
}Text;

typedef struct formato{
    //char tipo[20];
    struct formato *prox;
    struct formato *ant;

        Rect retangulo;
        Circ circulo;
        Linha linha;
        Text texto;
    
}forma;


void* cria_retangulo(char id[], char tipo[], char w[], char h[],char x[],char y[],char corb[],char corp [],char rota[]){
    Rect *novo = malloc (sizeof(Rect));

    void set_id(void* formato, char id[]){
        struct formato *forma = formato;
        strcpy(forma->retangulo.id, id);
    }

    char* get_id(void* formato){
        struct formato *forma = formato;
        return forma->retangulo.id;
    }

    void set_tipo(void* formato, char tipo[]){
        struct formato *forma = formato;
        strcpy(forma->retangulo.tipo, tipo);
    }

    char* get_tipo(void* formato)
    {
        struct formato *forma = formato;
        return forma->retangulo.tipo;
    }
    void set_w(void* formato, char w[])
    {
        struct formato *forma = formato;
        strcpy(forma->retangulo.w, w);
    }
    char* get_w(void* formato)
    {
        struct formato *forma = formato;
        return forma->retangulo.w;
    }
    void set_h(void* formato, char h[])
    {
        struct formato *forma = formato;
        strcpy(forma->retangulo.h, h);
    }
    char* get_h(void* formato)
    {
        struct formato *forma = formato;
        return forma->retangulo.h;
    }
    void set_x(void* formato, char x[])
    {
        struct formato *forma = formato;
        strcpy(forma->retangulo.x, x);
    }
    char* get_x(void* formato)
    {
        struct formato *forma = formato;
        return forma->retangulo.x;
    }
    void set_y(void* formato, char y[])
    {
        struct formato *forma = formato;
        strcpy(forma->retangulo.y, y);
    }
    char* get_y(void* formato)
    {
        struct formato *forma = formato;
        return forma->retangulo.y;
    }
    void set_corb(void* formato, char corb[])
    {
        struct formato *forma = formato;
        strcpy(forma->retangulo.corb, corb);
    }
    char* get_corb(void* formato)
    {
        struct formato *forma = formato;
        return forma->retangulo.corb;
    }
    void set_corp(void* formato, char corp[])
    {
        struct formato *forma = formato;
        strcpy(forma->retangulo.corp, corp);
    }
    char* get_corp(void* formato)
    {
        struct formato *forma = formato;
        return forma->retangulo.corp;
    }
    //rotação vem depois
    if(novo != NULL){
    return novo;
    }
    else
    {
        return 0;
    }
}

void* cria_circulo(char id[], char tipo[], char r[],char x[],char y[],char corb[],char corp [],char rota[]){
    Circ *novo = malloc (sizeof(Circ)); 
    void set_id(void* formato, char id[])
    {
        struct formato *forma = formato;
        strcpy(forma->circulo.id, id);
    }

    char* get_id(void* formato)
    {
        struct formato *forma = formato;
        return forma->circulo.id;
    }
    void set_tipo(void* formato, char tipo[])
    {
        struct formato *forma = formato;
        strcpy(forma->circulo.tipo, tipo);
    }
    char* get_tipo(void* formato)
    {
        struct formato *forma = formato;
        return forma->circulo.tipo;
    }
    void set_r(void* formato, char r[])
    {
        struct formato *forma = formato;
        strcpy(forma->circulo.r, r);
    }
    char* get_r(void* formato)
    {
        struct formato *forma = formato;
        return forma->circulo.r;
    }
    void set_x(void* formato, char x[])
    {
        struct formato *forma = formato;
        strcpy(forma->circulo.x, x);
    }
    char* get_x(void* formato)
    {
        struct formato *forma = formato;
        return forma->circulo.x;
    }
    void set_y(void* formato, char y[])
    {
        struct formato *forma = formato;
        strcpy(forma->circulo.y, y);
    }
    char* get_y(void* formato)
    {
        struct formato *forma = formato;
        return forma->circulo.y;
    }
    void set_corb(void* formato, char corb[])
    {
        struct formato *forma = formato;
        strcpy(forma->circulo.corb, corb);
    }
    char* get_corb(void* formato)
    {
        struct formato *forma = formato;
        return forma->circulo.corb;
    }
    void set_corp(void* formato, char corp[])
    {
        struct formato *forma = formato;
        strcpy(forma->circulo.corp, corp);
    }
    char* get_corp(void* formato)
    {
        struct formato *forma = formato;
        return forma->circulo.corp;
    }
    //rotação vem depois    == 0 //por enquanto
    
    if(novo != NULL){
    return novo;
    }
    else
    {
        return 0;
    }
}

void* cria_linha (char id[], char tipo[], char x[],char y[],char x2[],char y2[],char cor[],char rota[]){

    Linha* novo = malloc (sizeof(Linha));
    
    void set_id(void* formato, char id[])
    {
        struct formato *forma = formato;
        strcpy(forma->linha.id, id);
    }
    char* get_id(void* formato)
    {
        struct formato *forma = formato;
        strcpy(forma->linha.id, id);
    }
    void set_tipo(void* formato, char tipo[])
    {
        struct formato *forma = formato;
        strcpy(forma->linha.tipo, tipo);
    }
    char* get_tipo(void* formato)
    {
        struct formato *forma = formato;
        return forma->linha.tipo;
    }
    void set_x(void* formato, char x[])
    {
        struct formato *forma = formato;
        strcpy(forma->linha.x, x);
    }
    char* get_x(void* formato)
    {
        struct formato *forma = formato;
        return forma->linha.x;
    }
    void set_y(void* formato, char y[])
    {
        struct formato *forma = formato;
        strcpy(forma->linha.y, y);
    }
    char* get_y(void* formato)
    {
        struct formato *forma = formato;
        return forma->linha.y;
    }
    void set_x2(void* formato, char x2[])
    {
        struct formato *forma = formato;
        strcpy(forma->linha.x2, x2);
    }
    char* get_x2(void* formato)
    {
        struct formato *forma = formato;
        return forma->linha.x2;
    }
    void set_y2(void* formato, char y2[])
    {
        struct formato *forma = formato;
        strcpy(forma->linha.y2, y2);
    }
    char* get_y2(void* formato)
    {
        struct formato *forma = formato;
        return forma->linha.y2;
    }
    void set_cor(void* formato, char cor[])
    {
        struct formato *forma = formato;
        strcpy(forma->linha.cor, cor);
    }
    char* get_cor(void* formato)
    {
        struct formato *forma = formato;
        return forma->linha.cor;
    }
    //rotação vem depois          

    if(novo != NULL){
    return novo;
    }
    else
    {
        return 0;
    }
}

void* cria_texto (char i[], char tipo[], char x[],char y[],char corb[], char corp[],char txto[],char rota[]){

    Text* novo = malloc (sizeof(Text));
    
    void set_id(void* formato, char id[])
    {
        struct formato *forma = formato;
        strcpy(forma->texto.id, id);
    }
    char* get_id(void* formato)
    {
        struct formato *forma = formato;
        return forma->texto.id;
    }
    void set_tipo(void* formato, char tipo[])
    {
        struct formato *forma = formato;
        strcpy(forma->texto.tipo, tipo);
    }
    char* get_tipo(void* formato)
    {
        struct formato *forma = formato;
        return forma->texto.tipo;
    }
    void set_x(void* formato, char x[])
    {
        struct formato *forma = formato;
        strcpy(forma->texto.x, x);
    }
    char* get_x(void* formato)
    {
        struct formato *forma = formato;
        return forma->texto.x;
    }
    void set_y(void* formato, char y[])
    {
        struct formato *forma = formato;
        strcpy(forma->texto.y, y);
    }
    char* get_y(void* formato)
    {
        struct formato *forma = formato;
        return forma->texto.y;
    }
    void set_corb(void* formato, char corb[])
    {
        struct formato *forma = formato;
        strcpy(forma->texto.corb, corb);
    }
    char* get_corb(void* formato)
    {
        struct formato *forma = formato;
        return forma->texto.corb;
    }
    void set_corp(void* formato, char corp[])
    {
        struct formato *forma = formato;
        strcpy(forma->texto.corp, corp);
    }
    char* get_corp(void* formato)
    {
        struct formato *forma = formato;
        return forma->texto.corp;
    }
    void set_txto(void* formato, char txto[])
    {
        struct formato *forma = formato;
        strcpy(forma->texto.txto, txto);
    }
    char* get_txto(void* formato)
    {
        struct formato *forma = formato;
        return forma->texto.txto;
    }
    //rotação vem depois 
    if(novo != NULL){
    return novo;
    }
    else
    {
        return 0;
    }
}

//faz sentido eu precisar receber o tipo antes


//rotacionar e etc tbm

//ideia: 