#include "bomba.h"
#include <math.h>


#include "../ed/lista.h"
#include "../ed/fila.h"
#include "../objetos/formas.h"
#include "foto.h"

struct circClos
{
    char x[50];
    char y[50];
    char r[50];
};

struct bombClos
{
    Lista db;
};

struct cloneClos
{
    FILE *txt;
    Lista db;
    Lista atingidos;
    double dx;
    double x, y, r; // coordenadas do centro da bomba e raio
    int j;
};

//Closure pra lidar com as posições x,y relativas ao movimentar a foto-figura. 
struct relativeClos
{
    double dx;
    double xOffset, yOffset; // como as coordenadas das fotos são relativas ao balão, é necessário guardar as coordenadas do balão
    int j;
};

struct clausuraX
{
    FILE *svg;
};

//O objetivo da função checkInLista é criar e retornar uma nova lista contendo todas 
//as formas que se encontram dentro do raio especificado
Lista checkInLista(Lista db, double xbomba, double ybomba, double raio)
{
    Lista lista = createLst(-1);
    Iterador it = createIterador(db, false);
    //circClos c = criacircClos(xbomba, ybomba, raio);
    Posic posic;
    while (isIteratorEmpty(it) == false)
    {
        posic = getIteratorNextPosic(it);
        if (posic == NULL)
            break;
        void *forma = getIteratorNext(it);
        if (strcmp(get_tipo(forma), "c") == 0)
        {
            double xcaca = atof(get_x(forma));
            double ycaca = atof(get_y(forma));
            double rcaca = atof(get_r(forma));
            double distancia = sqrt(pow(xcaca - xbomba, 2) + pow(ycaca - ybomba, 2));
            if (distancia <= raio + rcaca)
            {
                insertLst(lista, forma);
            }
        }
    }
}

// A função abaixo  é do tipo fold e é responsável por remover um item específico de uma lista dentro de uma closure
void intersecOff(Item item, Clausura c)
{
    struct bombClos *cb = (struct bombClos *)c;
    Lista db = cb->db;
    removeLst(db, item);
}

// função map que faz uma lista com os ids das formas atingidas
// item é o endereço Posic da forma
// c não é usado
Item getIds(Item item, Clausura c)
{
    Posic posic = (Posic)item;
    Item forma = getLst(posic);
    if (c != NULL)
    {
    } 
    int *id = malloc(sizeof(int));
    char* tipo = get_tipo(forma);
    if (strcmp(tipo, "c") == 0) 
    {
        *id = get_id(forma);
    // código para tipo1
    } else if (strcmp(tipo, "r") == 0) 
    {
        *id = get_id(forma);
    // código para tipo2
    } 
    else if (strcmp(tipo, "t") == 0) 
    {
        *id = get_id(forma);
    // código para tipo3
    } 
    else if (strcmp(tipo, "l" ) == 0)
    {
        *id = get_id(forma);
    }   
}

//
Item deslocaXchangeColor(Item item, Clausura c) {
    struct relativeClos *ci = (struct relativeClos *)c;
    double dx = ci->dx;
    int *j = &ci->j;
    *j += 1;
    char* tipo = get_tipo(item);
    Item forma = NULL;
    if (strcmp(tipo, "c") == 0) {
        forma = cria_circulo(*j - 1, get_i(item), get_r(item), (int)(get_x(item) + (int)dx + (int)ci->xOffset), (int)(get_y(item) + (int)ci->yOffset), get_corb(item), get_corp(item));
        set_rota(forma, get_rota(item));
    } else if (strcmp(tipo, "r") == 0) {
        forma = cria_retangulo(*j - 1, get_i(item), get_w(item), get_h(item), (int)(get_x(item) + (int)dx + (int)ci->xOffset), (int)(get_y(item) + (int)ci->yOffset), get_corb(item), get_corp(item));
        set_rota(forma, get_rota(item));
    }
    else if (strcmp(tipo, "t") == 0) {
        forma = cria_texto(*j - 1, get_i(item), get_x(item) + (int)dx + (int)ci->xOffset, get_y(item) + (int)ci->yOffset, get_corb(item), get_corp(item), get_texto(item), get_familia(item), get_tamanho(item), get_peso(item), get_ancora(item));
        set_rota(forma, get_rota(item));
    }
    else if (strcmp(tipo, "l") == 0) {
        forma = cria_linha(*j - 1, get_i(item), get_x(item) + (int)dx + (int)ci->xOffset, get_y(item) + (int)ci->yOffset, get_x2(item) + (int)dx + (int)ci->xOffset, get_y2(item) + (int)ci->yOffset, get_corb(item));
        set_rota(forma, get_rota(item));
    }
    return forma;
}

