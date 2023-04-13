#include "leitura.h"
#include "main.h"
#include "headers.h"

#define MAX 100

void lerLinha(FILE *arq, char *palavras[], int *n)
{
	char linha[MAX];
	char *token;
	const char *delim = " \t\n";
	int i = 0;
	*n = i;
	// lê uma linha do arquivo
	if (fgets(linha, MAX, arq) != NULL)
	{
		// separa a primeira palavra da linha
		token = strtok(linha, delim);
		// enquanto houver palavras na linha
		while (token != NULL)
		{
			// aloca memória para armazenar a palavra
			palavras[i] = (char *)malloc(strlen(token) + 1);
			// copia a palavra para a variável
			strcpy(palavras[i], token);
			// incrementa o contador de palavras
			i++;
			// separa a próxima palavra da linha
			token = strtok(NULL, delim);
		}
		// atualiza o número de palavras na linha
		*n = i;
	}
	else
	{
		// atualiza o número de palavras na linha
		*n = 0;
	}
}
