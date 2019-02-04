#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>
#include <windows.h>

#define ALTURA 20
#define LARGURA 1500
#define PERSONAGEM 175
#define BARREIRA 178

struct jogador{
	char nome[41];
	char senha[17];
	int score;
};

struct jogador *vj, jog;

int value, p, verif, score, qtd, ind_j = -1;

char **matriz_fase1(int largura, int altura, char barreira, int intervalo);
char **matriz_fase2(int largura, int altura, char barreira, int intervalo);
char **matriz_fase3(int largura, int altura, char barreira, int intervalo);
char **init_mat();
void esp_b();
int draw(int aux, int aux1, char *vet, char **mat);
void scores();
void cad_jog();
void login();
void mov_fase(char *vet, char **mat);
void game();
