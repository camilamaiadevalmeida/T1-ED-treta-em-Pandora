#include"main.h"
#include "svg.h"
#include "../objetos/formas.h"
#include "../ed/lista.h"



struct retangulo
{
    char i[20];
    char x[20];
    char y[20];
    char w[20];
    char h[20];
    char corb[20];
    char corp[20];
    char rota[20];
}Rect;

struct circulo
{
    char i[20];
    char x[20];
    char y[20];
    char r[20];
    char corb[20];
    char corp[20];
    char rota[20];
}Circ;

struct linha
{
    char i[20];
    char x1[20];
    char y1[20];
    char x2[20];
    char y2[20];
    char cor[20];
    char rota[20];
}Linha;

struct texto
{
    char i[20];
    char x[20];
    char y[20];
    char corb[20];
    char corp[20];
    char rota[20];
    char texto[20];
    //estilo
}Text;

//Definição do tipo de lista//////////////////////////////////////////loucuraassssssss
struct formato{
    Rect retangulo;
    Circ circulo;
    Linha linha;
    Text texto;

    char tipo_forma[20];
    struct formato *prox;
};

FILE* cria_path_SVG_geo (void* parametros){

};

void desenhaitemSVG (Lista* lst, FILE* file){
    if(lst == NULL)
        return;
    //elem* elem = *lst;
    Item* item = *lst;
    
    //na real nao sei se faz sentido lst aqui no while...porque eu quero entrar em cada no ne

    while(lst != NULL){
        if(strcmp(formato->tipo_forma,"r")==0){
        
            fprintf(file,"<rect width=\"%s\" height=\"%s\" x=\"%s\" y=\"%s\" stroke=\"%s\" stroke-width=\"1.0\" fill=\"%s\" fill-opacity = \"0.8\" stroke-opacity = \"0.8\"/>\n", elem->retan.w,elem->retan.h,elem->retan.x,elem->retan.y,elem->retan.corb,elem->retan.corp);

        }else if (strcmp(elem->tipo_forma,"c")==0){

            fprintf(file,"<circle cx=\"%s\" cy=\"%s\" r=\"%s\" stroke=\"%s\" stroke-width=\"1.0\" fill=\"%s\" fill-opacity =  \"0.8\" stroke-opacity = \"0.8\"/>\n",elem->circulo.x,elem->circulo.y,elem->circulo.r,elem->circulo.corb,elem->circulo.corp);
        
        }else if (strcmp(elem->tipo_forma,"t")==0){

            fprintf (file,"<text x=\"%s\" y=\"%s\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\" > %s </text> ->\n",elem->texto.x,elem->texto.y,elem->texto.corb,elem->texto.corp,elem->texto.txto);
        }else if (strcmp(elem->tipo_forma,"l")==0){

        fprintf ( file,"<line x1=\"%s\" y1=\"%s\" x2=\"%s\" y2=\"%s\" stroke=\"%s\" stroke-width=\"1.0\"/>\n",elem->linha.x1,elem->linha.y1,elem->linha.x2,elem->linha.y2,elem->linha.cor);

        }

        elem = elem->prox;
    }

    fprintf(file,"</svg>");
};

