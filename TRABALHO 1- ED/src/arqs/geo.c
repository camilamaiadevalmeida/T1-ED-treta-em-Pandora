#include "geo.h"
#include"../ed/lista.h"
#include"path.h"
#include"../objetos/figuras.h"
#include"../objetos/retangulo.h"
#include"../objetos/circulo.h"
#include"../objetos/linha.h"
#include"../objetos/texto.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX 100


/*Implementação de funções utilizadas para interpretar arquivos .GEO 
e inserir informações das descrições das figuras presentes neste em
uma lista duplamente encadeada.
Existem duas funções que operam esta ação, sendo estas: lerGline e
lerGeo.
*/

//Função que lê uma linha do arquivo .GEO e separa a primeira letra
//da string, que pode ser 'c', 'r', 'l' ou 't' e define o tipo da figura.
// O resto da string é a descrição da figura. Isto é: suas dimensões seguidas
// das cores de borda e preenchimento.

/* A função lerGline opera, basicamente, tokenizando as linhas.
*/
void lerGline(FILE *arq, char *figureDescription[], int *n)
{
    char Gline[MAX];
    char *token;
    const char *limit= " \t\n";
    int i = 0;
    *n = i;
    // leitura de uma linha
    // nesse caso, o primeiro parÂmetro deve ser a string que desejo ler,
    // o segundo deve ser o tamanho máximo de tal string e o terceiro deve
    // ser um ponteiro para o arquivo que desejo ler.
    if (fgets(Gline, MAX, arq) != NULL)
    {
        // separa o primeiro token da linha (que deve indicar o tipo de figura)
        token = strtok(Gline, limit);
        // enquanto houver tokens na linha
        while (token != NULL)
        {
            // armazena o token na posição i do vetor figureDescription
            figureDescription[i] = (char *)malloc(strlen(token) + 1);
            // copia o token para a variável
            strcpy(figureDescription[i], token);
            // incrementa para o próximo token
            i++;
            // separa o próximo token de Gline (observe o uso de ptr como parâmetro!)
            token = strtok(NULL, limit);
        }
        // armazena o número atual de tokens na variável n
        *n = i;
    }
    else
    {
        // se não houver mais tokens no arquivo, armazena 0 em n
        *n = 0;
    }

}

/*Agora que eu já posso ler uma linha e tokenizá-la, posso ler 
todo o arquivo através de uma estrutura de repetição.
Assim, essa função opera lendo uma linha atrás da outra até o final
e, a cada leitura, identificando o primeiro token e determinando de 
que tipo de figura se trata. Depois, ela chama a função que insere
a figura na lista duplamente encadeada.
*/
void lerGeo(FILE *geo, Lista *lista)
{
    char *figureDescription[MAX];
    //variaveis para estilizar texto//
    int n;

    char **ptr = NULL;
    //char **n = ptr;
    //char vetortexto[MAX]//

    // Estrutura de repetição para ler as linhas do arquivo em sequência até o seu final.
    while(true)
    {
        // Lê uma linha do arquivo .GEO
        //esse ponteiro aqui tá sendo uma questão!!!
        lerGline(geo, figureDescription, &n);
        if (n > 0)
        {
            // Se a primeira letra da linha for 'c', chama a função que insere um círculo na lista
            if (strcmp(figureDescription[0], "c") == 0)
            {
                
                //double i = strtod(figureDescription[1], ptr);
                double x = strtod(figureDescription[2], ptr);
                double y = strtod(figureDescription[3], ptr);
                double raio = strtod(figureDescription[4], ptr);
                double corb = strtod(figureDescription[5], ptr);
                double corp = strtod(figureDescription[6], ptr);

                Circulo c = criaFigura(atoi(figureDescription[1]), x, y, raio, corb, corp);
                insertLst(lista, c);
            }

            // Se a primeira letra da linha for 'r', chama a função que insere um retângulo na lista
            else if (strcmp(figureDescription[0], "r") == 0)
            {
                double x = strtod(figureDescription[2], ptr);
                double y = strtod(figureDescription[3], ptr);
                double w = strtod(figureDescription[4], ptr);
                double h = strtod(figureDescription[5], ptr);
                double corb = strtod(figureDescription[6], ptr);
                double corp = strtod(figureDescription[7], ptr);

                Retangulo r = criaFigura(atoi(figureDescription[1]), x, y, w, h, corb, corp);
                insertLst(lista, r);
            }

            // Se a primeira letra da linha for 'l', chama a função que insere uma linha na lista
            else if (strcmp(figureDescription[0], "l") == 0)
            {
                double x1 = strtod(figureDescription[2], ptr);
                double y1 = strtod(figureDescription[3], ptr);
                double x2 = strtod(figureDescription[4], ptr);
                double y2 = strtod(figureDescription[5], ptr);
                double corb = strtod(figureDescription[6], ptr);

                Linha l = criaFigura(atoi(figureDescription[1]), x1, x2, y1, y2, corb);
                insertLst(lista, l);
            }

            // Se a primeira letra da linha for 't', chama a função que insere um texto na lista
            else if (strcmp(figureDescription[0], "t") == 0)
            {
                double x = strtod(figureDescription[2], ptr);
                double y = strtod(figureDescription[3], ptr);
                double corb = strtod(figureDescription[4], ptr);
                double corp = strtod(figureDescription[5], ptr);
                char *texto = figureDescription[6];

                Texto t = criaFigura(atoi(figureDescription[1]), x, y, corb, corp, *texto);
                insertLst(lista, t);
            }
        else
        {
            break;
        }
        }
    }
}

/* Os parâmetros tem que combinar com a ordem das variáveis? Não sei explicar isso direito..
*/






