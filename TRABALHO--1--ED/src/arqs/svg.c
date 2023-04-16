#include "libsgerais.h"
#include "svg.h"
#include "../objetos/formas.h"
#include "../ed/lista.h"

void svg_init(FILE *svg)
{
    fprintf(svg, "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n");
    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\">\n");
}

void svg_finalize(FILE *svg)
{
    fprintf(svg, "</svg>\n");
}

struct clausuraSvg
{
    FILE *svg; // arquivo svg
};

void escreveSvg(Item item, Clausura c)
{
    FILE *file = c;

    switch (get_tipo(item)[0])
    {
    case 'c':
        fprintf(file, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"%s\" stroke=\"%s\" />\n",
                atof(get_x(item)), atof(get_y(item)), atof(get_r(item)), get_corp(item), get_corb(item));
        break;
    case 'r':
        fprintf(file, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"%s\" stroke=\"%s\" transform=\"rotate(%f %d %d)\" \n",
                atof(get_x(item)), atof(get_y(item)), atof(get_w(item)), atof(get_h(item)), get_corp(item), get_corb(item), atof(get_rota(item)), atof(get_x(item)), atof(get_y(item)));
        break;
    case 't':
        fprintf(file, "<text x=\"%d\" y=\"%d\" fill=\"%s\" stroke=\"%s\" font-size=\"%s\" font-family=\"%s\" font-weight=\"%s\" transform=\"rotate(%f %d %d)\" text-anchor=\"%s\">%s</text>\n",
                atof(get_x(item)), atof(get_y(item)), get_corp(item), get_corb(item), get_tamanho(item), get_familia(item), get_peso(item), atof(get_rota(item)), atof(get_x(item)), atof(get_y(item)), get_ancora(item), get_txto(item));
        break;
    case 'l':
        fprintf(file, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\" transform=\"rotate(%f %d %d)\" />\n",
                atof(get_x(item)), atof(get_y(item)), atof(get_x2(item)), atof(get_y2(item)), get_corb(item), atof(get_rota(item)), atof(get_x(item)), atof(get_y(item)));
        break;
    }
}