//deixar essa função e a próxima para depois...e continuar :)
//continuei [check]

//depende muitinho de foto :)
void clonarOQsobrou(Item item, Clausura c)
{
    struct reverseClos
    {
        double dx;
        double xbalao, ybalao;
        int j;
    };
    struct cloneClos *cl = (struct cloneClos *)c;
    Lista db = cl->db;
    Lista atingidos = cl->atingidos;
    struct reverseClos ci;
    ci.dx = cl->dx;
    ci.j = cl->j;
    Fila filaBalao;
    Foto elementoInicial, elementoAtual;
    Lista elementosFoto, clonados, clonadosEnderecos;
    void* Forma balao = getLst(item);
    if (get_tipo(item)[0] == 'b')
    {
        // percorre as filas do balão atual
        for (int filaAtual = 0; filaAtual < 10; filaAtual++)
        {
            filaBalao = getBalaoFilaI(balaoAtual, filaAtual);
            if (isVaziaFila(filaBalao))
                continue;
            elementoInicial = getInicioFila(filaBalao);
            elementoAtual = elementoInicial;
            {
                elementosFoto = getElementosFoto(elementoAtual);
                if (elementosFoto != NULL)
                {
                    ci.xOffset = getXOffsetFoto(elementoAtual);
                    ci.yOffset = getYOffsetFoto(elementoAtual);
                    clonados = map(elementosFoto, deslocaInverte, &ci);
                    fold(clonados, reportarAtributosFold, cl->txt);
                    insertPosicLst(db, getFirstLst(clonados), clonados);
                }
                removeFila(filaBalao);
                insereFila(filaBalao, elementoInicial);
                elementoAtual = getInicioFila(filaBalao);
            } while (elementoAtual != elementoInicial);
        }
    }

}

void bombaPosic(double xcaca, double ycaca, double rotacao, double distancia,
                  double *xbomba, double *ybomba)
{
    const int PI = 3.142; //add aqui, é um probleminha?????
    double radianos = ((rotacao + 90) * PI /180);
    *xbomba = xcaca + distancia * cos(radianos);
    *ybomba = ycaca + distancia * sin(radianos);
}
    
void xVermelhoAncoras(Item item, Clausura c)
{
    struct clausuraX *cl = (struct clausuraX *)c;
    Item forma = getLst(item);
    double x, y;
    FILE *svg = cl->svg;
    switch (get_tipo(item)[0])
    {
    case 'r':
        x = (int)atof(get_x(item));
        y = (int)atof(get_y(item));
        break;
    case 'c':
        x = (int)atof(get_x(item));
        y = (int)atof(get_y(item));
        break;
    case 't':
        x = (int)atof(get_x(item));
        y = (int)atof(get_y(item));
        break;
    case 'l':
        x = (int)atof(get_x(item));
        y = (int)atof(get_y(item));
    }
    svg_text(svg, x, y, "X", "#FF0000", "#FF0000", 0, "sans (sans-serif)", "normal", "20px", "middle", NULL);
    if (get_tipo(item)[0] == 'l')
    {
        x = (int)atof(get_x2(item));
        y = (int)atof(get_y2(item)); 
        svg_text(svg, x, y, "X", "#FF0000", "#FF0000", 0, "sans (sans-serif)", "normal", "20px", "middle", NULL);
    }
}

void explodeBomba(Lista db, double xbomba, double ybomba, enum bombaTipo, double dx, void* formato, int j, FILE *txt, FILE *svg)
{
    

}

//fazer aquilo do formas.h com o void e etc [check]


