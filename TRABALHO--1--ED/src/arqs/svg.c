#include "main.h"
#include "svg.h"
#include "../objetos/formas.h"
#include "../ed/lista.h"

void svg_init(FILE *svg){
    fprintf(svg, "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n");
    fprintf(svg, "<svg xmlns=\"http://www.w3.org/2000/svg\">\n");
}

void svg_finalize(FILE *svg){
    fprintf(svg, "</svg>\n");
}

void svg_close (FILE* file){
    fclose(file);
}

struct clausuraSvg
{
    FILE *svg; // arquivo svg
};

ClausuraSvg criaClausuraSvg(FILE *svg)
{
    struct clausuraSvg *c = malloc(sizeof(struct clausuraSvg));
    c->svg = svg;
    return c;
}

void escreveSvg(Item item, Clausura c)
{
    enum TipoForma tipo = get_tipo(item);
    FILE* file = fopen(file, "w");
    fprintf(file, "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n");
    fprintf(file, "<svg xmlns=\"http://www.w3.org/2000/svg\">\n");
    switch (get_tipo(((struct clausuraSvg *)c)->svg))
    {
    case CIRCULO:
        (((struct clausuraSvg *)c)->svg,
                fprintf(file, "<circle cx=\"%s\" cy=\"%s\" r=\"%s\" fill=\"%s\" />\n", get_x(item), get_y(item), get_r(item), get_corp(item)));
        break;
    case RETANGULO:
        (((struct clausuraSvg *)c)->svg,
                 fprintf(file, "<rect x=\"%s\" y=\"%s\" width=\"%s\" height=\"%s\" fill=\"%s\" />\n", get_x(item), get_y(item), get_w(item), get_h(item), get_corp(item)));
        break;
    case TEXTO:
        (((struct clausuraSvg *)c)->svg,
                fprintf(file, "<text x=\"%s\" y=\"%s\" fill=\"%s\" />\n", get_x(item), get_y(item), get_corp(item)));
        break;
    case LINHA:
        (((struct clausuraSvg *)c)->svg,
                fprintf(file, "<line x1=\"%s\" y1=\"%s\" x2=\"%s\" y2=\"%s\" stroke=\"%s\" />\n", get_x(item), get_y(item), get_w(item), get_h(item), get_corp(item)));
        break;
    }
    fprintf(file, "</svg>\n");
    fclose(file);
}

//ler filnm como closure e la dentro tirar roupa dele pra

/*void desenhaItemSVG(Item item, void* closure, const char* filename) {
    FILE* file = fopen(filename, "w");
    fprintf(file, "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n");
    fprintf(file, "<svg xmlns=\"http://www.w3.org/2000/svg\">\n");
    switch (get_tipo(item)) {
        case RETANGULO:
            fprintf(file, "<rect x=\"%s\" y=\"%s\" width=\"%s\" height=\"%s\" fill=\"%s\" />\n", 
                get_x(item), get_y(item), get_w(item), get_h(item), get_corp(item));
            break;
        case CIRCULO:
            fprintf(file, "<circle cx=\"%s\" cy=\"%s\" r=\"%s\" fill=\"%s\" />\n", 
                get_x(item), get_y(item), get_r(item), get_corp(item));
            break;
        case TEXTO:
            fprintf(file, "<text x=\"%s\" y=\"%s\" fill=\"%s\" />\n", 
                get_x(item), get_y(item), get_corp(item));
            break;
        case LINHA:
            fprintf(file, "<line x1=\"%s\" y1=\"%s\" x2=\"%s\" y2=\"%s\" stroke=\"%s\" />\n", 
                get_x(item), get_y(item), get_w(item), get_h(item), get_corp(item));
            break;
    }
    fprintf(file, "</svg>\n");
    fclose(file);
}
*/