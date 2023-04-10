#include "formas.h"
#include "../arqs/main.h"


typedef struct retangulo
{
    char x[20];
    char y[20];
    char corb[20];
    char corp[20];
    char i[20];
    char w[20];
    char h[20];
    char rota[20];
}Rect;

typedef struct circulo {

    char i[20];
    char r[20];
    char x[20];
    char y[20];
    char corb[20];
    char corp[20];
    char rota[20];
}Circ;

typedef struct linha{

    char i[20];
    char x1[20];
    char y1[20];
    char x2[20];
    char y2[20];
    char cor[20];
    char rota[20];
}Linha;

typedef struct texto
{
    char i[20];
    char x[20];
    char y[20];
    char corb[20];
    char corp[20];
    char txto[400];
    char rota[20];
}Text;

struct formato{
    Rect retan;
    Circ circulo;
    Linha linha;
    Text texto;

    char tipo_forma[20];
    struct formato *prox;

};




void* cria_retangulo(char i[], char w[], char h[],char x[],char y[],char corb[],char corp [],char rota[]){
    struct retangulo *novo;

    novo = malloc (sizeof(Rect));
    strcpy(novo->i,i);
    strcpy(novo->w,w);
    strcpy(novo->h,h);
    strcpy(novo->x,x);
    strcpy(novo->y,y);
    strcpy(novo->corb,corb);
    strcpy(novo->corp,corp);
    strcpy(novo->rota,rota);

    if(novo != NULL){
    return novo;
    }
    else
    {
        return 0;
    }
}

void* cria_circulo(char i[], char r[],char x[],char y[],char corb[],char corp [],char rota[]){

    Circ* novo = malloc (sizeof(Rect));
    strcpy(novo->i,i);
    strcpy(novo->r,r);
    strcpy(novo->x,x);
    strcpy(novo->y,y);
    strcpy(novo->corb,corb);
    strcpy(novo->corp,corp);
    strcpy(novo->rota,rota);
    
    if(novo != NULL){
    return novo;
    }
    else
    {
        return 0;
    }
}

void* cria_linha (char i[],char x1[],char y1[],char x2[],char y2[],char cor[],char rota[]){

    Linha* novo = malloc (sizeof(Linha));
    strcpy(novo->i,i);
    strcpy(novo->x1,x1);
    strcpy(novo->y1,y1);
    strcpy(novo->x2,x2);
    strcpy(novo->y2,y2);
    strcpy(novo->cor,cor);
    strcpy(novo->rota,rota);
    
    if(novo != NULL){
    return novo;
    }
    else
    {
        return 0;
    }
}

void* cria_texto (char i[],char x[],char y[],char corb[], char corp[],char txto[],char rota[]){

    Text* novo = malloc (sizeof(Text));
    strcpy(novo->i,i);
    strcpy(novo->x,x);
    strcpy(novo->y,y);
    strcpy(novo->corb,corb);
    strcpy(novo->corp,corp);
    strcpy(novo->txto,txto);
    strcpy(novo->rota,rota);
    
    if(novo != NULL){
    return novo;
    }
    else
    {
        return 0;
    }
}

//rotacionar e etc tbm