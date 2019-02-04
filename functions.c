#include "header.h"

char **matriz_fase1(int largura, int altura, char barreira, int intervalo) {

	char **matriz;

	int i, j, barra_altura;

	matriz = (char **)malloc(altura * sizeof(char *));

	for (i = 0; i < altura; i++) {
		matriz[i] = (char *)malloc(largura * sizeof(char));
	}

	srand(time(0));
	for (i = 0; i < altura; i++) {
		for (j = 0; j < largura; j++) {
			matriz[i][j] = ' ';
		}
	}

	for (i = intervalo + 25; i < largura; i += intervalo) {

		barra_altura = ALTURA - (5 + rand() % 11);

		for (j = ALTURA - 1; j >= barra_altura; j--) {
			matriz[j][i] = barreira;
		}
	}

	return (matriz);
}

char **matriz_fase2(int largura, int altura, char barreira, int intervalo) {

	char **matriz;

	int i, j, barra_altura, tipo_barreira;

	matriz = (char **)malloc(altura * sizeof(char *));

	for (i = 0; i < altura; i++) {
		matriz[i] = (char *)malloc(largura * sizeof(char));
	}

	srand(time(0));
	for (i = 0; i < altura; i++) {
		for (j = 0; j < largura; j++) {
			matriz[i][j] = ' ';
		}
	}

	for (i = intervalo; i < largura; i += intervalo) {

		tipo_barreira = rand() % 10;

		if (tipo_barreira < 7){

			barra_altura = ALTURA - (5 + rand() % 11);

			for (j = ALTURA - 1; j >= barra_altura; j--) {
				matriz[j][i] = barreira;
			}
		}

		else {

			barra_altura = 5 + rand() % 11;

			for (j = 0; j <= barra_altura; j++) {
				matriz[j][i] = barreira;
			}
		}
	}

	return (matriz);
}

char **matriz_fase3(int largura, int altura, char barreira, int intervalo) {

	char **matriz;

	int i, j, barra_altura, tipo_barreira;

	matriz = (char **)malloc(altura * sizeof(char *));

	for (i = 0; i < altura; i++) {
		matriz[i] = (char *)malloc(largura * sizeof(char));
	}

	srand(time(0));
	for (i = 0; i < altura; i++) {
		for (j = 0; j < largura; j++) {
			matriz[i][j] = ' ';
		}
	}

	for (i = intervalo; i < largura; i += intervalo) {

		tipo_barreira = rand() % 10;

		if (tipo_barreira < 7) {

			barra_altura = 5 + rand() % 11;

			for (j = 0; j <= barra_altura; j++) {
				matriz[j][i] = barreira;
			}

			for (j += 4 + rand() % 5; j < ALTURA; j++) {
				matriz[j][i] = barreira;
			}
		}

		else if (tipo_barreira < 9){

			barra_altura = ALTURA - (7 + rand() % 10);

			for (j = ALTURA - 1; j >= barra_altura; j--) {
				matriz[j][i] = barreira;
			}
		}

		else {

			barra_altura = 7 + rand() % 10;

			for (j = 0; j <= barra_altura; j++) {
				matriz[j][i] = barreira;
			}
		}
	}

	return (matriz);
}

char **init_mat()
{
    int i, j;
    char **mapa;
    char **fase;

    mapa = (char **)malloc(ALTURA * sizeof(char *));

	for (i = 0; i < ALTURA; i++) {
		mapa[i] = (char *)malloc(LARGURA * 3 * sizeof(char));
	}

	fase = (char **)malloc(ALTURA * sizeof(char *));

	for (i = 0; i < ALTURA; i++) {
		fase[i] = (char *)malloc(LARGURA * sizeof(char));
	}

    fase = matriz_fase1(LARGURA, ALTURA, (char)BARREIRA, 10);

    for (i = 0; i < LARGURA; i++) {

        for (j = 0; j < ALTURA; j++) {

            mapa[j][i] = fase[j][i];
        }
    }

    fase = matriz_fase2(LARGURA, ALTURA, (char)BARREIRA, 14);

    for (; i < LARGURA * 2; i++) {

        for (j = 0; j < ALTURA; j++) {

            mapa[j][i] = fase[j][i - LARGURA];
        }
    }

    fase = matriz_fase3(LARGURA, ALTURA, (char)BARREIRA, 18);

    for (; i < LARGURA * 3; i++) {

        for (j = 0; j < ALTURA; j++) {

            mapa[j][i] = fase[j][i - LARGURA * 2];
        }
    }

    return (mapa);
}

