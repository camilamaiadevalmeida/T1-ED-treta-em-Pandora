#include "svg.h"
#include <stdio.h>
#include <stdlib.h>

//#include <conio.h>
//#include <graphics.h>


//Esta é a implementação do arquivo svg.h: 


void initSvg(FILE *svg, int w, int h)
{
    fprintf(svg, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    fprintf(svg, "<svg width=\"%d\" height=\"%d\" xmlns=\"http://www.w3.org/2000/svg\">\n");
}

void endSvg(FILE *svg)
{
    fprintf(svg, "</svg>\n");
}

void writeRectSvg(FILE *svg, char *id, int x, int y, int w, int h, char *fill, char *stroke)
{
    fprintf(svg, "\t<rect id=\"%s\" x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%d\" />\n", id, x, y, w, h, fill, stroke);
}

void writeCircleSvg(FILE *svg, char *id, int cx, int cy, int r, char *fill, char *stroke)
{
    fprintf(svg, "\t<circle id=\"%s\" cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%d\" />\n", id, cx, cy, r, fill, stroke);
}

void writeLineSvg(FILE *svg, char *id, int x1, int y1, int x2, int y2, char *fill, char *stroke)
{
    fprintf(svg, "\t<line id=\"%s\" x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\" stroke-width=\"%d\" />\n", id, x1, y1, x2, y2, stroke);
}

void writeTextSvg(FILE *svg, char *id, int x, int y, char *fill, char *stroke, char *text)
{
    fprintf(svg, "\t<text id=\"%s\" x=\"%d\" y=\"%d\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%d\">%s</text>\n", id, x, y, fill, stroke, text);
}


