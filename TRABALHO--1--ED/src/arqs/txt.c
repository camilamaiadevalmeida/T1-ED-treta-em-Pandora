#include "txt.h"

void reportarCirculo(void *forma, FILE *txt)
{
    fprintf(txt, "Círculo %s de raio %s em (%s, %s) com borda de cor %s, preenchimento de cor %s com rotação de %s\n",
            get_id(forma),
            get_r(forma),
            get_x(forma),
            get_y(forma),
            get_corb(forma),
            get_corp(forma),
            get_rota(forma));
}

void reportarRetangulo(void *forma, FILE *txt)
{
    fprintf(txt, "Retângulo %s de largura %s e altura %s em (%s, %s) com borda de cor %s, preenchimento de cor %s com rotação de %s\n",
            get_id(forma),
            get_w(forma),
            get_h(forma),
            get_x(forma),
            get_y(forma),
            get_corb(forma),
            get_corp(forma),
            get_rota(forma));
}

void reportarLinha(void *forma, FILE *txt)
{
    fprintf(txt, "Linha %s (%s, %s) -> (%s, %s) com borda de cor %s e rotação de %s\n",
            get_id(forma),
            get_x(forma),
            get_y(forma),
            get_x2(forma),
            get_y2(forma),
            get_corb(forma),
            get_rota(forma));
}

void reportarBalao(void *forma, FILE *txt)
{
    Fila filaAtual;
    for (int i = 0; i < 10; i++)
    {
        filaAtual = get_fila(forma, i);
        if (filaAtual != NULL)
        {
            fprintf(txt, "Fila %d - %d fotos\n", i, getQtdFila(filaAtual));
        }
    }
    fprintf(txt, "Atributos da câmera:\nR: %s\nP: %s\nH: %s\n",
            get_r(forma),
            get_p(forma),
            get_h(forma));
}

void reportarCaca(void *forma, FILE *txt)
{
    fprintf(txt, "Disparou %d vezes, formas atingidas:\n", get_disparos(forma));
    for (int i = 0; i < get_tamanhoAtual(forma); i++)
    {
        fprintf(txt, "%d ", get_alvosAcertados(forma)[i]);
    }

    fprintf(txt, "\n");
}

void reportarTexto(void *forma, FILE *txt)
{
    fprintf(txt, "Texto %s \"%s\" em (%s, %s) com borda de cor %s, preenchimento de cor %s, rotação de %s\n\
    Fonte: %s\nTamanho: %s\nPeso: %s\nAlinhamento: %s\n",
            get_id(forma),
            get_txto(forma),
            get_x(forma),
            get_y(forma),
            get_corb(forma),
            get_corp(forma),
            get_rota(forma),
            get_familia(forma),
            get_tamanho(forma),
            get_peso(forma),
            get_ancora(forma));
}

void reportarAtributos(Item item, Clausura c)
{
    FILE *txt = (FILE *)c;

    switch (get_tipo(item)[0])
    {
    case 'c':
        reportarCirculo(item, txt);
        break;
    case 'r':
        reportarRetangulo(item, txt);
        break;
    case 'l':
        reportarLinha(item, txt);
        break;
    case 't':
        reportarTexto(item, txt);
        break;
    case 'b':
        reportarTexto(item, txt);
        reportarBalao(item, txt);
        break;
    case 'a':
        reportarTexto(item, txt);
        reportarCaca(item, txt);
        break;
    }
}
