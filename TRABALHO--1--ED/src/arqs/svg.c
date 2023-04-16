#include "libsgerais.h"
#include "svg.h"
#include "../objetos/formas.h"
#include "../ed/lista.h"

void svg_init(FILE *svg)
{
    fprintf(svg, "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n");
    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\">\n");
}


struct clausuraSvg
{
    FILE *svg; // arquivo svg
};

void escreveSvg(Item item, Clausura c)
{
    FILE *file = c;
    int x, y, w, h, r, x1, y1, x2, y2;
    switch (get_tipo(item)[0])
    {
    case 'c':
        x = (int)atof(get_x(item));
        y = (int)atof(get_y(item));
        r = (int)atof(get_r(item));
        fprintf(file, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"%s\" stroke=\"%s\" />\n",
                x, y, r, get_corp(item), get_corb(item));
        break;
    case 'r':
        x = (int)atof(get_x(item));
        y = (int)atof(get_y(item));
        w = (int)atof(get_w(item));
        h = (int)atof(get_h(item));
        fprintf(file, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"%s\" stroke=\"%s\" transform=\"rotate(%f %d %d)\" />\n", 
                x, y, w, h, get_corp(item), get_corb(item), atof(get_rota(item)), x, y);
        break;
    case 't':
        x = (int)atof(get_x(item));
        y = (int)atof(get_y(item));
        fprintf(file, "<text x=\"%d\" y=\"%d\" fill=\"%s\" stroke=\"%s\" font-size=\"%s\" font-family=\"%s\" font-weight=\"%s\" transform=\"rotate(%f %d %d)\" text-anchor=\"%s\">%s</text>\n",
                x, y, get_corp(item), get_corb(item), get_tamanho(item), get_familia(item), get_peso(item), atof(get_rota(item)), (int)atof(get_x(item)), (int)atof(get_y(item)), get_ancora(item), get_txto(item));
        break;
    case 'l':
        x1 = (int)atof(get_x(item));
        y1 = (int)atof(get_y(item));
        x2 = (int)atof(get_x2(item));
        y2 = (int)atof(get_y2(item));
        fprintf(file, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\" transform=\"rotate(%f %d %d)\" />\n",
                x1, y1, x2, y2, get_corb(item), atof(get_rota(item)), x, y);
        break;
    }
}
