#ifndef FORMAS_H
#define FORMAS_H

#include "../arqs/main.h"

enum TipoForma {CIRCULO, RETANGULO, TEXTO, LINHA};

void *cria_retangulo(char i[], char tipo[], char w[], char h[], char x[], char y[], char corb[], char corp[]);
void *cria_circulo(char i[], char tipo[], char r[], char x[], char y[], char corb[], char corp[]);
void *cria_linha(char i[], char tipo[], char x[], char y[], char x2[], char y2[], char cor[]);
void *cria_texto(char i[], char tipo[], char x[], char y[], char corb[], char corp[], char txto[], char familia[], char tamanho[], char peso[], char ancora[]);

// tipo:

//Eu tinha que mudar, né?


char get_tipo();

void set_tipo();

// Funções de set:

// função que seta o id para qualquer tipo de formato
void set_id(void *formato, char id[]);

// função que seta o x para qualquer tipo de formato
void set_x(void *formato, char x[]);

// função que seta o y para qualquer tipo de formato
void set_y(void *formato, char y[]);

// função que seta a cor de borda para qualquer tipo de formato
void set_corb(void *formato, char corb[]);

// função que seta a cor de preenchimento para qualquer tipo de formato
void set_corp(void *formato, char corp[]);

// função que seta a rotação para qualquer tipo de formato
void set_rota(void *formato, char rota[]);

// função que seta a largura para retangulo;
void set_w(void *formato, char w[]);

// função que seta a altura para retangulo;
void set_h(void *formato, char h[]);

// função que seta o raio para circulo;
void set_r(void *formato, char r[]);

// função que seta o x2 para linha
void set_x2(void *formato, char x2[]);

// função que seta o y2 para linha
void set_y2(void *formato, char y2[]);

// função que seta o texto para texto
void set_txto(void *formato, char txto[]);

// função que seta a familia para texto
void set_familia(void *formato, char familia[]);

// função que seta o tamanho para texto
void set_tamanho(void *formato, char tamanho[]);

// função que seta o peso para texto
void set_peso(void *formato, char peso[]);

// função que seta a ancora para texto
void set_ancora(void *formato, char ancora[]);


// Funções de get:

// função que retorna o id da forma
char *get_id(void *formato);


// função que retorna o x para qualquer tipo de formato
char *get_x(void *formato);

// função que retorna o y para qualquer tipo de formato
char *get_y(void *formato);

// função que retorna a cor de borda para qualquer tipo de formato
char *get_corb(void *formato);

// função que retorna a cor de preenchimento para qualquer tipo de formato
char *get_corp(void *formato);

// função que retorna a rotação para qualquer tipo de formato
char *get_rota(void *formato);

// função que retorna a largura para retangulo
char *get_w(void *formato);

// função que retorna a altura para retangulo
char *get_h(void *formato);

// função que retorna o raio para circulo
char *get_r(void *formato);

// função que retorna o x2 para linha
char *get_x2(void *formato);

// função que retorna o y2 para linha
char *get_y2(void *formato);

// função que retorna o texto para texto
char *get_txto(void *formato);

// função que retorna a familia para texto
char *get_familia(void *formato);

// função que retorna o tamanho para texto
char *get_tamanho(void *formato);

// função que retorna o peso para texto
char *get_peso(void *formato);

// função que retorna a ancora para texto
char *get_ancora(void *formato);

void killForma(void *formato);

#endif