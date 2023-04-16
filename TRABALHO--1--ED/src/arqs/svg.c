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
    fprintf(file, "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n");
    fprintf(file, "<svg xmlns=\"http://www.w3.org/2000/svg\">\n");
    switch (get_tipo(item)[0])
    {
    case 'c':
         fprintf(file, "<circle cx=\"%s\" cy=\"%s\" r=\"%s\" fill=\"%s\" />\n", get_x(item), get_y(item), get_r(item), get_corp(item));
        break;
    case 'r':
         fprintf(file, "<rect x=\"%s\" y=\"%s\" width=\"%s\" height=\"%s\" fill=\"%s\" />\n", get_x(item), get_y(item), get_w(item), get_h(item), get_corp(item));
        break;
    case 't':
         fprintf(file, "<text x=\"%s\" y=\"%s\" fill=\"%s\" />\n", get_x(item), get_y(item), get_corp(item));
        break;
    case 'l':

         fprintf(file, "<line x1=\"%s\" y1=\"%s\" x2=\"%s\" y2=\"%s\" stroke=\"%s\" />\n", get_x(item), get_y(item), get_w(item), get_h(item), get_corp(item));
        break;
    }
    fprintf(file, "</svg>\n");
}
