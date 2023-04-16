#include "arqs/libsgerais.h"
#include "ed/lista.h"
#include "arqs/geo.h"
#include "arqs/svg.h"

#include <string.h>

#define MAX 150

int main(int argc, char *argv[])
{
    // 'Path' //

    // localização dos arquivos que serão lidos
    char *entrada = "./";
    char *nomeGeo = "";
    char *nomeQry = "";
    char *saida = "./"; // localização de onde os arquivos vão ser gerados

    // leitura dos argumentos
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-e") == 0)
        {
            entrada = argv[i + 1];
        }
        else if (strcmp(argv[i], "-f") == 0)
        {
            nomeGeo = argv[i + 1];
        }
        else if (strcmp(argv[i], "-q") == 0)
        {
            nomeQry = argv[i + 1];
        }
        else if (strcmp(argv[i], "-o") == 0)
        {
            saida = argv[i + 1];
        }
    }

    // nomes completos dos arquivos
    char *geo = (char *)malloc((strlen(entrada) + strlen(nomeGeo) + 1) * sizeof(char));
    char *qry = (char *)malloc((strlen(entrada) + strlen(nomeQry) + 1) * sizeof(char));
    char *svg = (char *)malloc((strlen(saida) + strlen(nomeGeo) + strlen(nomeQry) + 10) * sizeof(char));

    // função que 'preparam' a criação do nome
    strcpy(geo, entrada);
    strcpy(qry, entrada);
    strcpy(svg, saida);

    // funções que criam o nome
    strcat(geo, nomeGeo);
    strcat(qry, nomeQry);
    strcat(svg, nomeGeo);
    strcat(svg, "-");
    strcat(svg, nomeQry);
    strcat(svg, ".svg");

    // abrir arquivos
    FILE *arqQry;
    FILE *arqGeo = fopen(geo, "r");
    if (strcmp(nomeQry, "") != 0)
        arqQry = fopen(qry, "r");
    FILE *arqSvg = fopen(svg, "w");

    // ler GEO
    svg_init(arqSvg);
    Lista *listona = createLst(-1);
    dealWithGeo(arqGeo, listona);
    

    fold(listona, escreveSvg, arqSvg);
    fprintf(arqSvg, "</svg>\n");
    fclose(arqGeo);
    if (strcmp(nomeQry, "") != 0)
        fclose(arqQry);
    fclose(arqSvg);

    free(geo);
}