void esp_b()
{
	char bt;
	while(p >= 0 && p != (ALTURA - 1) && verif)
	{
		bt = getch();
		setbuf(stdin, NULL);
		if(bt == 32)
		{
			 value = 1;
		}
		bt = '0';
	}
}

int draw(int aux, int aux1, char *vet, char **mat)
{
	int i, j, cont;
	system("cls");

	printf("SCORE %d\n", score);
	

	if(aux1 % 10 == 0)
	{	
		++score;
	}

	for (i = 0; i < 70; i++) {
        putchar(220);
	}

	printf("\n");

	for(i = 0; i < ALTURA; ++i)
	{
		cont = 5;
		for(j = (aux - 70); j < cont; ++j)
		{
			putchar(mat[i][j]);
		}

		if(vet[i] == (char)PERSONAGEM)
		{
			putchar(vet[i]);
			if(mat[i][j] == (char)178)
			{
				return(0);
			}
		}
		else
		{
			putchar(mat[i][j]);
		}

		for(++j; j < aux; ++j)
		{
			putchar(mat[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < 70; i++) {
        putchar(223);
	}

	return(1);
}

void scores()
{
	int i;

	system("cls");

	printf("\t\t\t\t====================================\n");
	printf("\t\t\t\t-------------- SCORES --------------\n");
	printf("\t\t\t\t====================================\n\n");
	printf("\t\t\t\t--------- ORDEM ALFABETICA ---------\n\n\n");

	printf("\t\t\t\tJOGADOR\t\t\tSCORE\n\n");
	
	for(i = 0; i < qtd; ++i)
	{
		if(i == ind_j)
		{
			printf("\t\t\t\t%s\t\t\t%d\n", jog.nome, jog.score);
		}
		else
		{
			printf("\t\t\t\t%s\t\t\t%d\n", vj[i].nome, vj[i].score); 
		} 
	}
	getchar();
}

void cad_jog()
{
	int i, conf;
	struct jogador j, *aux;	
	
	++qtd;

	aux = (struct jogador *) malloc(qtd * sizeof(struct jogador));

	system("cls");

	do
	{
		conf = 1;
		printf("\t\t\t\t===================================\n");
		printf("\t\t\t\t-----------    CADASTRO -----------\n");
		printf("\t\t\t\t===================================\n\n");
		printf("\t\t\t\t------- Nao utilize espacos -------\n\n\n");
		printf("\t\t\t\tNome: ");
		fgets(j.nome, 41, stdin);
		printf("\t\t\t\tSenha: ");
		fgets(j.senha, 17, stdin);
		
		j.nome[strlen(j.nome)-1] = '\0';
		j.senha[strlen(j.senha)-1] = '\0';

		j.score = 0;

		i = 0;

		while(strcmp(vj[i].nome, j.nome) < 0 && i < qtd && qtd != 1)
		{
			aux[i] = vj[i];
			++i;
		}
	
		if(!strcmp(vj[i].nome, j.nome))
		{
			conf = 0;
			printf("\t\t\tUSUARIO JA EXISTE! TENTE OUTRO NOME DE USUARIO!\n\n");
			getchar();
		}
		else
		{
			aux[i] = j;
			while(i < (qtd - 1) && qtd != 1)
			{
				aux[i+1] = vj[i];
				++i;
			}
		}

	}while(conf != 1);
		
	if(qtd > 1)
	{
		vj = (struct jogador *) realloc(vj, qtd * sizeof(struct jogador));
	}

	for(i = 0; i < qtd; ++i)
	{
		vj[i] = aux[i];
	}

	printf("\t\t\t\tCADASTRO REALIZADO COM SUCESSO!");
	getchar();

	free(aux);		
}

void login()
{
	int i, ver, ini, fim, at, achou;
	char alvo[41], sen[17], resp;
	
	ini = 0;
	at = qtd / 2;
	fim = qtd - 1;
	achou = -1;
	
	
	if(ind_j != -1)
	{
		vj[ind_j].score = jog.score;
	}

	system("cls");
	

	printf("\t\t\t\t===================================\n");
	printf("\t\t\t\t-------------- LOGIN --------------\n");
	printf("\t\t\t\t===================================\n\n\n");
	
	printf("\t\t\t\tNOME: ");
	fgets(alvo, 41, stdin);

	alvo[strlen(alvo)-1] = '\0';

	if(!strcmp(alvo, vj[ini].nome))
	{
		achou = ini;
	}
	else
	{
		if(!strcmp(alvo, vj[fim].nome))
		{
			achou = fim;
		}
		else
		{
			while(achou < 0 && ini != at)
			{
				if(!strcmp(alvo, vj[at].nome))
				{
					achou = at;
				}
				else
				{
					if(strcmp(alvo, vj[at].nome))
					{
						ini = at;
					}
					else
					{
						fim = at;
					}
				}
				at = (ini + at) / 2;
			}
		}
	}

	if(achou < 0)
	{
		printf("\t\t\t\tUSUARIO NAO ENCONTRADO!\n");
		printf("\t\t\t\tFAZER CADASTRO? (s/n)\n");
		resp = getch();
		if(resp == 's')
		{
			cad_jog();
		}
	}
	else
	{
		do
		{
			resp = 0;
			printf("\t\t\t\tSENHA: ");
			fgets(sen, 17, stdin);

			sen[strlen(sen)-1] = '\0';

			if(strcmp(vj[achou].senha, sen))
			{
				printf("\t\t\t\t\n\nSENHA INCORRETA! DIGITE NOVAMENTE!\n\n");
				resp = 1;
			}
		}while(resp);

		jog = vj[achou];
		ind_j = achou;
	}
}

void mov_fase(char *vet, char **mat)
{
	int cont = 100, aux1 = 0, tim = 40;
	_beginthread(esp_b, 0, NULL);
	while(p != (ALTURA - 1) && p >= 0 && verif)
	{
		if(value > 0)
		{
			--(value);
			vet[p] = ' ';
			vet[--p] = (char)PERSONAGEM;
		}
		else
		{
			vet[p] = ' ';
			vet[++p] = (char)PERSONAGEM;
		}

		verif = draw(cont, aux1, vet, mat);
		++cont;
		++aux1;
		if(aux1 == 50 && tim > 14)
		{
			aux1 = 0;
			--tim;
		}
		Sleep(tim);
	}
}

void game()
{
    char **mapa, vet[ALTURA], resp = 's';
    int i, j;

	do
	{
		score = 0;
		value = 0;
    		p = 4;
    		verif = 1;

		mapa = (char **)malloc(ALTURA * sizeof(char *));

		for (i = 0; i < ALTURA; ++i) {
			mapa[i] = (char *)malloc(LARGURA * 3 * sizeof(char));
		}
		
		system("cls");
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\PRESS ENTER\n\n\n\n\n\n\n\n\n\n\n");
		getchar();

		for(i = 0; i < ALTURA; ++i)
		{
			vet[i] = ' ';
		}

		vet[p] = (char)PERSONAGEM;

		mapa = init_mat();

		system("cls");

		mov_fase(vet, mapa);
		
		setbuf(stdin, NULL);
    		system("cls");
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\tGAME OVER!");
		printf("\n\n\t\t\t\t SCORE %d\n\n\n\n\n\n\n\n\n\n\n", score);
		getchar();

		if(score > jog.score && ind_j != -1)
		{
			jog.score = score;
		}
		
		system("cls");
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\tJOGAR NOVAMENTE? (s/n)\n\n\n\n\n\n\n\n\n\n\n");
		resp = getch();
		setbuf(stdin, NULL);
		
		for (i = 0; i < ALTURA; i++) {
			free(mapa[i]);
		}
		free(mapa);

	}while(resp == 's');
	
}
