
// Mapa - Fase 1

#include <stdio.h>
#include <stdlib.h>

// Define as dimensões do mapa e
// o caracter que representa a barreira
#define LARGURA 1500
#define ALTURA 20
#define BARREIRA 124 // "|"

// Define o intervalo entre
// barras consecutivas
#define BARRA_INTERVALO 30

int main(void) {
	
	FILE *output = fopen("mapa.txt", "w");
	char mapa[ALTURA][LARGURA] = {' '};
	int i, j, barra_altura;
	
	// Inicializa a matriz com es
	for (i = 0; i < LARGURA; i++) {
		
		for (j = 0; j < ALTURA; j++) {
			
			mapa[j][i] = ' ';
		}
	}
	
	// Coloca as barras no mapa
	for (i = BARRA_INTERVALO + 10; i < LARGURA; i += BARRA_INTERVALO) {
		
		// Note que a altura da barreira é relativa
		// a altura do mapa. No mínimo ela vai ocupar
		// 40% da altura total e, no máximo, ocupará
		// 65% (40 + 25). Cuidado ao fazer alterações. 
		barra_altura = ALTURA - (int)(ALTURA * 0.4 + rand() % (int)(ALTURA * 0.25 + 1));
		
		for (j = ALTURA - 1; j >= barra_altura; j--) {
			
			mapa[j][i] = (char)BARREIRA;
		}
	}
	
	// Coloca os dados da matriz no arquivo
	for (i = 0; i < ALTURA; i++) {
		
		for (j = 0; j < LARGURA; j++) {
			
			fputc(mapa[i][j], output);
		}
		
		fputc('\n', output);
	}
	
	return (0);
}
