#include"main.h"
#include "svg.h"
#include "../objetos/formas.h"
#include "../ed/lista.h"





//FILE* cria_path_SVG_geo (void* parametros){}

/*void desenhaitemSVG (Lista* lst, FILE* file){
    if(lst == NULL)
        return;
    //elem* elem = *lst;
    Item* item = *lst;
    
    //na real nao sei se faz sentido lst aqui no while...porque eu quero entrar em cada no ne

    //função que escreve no svg so o atual ne
    //botando aquele formato de fold
    */

void desenhaItemFoldSVG (Lista lst, ApplyClosure f, Clausura c)
{
    Iterador it = createIterador(lst, false);

    while (!isIteratorEmpty(it))
    {
        Item info = getIteratorNext(it);
        f(info, c);
        switch (tipo)
        {
        case 'r':
            fprintf(file,"<rect width=\"%s\" height=\"%s\" x=\"%s\" y=\"%s\" stroke=\"%s\" stroke-width=\"1.0\" fill=\"%s\" fill-opacity = \"0.8\" stroke-opacity = \"0.8\"/>\n", elem->retan.w,elem->retan.h,elem->retan.x,elem->retan.y,elem->retan.corb,elem->retan.corp);
            break;

        case 'c':
            fprintf(file,"<circle cx=\"%s\" cy=\"%s\" r=\"%s\" stroke=\"%s\" stroke-width=\"1.0\" fill=\"%s\" fill-opacity =  \"0.8\" stroke-opacity = \"0.8\"/>\n",elem->circulo.x,elem->circulo.y,elem->circulo.r,elem->circulo.corb,elem->circulo.corp);
            break;

        case 'l':
            fprintf(file,"<line x1=\"%s\" y1=\"%s\" x2=\"%s\" y2=\"%s\" stroke=\"%s\" stroke-width=\"1.0\" fill-opacity = \"0.8\" stroke-opacity = \"0.8\"/>\n",elem->linha.x1,elem->linha.y1,elem->linha.x2,elem->linha.y2,elem->linha.cor);
            break;

        case 't':
            fprintf(file,"<text x=\"%s\" y=\"%s\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1.0\" fill-opacity = \"0.8\" stroke-opacity = \"0.8\" transform=\"rotate(%s)\">%s</text>\n",elem->texto.x,elem->texto.y,elem->texto.corp,elem->texto.corb,elem->texto.rota,elem->texto.texto);
            break;
        }
    }
    killIterator(it);
}

/*

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

*/

